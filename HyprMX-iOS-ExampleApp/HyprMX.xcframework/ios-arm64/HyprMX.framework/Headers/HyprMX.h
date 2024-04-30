//
//  HyprMX.h
//  HyprMX
//
#import <UIKit/UIKit.h>
//! Project version number for HyprMX_SDK.
FOUNDATION_EXPORT double HyprMXVersionNumber;

//! Project version string for HyprMX_SDK.
FOUNDATION_EXPORT const unsigned char HyprMXVersionString[];

#import <Foundation/Foundation.h>

extern CGSize const kHyprMXAdSizeShort;
extern CGSize const kHyprMXAdSizeBanner;
extern CGSize const kHyprMXAdSizeMediumRectangle;
extern CGSize const kHyprMXAdSizeLeaderBoard;
extern CGSize const kHyprMXAdSizeSkyScraper;

typedef enum {
    INVALID = 0,
    INTERSTITIAL,
    REWARDED,
    BANNER
} HyprMXPlacementType;

typedef enum {
    NO_FILL = 0,
    DISPLAY_ERROR,
    PLACEMENT_DOES_NOT_EXIST,
    AD_SIZE_NOT_SET,
    PLACEMENT_NAME_NOT_SET,
    SDK_NOT_INITIALIZED
} HyprMXError;

@protocol HyprMXAudioChangeDelegate
- (void)adAudioWillStart;
- (void)adAudioDidEnd;
@end

typedef enum {
    HYPRLogLevelError = 0, // Messages at this level get logged all the time.
    HYPRLogLevelVerbose,   //                               ... only when verbose logging is turned on.
    HYPRLogLevelDebug      //                               ... in debug mode.
} HYPRLogLevel;

typedef enum {
    NOT_INITIALIZED = 0,    // HyprMX has not been initialized yet.
    INITIALIZING,           // Initialiation is in progress.
    INITIALIZATION_FAILED,  // Initialization failed.
    INITIALIZATION_COMPLETE // Initialization completed successfully.
} HyprMXState;

typedef enum {
    CONSENT_STATUS_UNKNOWN = 0,  // consent has not been collected from the user
    CONSENT_GIVEN,               // user has granted consent
    CONSENT_DECLINED             // user has declined
} HyprConsentStatus;

extern NSString * _Nonnull const HyprMXMediationProviderAdmob;
extern NSString * _Nonnull const HyprMXMediationProviderApplovinMax;
extern NSString * _Nonnull const HyprMXMediationProviderFyber;
extern NSString * _Nonnull const HyprMXMediationProviderIronSource;
extern NSString * _Nonnull const HyprMXMediationProviderMopub;
extern NSString * _Nonnull const HyprMXMediationProviderUnity;
extern NSString * _Nonnull const HyprMXMediationProviderChartboost;
