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

@implementation NCAdditions

+ (void)load {
    [self patchNCNotificationCenterController];
    [self createLog];
    [self presentInstalledNotification];
    
    NSLog(@"NCAdditions loaded");
}

+ (void)createLog
{
    const char* logFilePath = [[NSHomeDirectory() stringByAppendingPathComponent:@"NCBlackhole.log"] UTF8String];
    freopen(logFilePath, "a", stdout);
    freopen(logFilePath, "a", stderr);
}

+ (void)presentInstalledNotification {
    NSUserNotification *userNotification = [[NSUserNotification alloc] init];
    userNotification.title = @"NCBlackhole installed";
    [[NSUserNotificationCenter defaultUserNotificationCenter] scheduleNotification:userNotification];
}

#pragma mark - Overrides

BOOL NCAppInfo_isBlackHoled(NCAppInfo *_self)
{
    return [_self->_bundleIdentifier isEqualToString:@"com.apple.appstore"];
}

void NCAppInfo_log(NCAppInfo *_self) {
    NSLog(@"%@", _self->_name);
    NSLog(@"%@", _self->_notifications);
    NSLog(@"%llu", _self->_notificationsToShow);
    NSLog(@"%d", _self->_needsToFetchData);
    NSLog(@"%d", _self->_type);
    NSLog(@"%d", _self->_showInNotificationCenter);
}

+ (void)patchNCNotificationCenterController
{
	Method originalMeth = class_getInstanceMethod(NSClassFromString(@"NCNotificationCenterController"), @selector(notificationCenter:presentNotification:forApplication:withUnpresentedCount:));

	IMP originalImp = method_getImplementation(originalMeth);
    method_setImplementation(originalMeth,
                             (IMP)imp_implementationWithBlock(^(id _self, id notificationCenter, id userNotification, NCAppInfo *application, id unpresentedCount){
        //TODO : remove logging
        NSLog(@"-[NCNotificationCenterController notificationCenter:presentNotification:forApplication:withUnpresentedCount:]");
        
        NSLog(@"%@", _self);
        NSLog(@"%@", notificationCenter);
        NSLog(@"%@", userNotification);
        NSLog(@"%@", application);
        NSLog(@"%@", unpresentedCount);
        
        NCAppInfo_log(application);
        
        if (NCAppInfo_isBlackHoled(application)) {
            NSLog(@"Did blackhole notification");
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

@end

