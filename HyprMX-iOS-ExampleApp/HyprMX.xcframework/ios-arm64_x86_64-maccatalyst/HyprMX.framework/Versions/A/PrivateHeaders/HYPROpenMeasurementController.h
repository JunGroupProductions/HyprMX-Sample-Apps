//
//  HYPROpenMeasurementController.h
//  HyprMX-SDK
//
//  Created by Ben Balcomb on 9/5/18.
//  Copyright © 2018 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "HYPRConstants.h"
#if OMSDK_SUPPORTED_ARCHITECTURE == 1
#import <OMSDK_Jungroup/OMIDImports.h>
#endif
@class WKWebView, OMIDJungroupAdSession, OMIDJungroupAdEvents, OMIDJungroupMediaEvents, OMIDJungroupVerificationScriptResource;

HYPR_CLASS_AVAILABLE_IOS

@interface HYPROpenMeasurementController : NSObject
#if OMSDK_SUPPORTED_ARCHITECTURE == 1
@property (strong, nonatomic) OMIDJungroupAdSession *adSession;
@property (strong, nonatomic) OMIDJungroupMediaEvents *mediaEvents;
@property (strong, nonatomic) OMIDJungroupAdEvents *adEvents;

- (instancetype)initWithImpressionOwner:(OMIDOwner)impressionOwner
                       videoEventsOwner:(OMIDOwner)videoEventsOwner
                             mainAdView:(UIView *)mainAdView
                              resources:(NSArray*)resources
                           obstructions:(NSDictionary<NSString *,UIView*>*)obstructions
                             customData:(NSString*)customData
                                partner:(OMIDJungroupPartner*)partner;

- (void)startAdSession;
- (void)finish;

+ (NSNumber*)defaultWebViewRetainTime;
#endif
@end
