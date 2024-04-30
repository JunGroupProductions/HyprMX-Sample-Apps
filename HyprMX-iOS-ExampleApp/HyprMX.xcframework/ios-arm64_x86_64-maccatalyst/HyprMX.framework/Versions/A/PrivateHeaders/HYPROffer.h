//
//  HYPROffer.h
//  HyprMX
//
//  Created on 2/29/12.
//  Copyright (c) 2012 HyprMX Mobile LLC. All rights reserved.
//
#import <HyprMX/HyprMX.h>
#import <HyprMX/HYPRJSContext.h>

@class HYPRImage, HYPRCancellationDialog, HYPRFooter, HYPROfferNavBar;

/**  Models a HyprMX Mobile Offer  */
@interface HYPROffer : NSObject

/**  Initializes HYPROffer with JSON string  */
- (instancetype)initWithJson:(NSString *)json;

/**  Models a HyprMX Mobile Offer  */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

+ (void)offerWithJson:(NSString *)json context:(JSContext<HYPRJSContextProtocol> *)context completion:(void (^)(HYPROffer *))completion;

/** Identifier for the offer */
@property (nonatomic, strong) NSString *identifier;

/** Title of the offer to be displayed to the user  */
@property (nonatomic, copy) NSString *title;

/** Description of the offer to be displayed to the user  */
@property (nonatomic, copy) NSString *offerDescription;

/** Reward token. This is used to identify the reward when we open the offer view. */
@property (nonatomic, retain) NSString *rewardToken;

/** Type of offer; 'mraid', 'web_traffic' map to unique ViewControllers, all others map to HYPROfferWebViewController */
@property (nonatomic, copy) NSString *offerType;

/** String uniquely identifying this offer. Provided by the SDK user and returned when the offer is completed.  */
@property (nonatomic, strong) NSString *hyprTransactionID;

/** The cancellation dialog */
@property (nonatomic, strong) HYPRCancellationDialog *cancellationDialog;

/** Close button visibility property for WebView */
@property (nonatomic) BOOL isCloseButtonShown;

/** Should the audio session be changed to disable the mute switch */
@property (nonatomic) BOOL isMuteSwitchIgnored;

/** The Proscenium property that will determine if the Proscenium view should be displayed or not. */
@property (nonatomic) BOOL isProsceniumSkipped;

/** The Thank You Screen property that will determine if the Thank You view should be displayed or not. */
@property (nonatomic) BOOL skipThankYouScreen;

/** Integer for Page Load Timeout */
@property (nonatomic) NSInteger offerInitiationTimeout;

/** Interface orientation mask required for ad */
@property (nonatomic) UIInterfaceOrientationMask allowedOrientation;

/** Base URL for offer to send catalog frame post to - can be nil */
@property (nonatomic, strong) NSString *baseCatalogFrameURLString;

/** Bool set to YES if the server requests to open sharing links in SVC for this offer */
@property (nonatomic, assign) BOOL diableSVCForLearnMore;

/** Base URL for offer to preload MRAID offer from - can be nil (falls back to catalog frame url) */
@property (nonatomic, strong) NSString *preloadPlayerURL;

/** A cached webview will be replaced after so many seconds */
@property (nonatomic) NSInteger webviewTimeout;

/** A cached webview is only valid if it fires page ready after so many seconds */
@property (nonatomic) NSInteger preloadedMraidPageReadyTimeout;

/**  to be set on web traffic web view  */
@property (nonatomic, copy) NSString *userAgent;

/** The configuration for a web traffic footer */
@property (nonatomic, strong) HYPRFooter *footer;

/** The configuration for a web traffic header */
@property (nonatomic, strong) HYPROfferNavBar *navBar;

/**  Time to retain webview on finish  */
@property (nonatomic, retain) NSNumber *webviewReleaseSeconds;

/** Bool set to YES if the Webtraffic controller must display the status bar */
@property (nonatomic, assign) BOOL forceStatusBarDisplay;

/**  returns YES if offer is MRAID  */
- (BOOL)isMraidOffer;
@end
