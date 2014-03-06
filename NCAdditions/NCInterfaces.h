//
//  NCBlackhole.h
//  NCBlackhole
//
//  Created by Jerry Marino on 3/2/14.
//  Copyright (c) 2014 Jerry Marino. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

@class NCNotificationCenter;
@class NCWindowLayoutController;

@interface NCNotificationCenterController : NSObject <NSApplicationDelegate>
{
    NSStatusItem *_statusItem;
    NCNotificationCenter *_center;
    id _eventShieldWindow;
    NSMutableArray *_alertProviders;
    BOOL _newMessages;
    BOOL _isAnimating;
    BOOL _mouseDownWhenOpen;
    BOOL _bannersAndAlertsDisabled;
    BOOL _ncDisabled;
    BOOL _processUnbackgrounded;
    BOOL _DEBUG_POPOUT_WINDOW;
    BOOL _DEBUG_SLIDE_WINDOW;
    BOOL _DEBUG_LOCK_SCREEN;
    BOOL _DEBUG_SHOW_SETTINGS_WINDOW;
    double _statusMouseDownTime;
    id _notificationTableController;
    NCWindowLayoutController *_notificationWindowController;
    id _statusButtonCell;
    unsigned int _layoutDisplay;
    unsigned long long _notificationsSpace;
    struct CGRect _screenFrame;
    struct CGRect _visibleFrame;
    id _dndController;
    NSObject *_reconfig_timer;
    NSObject *_state_updater_timer;
    _Bool _displaySleeping;
    _Bool _lockuiShowing;
    _Bool _screenLocked;
    _Bool _shieldUp;
    _Bool _settingDND;
    BOOL _shown;
    BOOL _showingShareKitWindow;
    NSMenu *_optionsMenu;
}

@property BOOL showingShareKitWindow; // @synthesize showingShareKitWindow=_showingShareKitWindow;
//@property(readonly) NCDNDController *dndController; // @synthesize dndController=_dndController;
//@property(readonly) NCNotificationTableController *notificationTableController; // @synthesize notificationTableController=_notificationTableController;
//@property(readonly) NCWindowLayoutController *notificationWindowController; // @synthesize notificationWindowController=_notificationWindowController;
@property(readonly) BOOL shown; // @synthesize shown=_shown;
@property NSMenu *optionsMenu; // @synthesize optionsMenu=_optionsMenu;
//- (void).cxx_destruct;
- (void)screenParametersChanged;
- (void)screenParemetersChangedProcessNow;
- (BOOL)eventWindow:(id)arg1 keyDownWithEvent:(id)arg2;
- (void)debugWindowScreenlockModeChanged:(id)arg1;
- (void)debugWindowDoNotDisturbModeChanged:(id)arg1;
- (void)windowLayout:(id)arg1 showNotificationInCenter:(id)arg2;
- (void)notificationCenter:(id)arg1 progressRemoved:(id)arg2;
- (void)notificationCenter:(id)arg1 progressAdded:(id)arg2;
- (void)notificationCenter:(id)arg1 alertChanged:(id)arg2 forApplication:(id)arg3;
- (void)notificationCenter:(id)arg1 restoreSnoozedAlert:(id)arg2 forApplication:(id)arg3;
- (void)notificationCenter:(id)arg1 clearBannersForApplication:(id)arg2;
- (void)notificationCenter:(id)arg1 removeDisplayedNotification:(id)arg2 forApplication:(id)arg3;
- (void)notificationCenter:(id)arg1 applicationRemoved:(id)arg2;
- (void)notificationCenter:(id)arg1 restoreAlerts:(id)arg2 forApplication:(id)arg3;
- (void)notificationCenter:(id)arg1 presentNotification:(id)arg2 forApplication:(id)arg3 withUnpresentedCount:(unsigned long long)arg4;
- (void)notificationCenter:(id)arg1 applicationUpdated:(id)arg2;
- (void)notificationCenter:(id)arg1 hasUnreadNotifications:(BOOL)arg2;
- (void)notificationCenterDataReloaded:(id)arg1;
- (void)notificationCenterConnectionError:(id)arg1;
- (void)notificationCenter:(id)arg1 applicationOrderChanged:(id)arg2;
- (void)closeCompletedFluid:(BOOL)arg1;
- (void)closeStarted:(BOOL)arg1 fluid:(BOOL)arg2;
- (void)openCompletedFluid:(BOOL)arg1;
- (void)openStarted:(BOOL)arg1 fluid:(BOOL)arg2 fullscreen:(BOOL)arg3 display:(unsigned int)arg4;
- (void)_debugDump:(id)arg1;
- (void)_systemEventThatShouldCauseNotificationCenterToClose:(id)arg1;
- (void)_showDNDButton:(id)arg1;
- (void)_displaySleep;
- (void)_displayLit;
- (void)_registerForLockscreenNotifications;
- (void)_updateStateNow;
- (void)_updateState;
- (void)_updateDisplayState;
- (void)_createEventShieldWindow;
- (void)statusItemClicked:(id)arg1;
- (void)showPreferences:(id)arg1;
- (void)quit:(id)arg1;
- (void)alertProvider:(id)arg1 removeAlert:(id)arg2;
- (void)alertProvider:(id)arg1 showAlert:(id)arg2 animation:(int)arg3 restore:(_Bool)arg4;
- (void)registerAlertConnection:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)_updateDoNotDisurbViews;
@property(readonly) BOOL doNotDisturbActive;
- (void)requestClose;
- (void)requestOpenWithReason:(const char *)arg1 display:(unsigned int)arg2;
- (void)requestOpenWithReason:(const char *)arg1;
- (void)applicationDidFinishLaunching:(id)arg1;

