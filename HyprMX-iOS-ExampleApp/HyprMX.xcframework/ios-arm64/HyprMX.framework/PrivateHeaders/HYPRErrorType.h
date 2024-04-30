//
//  HYPRErrorType.h
//  HyprMX
//
//  Created on 3/1/12.
//  Copyright (c) 2012 HyprMX Mobile LLC. All rights reserved.
//

typedef enum {
    /**
     * Unspecified Error (Used in Unit Tests)
     * 0
     */
    HYPRErrorTypeUnspecified = 0,

    /**
     * VAST Errors  
     * 020 - 039
     */
    HYPRErrorTypeVASTPlayerError                   = 20,
    HYPRErrorTypeVASTParsingTagError               = 21,
    HYPRErrorTypeVASTDownloadingError              = 22,
    HYPRErrorTypeVASTCachingAssetError             = 23,
    HYPRErrorTypeVASTAssetDownloadError            = 24,
    HYPRErrorTypeVASTDownloadingTagError           = 25,
    HYPRErrorTypeVASTNoSuitableMediaError          = 26,
    HYPRErrorTypeVASTPrepareForPlaybackError       = 27,
    HYPRErrorTypeVASTRewardNotDeliveredError       = 28,
    
    // VAST Errors: Player Catalog Frame Errors
    HYPRErrorTypeVASTPlayerDidNotReceiveThankYouURL     = 30,
    HYPRErrorTypeVASTPlayerCatalogFrameError            = 31,
    
    // VAST Errors: Parser Internal Errors
    HYPRErrorTypeNSXMLParseError                        = 32,
    HYPRErrorTypeNSXMLValidationError                   = 33,
    HYPRErrorTypeParsingStatusFailedWithNoData          = 34,
    HYPRErrorTypeParsingWrapperLoopDetected             = 35,
    
    // ERROR CODE 36 DEPRECATED

    /**
     * General Web View Errors
     * 040-059
     */
    HYPRErrorTypeWebViewEmptyJavaScriptError = 40,
    HYPRErrorTypeWebViewJavaScriptPOSTError = 41,
    HYPRErrorTypeGeneralOfferPageReadyError = 42,
    
    // HYPROfferViewController App Store Errors
    HYPRErrorTypeAppStoreLoadingError       = 43,
    
    // HYPROfferViewController Payout Errors
    HYPRErrorTypePayoutCompleteJavaScriptError = 44,
    
    // Post Offer Questions Error
    HYPRErrorTypePostOfferQuestionsNotSupported = 45,
    
    // Post Offer Questions Error
    HYPRErrorTypeWebViewCrash = 46,
    
    /**
     * Web Traffic Errors
     * 060-079
     */
    HYPRErrorTypeWebTrafficPageReadyError                 = 60,
    HYPRErrorTypeWebTrafficSessionTaskError               = 61,
    HYPRErrorTypeWebTrafficJSONContentsError              = 62,
    HYPRErrorTypeWebTrafficOfferValidationError           = 63,
    HYPRErrorTypeWebTrafficReadyStateJavaScriptError      = 64,
    HYPRErrorTypeWebTrafficJSONContentValidationError     = 65,
    HYPRErrorTypeWebTrafficPageLoadScriptsJavaScriptError = 66,
    HYPRErrorTypeWebTrafficJavaScriptPOSTError            = 67,
    
    /**
     * HYPRDownloadJob Errors
     * 080-099
     */
    HYPRErrorTypeDownloadJobCopyFileError                   = 80,
    HYPRErrorTypeDownloadJobNSDataCopyError                 = 81,
    HYPRErrorTypeDownloadJobAssetValidationError            = 82,
    HYPRErrorTypeDownloadJobNotEnoughDiskSpaceError         = 83,
    HYPRErrorTypeDownloadJobNSURLSessionTaskFailureDelegate = 84,
    HYPRErrorTypeDownloadJobReceived404ResponseError        = 85,

    /**
     * Offers Available Errors
     * 100-119
     */
    HYPRErrorTypeOfferAvailableFailed                   = 100,
    
    /**
     * Image Errors
     * 120-139
     */
    HYPRErrorTypeImageLoadingError   = 120,
    HYPRErrorTypeImageParameterError = 121,
    
    /**
     * HYPROfferViewController Audio Session Errors
     * 140-159
     */
    HYPRErrorTypeAudioSessionFailureToSetCategory                  = 140,
    HYPRErrorTypeAudioSessionFailureToSetSettings                  = 141,
    HYPRErrorTypeAudioSessionFailureToSetPlaybackToActiveSession   = 142,
    HYPRErrorTypeAudioSessionFailureToSetPlaybackToOriginalSession = 143,
    
    /**
     * NSURL Error
     * 160-179
     */
    HYPRErrorTypeStringToNSURLConversionError = 160,
    
    /**
     * HYPRObjectMappingQueue Errors
     * 180-199
     */
    HYPRErrorTypeObjectMappingQueueNilJSONObject = 180,
    HYPRErrorTypeObjectMappingQueueJSONParsingFailure = 181,
    
    /**
     * HYPRMRAIDSupport Errors
     * 200-219
     */
    HYPRErrorTypeNonStringPhotosUsageDescriptionPlistValue = 200,
    HYPRErrorTypeEmptyStringPhotosUsageDescriptionPlistValue = 201,
    HYPRErrorTypeNonStringCalendarsUsageDescriptionPlistValue = 202,
    HYPRErrorTypeEmptyStringCalendarsUsageDescriptionPlistValue = 203,
    
    /**
     * Upgrade Errors
     * 220-239
     */
    HYPRErrorTypeJavaScriptUpgradeError = 220,
    HYPRErrorTypeJavaScriptImproperRollbackAgainstBase = 221,
    HYPRErrorTypeJavaScriptImproperRollbackDuringUpgrade = 222,
    HYPRErrorTypeJavaScriptUpgradeLoopError = 223,
    HYPRErrorTypeJavaScriptUpgradeFetchError = 224,
    HYPRErrorTypeJavaScriptUpgradeToSameVersionError = 225,
    HYPRErrorTypeJavaScriptUpgradeToEmptyURL = 226,

    /**
     * Core Javascript Exception Errors
     * 240-249
     */
    HYPRErrorTypeJavaScriptGeneralException = 227,
} HYPRErrorType;

#pragma mark - Error Event Collections -

typedef enum {
    HYPRErrorCollectionTypeOffersAvailable = 0,
    HYPRErrorCollectionTypeVASTFailure,
    HYPRErrorCollectionTypeJavaScriptEvaluation,
    HYPRErrorCollectionTypeNetworkDownloadFailure,
    HYPRErrorCollectionTypeCatalogFrame,
    HYPRErrorCollectionTypeAudioSessionFailure,
    HYPRErrorCollectionTypeVASTParser,
    HYPRErrorCollectionTypeImageProcessingFailure,
    HYPRErrorCollectionTypeInvalidURL,
    HYPRErrorCollectionTypeAppStoreLoadFailure,
    HYPRAnalyticsErrorClientErrorCapture,
    HYPRErrorCollectionTypePostOfferQuestionsNotSupported,
    HYPRErrorCollectionTypeWebTrafficError,
    HYPRErrorCollectionTypeObjectMappingQueueError,
    HYPRErrorCollectionTypeGeneralOfferTypeError,
    HYPRErrorCollectionTypeHostApplicationMisconfigured,
    HYPRErrorCollectionTypeJavaScriptCoreUpgrade
} HYPRErrorCollectionType;
