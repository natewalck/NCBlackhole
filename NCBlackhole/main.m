//
//  main.m
//  NCBlackhole
//
//  Created by Jerry Marino on 3/5/14.
//  Copyright (c) 2014 Jerry Marino. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>
#import "mach_inject_bundle/mach_inject_bundle.h"

int main(int argc, const char * argv[])
{
    @autoreleasepool {
        NSArray *apps = [NSRunningApplication runningApplicationsWithBundleIdentifier:@"com.apple.notificationcenterui"];
        if ([apps count] < 1) {
            NSLog(@"Notification center process not found");
            return -1;
        }
        
        pid_t pid = [[apps objectAtIndex:0] processIdentifier];
        
        NSString *bundlePath = [[NSBundle mainBundle] pathForResource:@"NCAdditions" ofType:@"bundle"];
        
        NSLog(@"Injecting bundle at path: %@", bundlePath);
        NSLog(@"PID: %d", pid);
        
        mach_error_t err;
        err = mach_inject_bundle_pid([bundlePath fileSystemRepresentation], pid);
        if (err == err_none) {
            NSLog(@"Inject successful!");
        } else {
            NSLog(@"Inject error: %d", err);
        }
    }
    return 0;
}