@end

@interface NCWindowLayoutController : NSObject
{
    NSMutableArray *_placeholderAlerts;
    id _keyAlert;
    id _replyAlert;
    NSHashTable *_notificationsInReplyThatShouldGoAway;
    NSMutableDictionary *_coalescedNotificationWindows;
    double _rightColumnConstraintConstant;
    BOOL _alertsDisabled;
    id _bannerWindow;
    NSHashTable *_allNotifications;
    NSMutableDictionary *_notificationsPerApplication;
    NSMutableArray *_pendingDarkWakeNotifications;
    double _screenLockedTime;
    double _screenLockDisplayTime;
    unsigned int _powerAssertionID;
    double _powerAssertionTime;
    double _bannerTime;
    double _lockscreenBannerTime;
    BOOL _centerOpen;
    BOOL _windowCanBecomeKey;
    int _lockscreenMode;
    id  _delegate;
    id _currentBanner;
}

@property(nonatomic) BOOL windowCanBecomeKey; // @synthesize windowCanBecomeKey=_windowCanBecomeKey;
@property(nonatomic) int lockscreenMode; // @synthesize lockscreenMode=_lockscreenMode;
@property(readonly, nonatomic) id currentBanner; // @synthesize currentBanner=_currentBanner;
@property(nonatomic) BOOL alertsDisabled; // @synthesize alertsDisabled=_alertsDisabled;
@property(nonatomic) BOOL centerOpen; // @synthesize centerOpen=_centerOpen;
//@property id <NCWindowLayoutDelegate> delegate; // @synthesize delegate=_delegate;
//- (void).cxx_destruct;
- (void)bannerShouldDismiss:(id)arg1;
- (void)bannerTextCleared:(id)arg1;
- (void)bannerTextTyped:(id)arg1;
- (void)bannerHidInlineReply:(id)arg1;
- (void)bannerShowedInlineReply:(id)arg1;
- (void)banner:(id)arg1 snoozedWithTimeInterval:(double)arg2;
- (void)bannerClose:(id)arg1;
- (void)bannerPerformActionAndDismiss:(id)arg1;
- (void)bannerContentClicked:(id)arg1;
- (void)notificationWindowDismissTimeElapsed:(id)arg1;
- (void)notificationWindow:(id)arg1 velocity:(double)arg2 draggedCompleted:(BOOL)arg3;
- (void)notificationWindow:(id)arg1 dragged:(id)arg2;
- (BOOL)notificationWindow:(id)arg1 dragStarted:(id)arg2;
- (void)notificationWindowSwipeEnded:(id)arg1 cancelled:(BOOL)arg2;
- (void)notificationWindowSwipeProgressed:(id)arg1 progress:(double)arg2;
- (BOOL)notificationWindowSwipeStarted:(id)arg1 rightToLeft:(BOOL)arg2 withEvent:(id)arg3;
- (BOOL)notificationWindowCanSwipe:(id)arg1 left:(BOOL)arg2;
- (void)bannerWindow:(id)arg1 windowsHiddenDueToOverflow:(id)arg2;
- (void)bannerWindowOrderedOut:(id)arg1;
- (_Bool)bannerWindowCanBecomeKey:(id)arg1;
- (void)_purgeStalePlaceholders;
- (void)_animateAlertOff:(id)arg1 animation:(int)arg2;
- (void)_removeNotification:(id)arg1 forApplication:(id)arg2;
- (void)_removeNotificationWindow:(id)arg1;
- (void)_addNotificationWindow:(id)arg1;
- (void)_addBannerNotificationByCoalescing:(id)arg1;
- (id)_matchExistingDisplayedBanner:(id)arg1;
- (id)_matchExistingBanner:(id)arg1;
- (void)_closeBanner:(id)arg1;
- (void)_clearBannerAssertion;
- (void)_refreshPowerAssertion;
- (double)_displayTimeForModel:(id)arg1;
- (BOOL)_shouldTakePowerAssertion;
- (void)debugDump:(id)arg1;
- (void)removePlaceholderAlert:(id)arg1;
- (void)addPlaceholderAlert:(id)arg1 restore:(_Bool)arg2 animation:(int)arg3;
- (BOOL)switchKeyNotification:(BOOL)arg1;
- (BOOL)canSwitchKeyNotifications;
- (void)layoutWindowForScreenRect:(struct CGRect)arg1 visibleRect:(struct CGRect)arg2;
- (void)updateAlert:(id)arg1 forApplication:(id)arg2;
- (void)removeBannersForApplication:(id)arg1;
- (void)removeAllDisplayedNotificationsForApplication:(id)arg1;
- (void)removeDisplayedNotification:(id)arg1 forApplication:(id)arg2;
- (void)restoreDisplayedNotifications:(id)arg1 forApplication:(id)arg2;
- (void)_coalesceLockScreenWindows:(id)arg1 hideForLockscreen:(_Bool)arg2;
- (void)_addNotificationOutOfLockscreen:(id)arg1 display:(_Bool)arg2 animation:(int)arg3;
- (id)_windowToAddBannerBelow:(id)arg1;
- (void)_addNotificationInLockscreen:(id)arg1 display:(_Bool)arg2 animation:(int)arg3;
- (void)_addNotificationWindow:(id)arg1 withAnimation:(int)arg2;
- (_Bool)_notificationShouldBeDisplayedInCurrentState:(id)arg1 displayTime:(double)arg2;
- (void)displayNotification:(id)arg1 forApplication:(id)arg2 withUnpresentedCount:(unsigned long long)arg3;
@property(readonly, nonatomic) NSMutableArray *visibleWindows;
- (id)sortedWindows;
- (BOOL)hasVisibleWindows;
@property(readonly, nonatomic) long long windowLevel;
@property(readonly) NSWindow *window;
- (void)dealloc;
- (id)initWithScreenFrame:(struct CGRect)arg1 andVisibleFrame:(struct CGRect)arg2 spaces:(id)arg3;

