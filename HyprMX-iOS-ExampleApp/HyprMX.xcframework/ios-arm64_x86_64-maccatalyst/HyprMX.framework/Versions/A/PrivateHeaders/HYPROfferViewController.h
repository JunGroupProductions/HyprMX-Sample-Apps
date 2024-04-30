//
//  HYPROfferViewController.h
//  HyprMX-Framework
//
//  Created by Jeremy Ellison on 7/15/14.
//  Copyright (c) 2014 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <StoreKit/StoreKit.h>
#import <SafariServices/SafariServices.h>

#import "HYPROffer.h"
#import "HYPRAlertView.h"
#import "HYPRImageCache.h"
#import "HYPRPresentationResultsDelegate.h"
#import "HYPRError.h"
#import "HYPRErrorType.h"
#import "HYPRWebView.h"
#import "HYPRConstants.h"
#import "HYPROrientation.h"
#import "HYPRWebViewPresenter.h"
#import "HYPRFullscreenViewModelConnector.h"
#import "HYPRPreloadController.h"
#import "HYPRPresentationAdapterProtocol.h"

#if OMSDK_SUPPORTED_ARCHITECTURE == 1
@class OMIDJungroupPartner;
#endif

extern NSString * const kHYPROrientationPortrait;
extern NSString * const kHYPROrientationLandscape;
extern NSString * const kHYPRPlayerTrackerReady;
extern NSString * const kHYPRConsoleBuffer;
extern NSString * const kHYPRGenericErrorMessage;
extern NSString * const kHYPRPlayerTrackerReady;
extern NSString * const kHYPRPlayerTrackerTrueResponse;
extern NSString * const kHYPRPlayerTrackerCompleteScript;
extern NSString * const kHYPRPlayerInformNavigationDidCloseScript;

@class HYPRDisplayRequest, HYPRError, HYPROpenMeasurementController, HYPRVideoPlayerManager, HYPRTrackingPixels, HYPRWeakNativeProxy;

HYPR_CLASS_AVAILABLE_IOS
@interface HYPROfferViewController : UIViewController
<SFSafariViewControllerDelegate> {
    
@protected
    HYPRWebView *_webView;
}

@property (nonatomic, readonly) HYPRWebView *webView;
@property (nonatomic, strong) HYPROffer *offer;
@property (nonatomic, strong) UIBarButtonItem *closeButtonItem;

@property (weak, nonatomic) UIStackView *stackView;
@property (atomic, readonly) BOOL isAdComplete;
@property (nonatomic, weak) HYPRAlertView *closeDialog;
@property (nonatomic, strong) HYPRAlertView *alertView;
@property (atomic, copy) void (^navigationCompletion)(void);
@property (nonatomic, assign) BOOL didOfferFinish;
@property (nonatomic, strong) HYPROpenMeasurementController *omController;
@property (strong, nonatomic) HYPROrientation *orientation;
@property (strong, nonatomic) NSString *viewModelId;
@property (weak, nonatomic) JSContext<HYPRJSContextProtocol> *context;
@property (strong, nonatomic) HYPRFullscreenViewModelConnector *viewModel;
@property (strong, nonatomic) HYPRPreloadController *preloadController;

// MRAID Support Properties
@property (nonatomic, assign) BOOL isRotationAllowed;
@property (nonatomic, strong, readonly) UIActivityIndicatorView *downloadActivityIndicator;
@property (nonatomic, strong) NSMutableArray<NSLayoutConstraint*>* downloadIndicatorConstraints;

// Video Support Properties
@property (nonatomic, strong) HYPRVideoPlayerManager *videoManager;
@property (nonatomic, strong, readonly) NSArray *verificationResources;
@property (nonatomic, assign) NSInteger skipOffset;
@property (nonatomic, strong) HYPRTrackingPixels *trackingPixels;
@property (nonatomic, strong) NSMutableDictionary<NSNumber *, NSArray<NSString *> *> *progressTrackingEvents;

