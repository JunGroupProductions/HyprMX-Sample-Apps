//
//  HYPRFullscreenNativeDelegate.h
//  HyprMX-Framework
//
#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "HYPRNativeDelegate.h"

@protocol HYPRFullscreenNativeDelegate <JSExport,
    HYPRActivityEventDelegate,
    HYPRLaunchBrowserDelegate,
    HYPRAppJSEventDelegate,
    HYPRMraidNativeDelegate,
    HYPROpenMeasurementNativeDelegate,
    HYPRStoreKitEventDelegate
>

@required
- (void)closeAdExperience;
- (void)showErrorDialog:(NSString *)message;
- (void)dismissOfferCancellationDialog;
- (void)setClosable:(BOOL)closeable;
- (void)reportPowerState;
- (void)setBackButtonEnabled:(BOOL)enabled;
- (void)showCancelDialog:(NSString *)message :(NSString *)continueButton :(NSString *)exitButton;
@end
