//
//  HYPRController.h
//  HyprMX-SDK
//
//  Created by Sean Reinhardt on 2/22/18.
//  Copyright © 2018 HyprMX Mobile LLC. All rights reserved.
//
#import "HYPRConstants.h"
#import "HYPRJSContext.h"
#import <HyprMX/HyprMX-Swift.h>

@class HYPRImageCache, OMIDJungroupPartner;

NS_ASSUME_NONNULL_BEGIN
HYPR_CLASS_AVAILABLE_IOS
@protocol HYPRControllerProtocol <NSObject, NSURLSessionDelegate>

@property (nonatomic, strong, readonly) NSURLSession *dataRequestSession;
- (nonnull HYPRImageCache *)sharedImageCache;

@end
NS_ASSUME_NONNULL_END

API_AVAILABLE(ios(13.4))
typedef NSObject<HYPRControllerProtocol> HYPRController;