#if OMSDK_SUPPORTED_ARCHITECTURE == 1
@property (nonatomic, strong) OMIDJungroupPartner *partner;
#endif

-(id<HYPRWebViewDelegate>)webViewPresenter;
@property (nonatomic, strong) HYPRPresentationAdapterDelegateImplementation *presentationDelegate;

// Delegate to notify of presentation status
@property (nonatomic, weak) NSObject <HYPRPresentationResultsDelegate>* presentationStatusDelegate;

/**
 * Designated Initializer used by HYPROfferWebViewController and HYPROfferWebTrafficViewController
 */
- (instancetype)initWithOffer:(HYPROffer *)offer
               statusDelegate:(NSObject<HYPRPresentationResultsDelegate> *)statusDelegate
                  orientation:(HYPROrientation *)orientation
                  viewModelId:(NSString *)viewModelId
                      context:(JSContext<HYPRJSContextProtocol> *)context
            preloadController:(HYPRPreloadController *)preloadController;

/** 
 * Call offer complete methods and offerViewControllerDidComplete 
 **/
- (void)offerDidFinish;


/**
 * Sets a block to release the webView after the required retain time for OpenMeasurement
 * Returns the window that the webView is attached to during the release timeframe.
 **/
- (UIWindow *)cleanupWebView;

/** 
 * Set the navigation bar buttons 
 **/
- (void)prepareNavigationBar;

/**
 * Selector attached to the Navigation bar and VAST Video control close buttons.
 * Produces an alert box warning that the user will not be rewarded when the offer is not marked as complete.
 **/
- (void)onCloseBarButtonItemPressed:(id)sender;

/**
 *  [PLAYER-5402] ~ https://jira.jungroup.com/browse/PLAYER-5402
 *  [PLAYER-6658] ~ https://jira.jungroup.com/browse/PLAYER-6658
 *
 *  This helper method will add a Close button to the UINavigationBar on initialization only when
 *  directed by the server.
 */
- (void)setOfferControllerIsClosable:(BOOL)isClosable;

/**
 *  Registers controller for UIApplicationDidBecomeActiveNotification and UIApplicationDidEnterBackgroundNotification
 */
- (void)registerForBackgroundNotifications;

/**
 *  Unregisters controller for UIApplicationDidBecomeActiveNotification and UIApplicationDidEnterBackgroundNotification
 */
- (void)unregisterForBackgroundNotifications;

/**
 *  Default selector for UIApplicationDidBecomeActiveNotification - should be overriden when used
 */
- (void)appDidBecomeActive:(NSNotification *)notification;

/**
 *  Default selector for UIApplicationWillEnterForegroundNotification - should be overriden when used
 */
- (void)appWillEnterForeground:(NSNotification *)notification;

/**
 *  Default selector for UIApplicationDidEnterBackgroundNotification - should be overriden when used
 */
- (void)appDidBackground:(NSNotification *)notification;

/**
 *  Default selector for UIApplicationWillResignActiveNotification - should be overriden when used
 */
- (void)appWillResignActive:(NSNotification *)notification;

- (void)finishAndClearOmSession;

/**
 * Checks if object is a UIWindowScene and is equal to the view's scene
 * Returns NO when called below iOS 13
 */
- (BOOL)notificationAffectsAdPresentation:(NSNotification *)notification;

// WebView config with mode string to send to shared_js to determine limitNavigation status
-(NSString *)webViewDisplayMode;

- (NSArray<UIView *>*)adViews;

-(void)presentFullscreenSharingForURL:(NSString *)urlString;
- (void)createOMSessionForWebViewWithInfo:(NSString *)info;
- (void)endDownloadActivityIndicator;
- (void)displayErrorAlertWithTitle:(NSString *)title message:(NSString *)message fatalAlert:(BOOL)isFatal;
-(void)enableBackButton:(BOOL)isEnabled;
-(void)enableForwardButton:(BOOL)isEnabled;
- (HYPRWebView *)startWebView;
-(HYPRWeakNativeProxy *)proxyForController;

@end