@end
@interface NCAppInfo : NSObject
{
    @public
    NSString *_name;
    NSImage *_image;
    NSString *_bundleIdentifier;
    int _type;
    BOOL _found;
    NSArray *_notifications;
    NSMutableArray *_unseenNotifications;
    unsigned long long _notificationsToShow;
    BOOL _showInNotificationCenter;
    BOOL _playSounds;
    BOOL _badgeIcons;
    BOOL _warnedAboutInvalidIdentity;
    BOOL _appDataLoadedStatically;
    BOOL _updatingNameImage;
    unsigned long long _alertStyle;
    NSObject *_delivered_timer;
    CDUnknownBlockType _delivered_block;
    double _sound_last_play_time;
    double _lastestNotificationTime;
    NSMutableDictionary *_soundDictionary;
    NSString *_lastKnownPath;
    BOOL _needsToFetchData;
    BOOL _hiddenFromLockscreen;
    BOOL _contentHidden;
    BOOL _contentHiddenFromLockscreen;
    id  _delegate;
}

+ (id)keyPathsForValuesAffectingPreferenceDictionary;
@property BOOL contentHiddenFromLockscreen; // @synthesize contentHiddenFromLockscreen=_contentHiddenFromLockscreen;
@property BOOL contentHidden; // @synthesize contentHidden=_contentHidden;
@property BOOL hiddenFromLockscreen; // @synthesize hiddenFromLockscreen=_hiddenFromLockscreen;
@property BOOL needsToFetchData; // @synthesize needsToFetchData=_needsToFetchData;
@property(readonly) int type; // @synthesize type=_type;
@property(readonly) BOOL found; // @synthesize found=_found;
@property double lastestNotificationTime; // @synthesize lastestNotificationTime=_lastestNotificationTime;
@property unsigned long long alertStyle; // @synthesize alertStyle=_alertStyle;
@property BOOL playSounds; // @synthesize playSounds=_playSounds;
@property BOOL badgeIcons; // @synthesize badgeIcons=_badgeIcons;
@property BOOL showInNotificationCenter; // @synthesize showInNotificationCenter=_showInNotificationCenter;
@property unsigned long long notificationsToShow; // @synthesize notificationsToShow=_notificationsToShow;
@property(retain, nonatomic) NSArray *notifications; // @synthesize notifications=_notifications;
@property(readonly) NSImage *image; // @synthesize image=_image;
@property(readonly) NSString *bundleIdentifier; // @synthesize bundleIdentifier=_bundleIdentifier;
@property(readonly) NSString *name; // @synthesize name=_name;
//@property __weak id <NCAppInfoDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain) NSString *lastKnownPath; // @synthesize lastKnownPath=_lastKnownPath;
//- (void).cxx_destruct;
- (void)messageTraceLogPreferences;
- (void)clearUnreadNotificationMatching:(id)arg1;
- (void)clearUnreadNotifications;
- (void)setDeliveredActionBlock:(CDUnknownBlockType)arg1;
- (void)playSound:(id)arg1;
//- (void)_playSoundWithBlock:(CDUnknownBlockType)arg1;
- (void)lookupInfoInBackgroundOnQueue:(id)arg1 fallbackPath:(id)arg2;
- (void)lookupInfoInBackgroundOnQueue:(id)arg1;
@property(copy) NSDictionary *preferenceDictionary;
@property(readonly) BOOL clearable;
@property(readonly) BOOL hasUnreadNotifications;
@property(readonly, nonatomic) NSString *unprefixedIdentifier;
@property(readonly) BOOL isWebApp;
@property(readonly) BOOL isSystemApp;
- (id)description;
- (BOOL)isEqual:(id)arg1;
- (unsigned long long)hash;
- (void)dealloc;
- (id)initSystemAppWithIdentifier:(id)arg1;
- (id)initWithBundleIdentifier:(id)arg1 lastKnownPath:(id)arg2 type:(int)arg3 name:(id)arg4 image:(id)arg5;
- (id)initWithBundleIdentifier:(id)arg1 lastKnownPath:(id)arg2 type:(int)arg3 loadInfoOnQueue:(id)arg4;

@end

