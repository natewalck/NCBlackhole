//
//  NCAdditions.m
//  NCBlackhole
//
//  Created by Jerry Marino on 3/3/14.
//  Copyright (c) 2014 Jerry Marino. All rights reserved.
//

#import "NCAdditions.h"
#import <objc/runtime.h>
#import "NCInterfaces.h"

#define NCDEBUG 0

@implementation NCAdditions

__attribute__((constructor)) static void NCAdditionsInitSharedInstance(void) {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [NCAdditions createLog];
        [NCAdditions patchNCNotificationCenterController];
        NSLog(@"NCBlackhole: loaded");
#if NCDEBUG
        [NCAdditions logLoadedMessage];
#endif
    });
}

+ (void)logLoadedMessage {
    double delayInSeconds = 2.0;
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [self logLoadedMessage];
        NSLog(@"NCBlackhole: is loaded");
    });
}

+ (void)createLog
{
    const char* logFilePath = [[NSHomeDirectory() stringByAppendingPathComponent:@"NCBlackhole.log"] UTF8String];
    freopen(logFilePath, "a", stdout);
    freopen(logFilePath, "a", stderr);
}

+ (void)patchNCNotificationCenterController
{
	Method originalMeth = class_getInstanceMethod(NSClassFromString(@"NCNotificationCenterController"), @selector(notificationCenter:presentNotification:forApplication:withUnpresentedCount:));

	IMP originalImp = method_getImplementation(originalMeth);
    method_setImplementation(originalMeth,
                             (IMP)imp_implementationWithBlock(^(id _self, id notificationCenter, id userNotification, NCAppInfo *application, id unpresentedCount){
#if NCDEBUG
        NSLog(@"-[NCNotificationCenterController(NCAdditions) notificationCenter:presentNotification:forApplication:withUnpresentedCount:]");
        NSLog(@"%@", _self);
        NSLog(@"%@", notificationCenter);
        NSLog(@"%@", userNotification);
        NSLog(@"%@", application);
        NSLog(@"%@", unpresentedCount);
#endif
        if ([self NCAppInfoIsBlackHoled:application]) {
            NSLog(@"NCBlackhole: Did blackhole notification %@", userNotification);
            return;
        }
        
        originalImp(_self,
                     @selector(notificationCenter:presentNotification:forApplication:withUnpresentedCount:),
                     notificationCenter,
                     userNotification,
                     application,
                     unpresentedCount
                     );
    }));
}

+ (BOOL)NCAppInfoIsBlackHoled:(NCAppInfo *)appInfo
{
    return [[appInfo valueForKey:@"_bundleIdentifier"] isEqualToString:@"com.apple.appstore"];
}

@end

