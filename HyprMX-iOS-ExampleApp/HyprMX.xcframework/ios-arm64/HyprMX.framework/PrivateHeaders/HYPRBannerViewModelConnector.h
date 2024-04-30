//
//  HYPRBannerViewModelConnector.h
//  HyprMX
//
//  Created by Sean Reinhardt on 8/24/22.
//  Copyright © 2022 HyprMX Mobile LLC. All rights reserved.
//

#import <HyprMX/HYPRJSContext.h>
#import <HyprMX/HYPRViewModelConnector.h>
NS_ASSUME_NONNULL_BEGIN
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRBannerViewModelConnector : HYPRViewModelConnector  <
HYPRBannerViewModelInterface>
- (instancetype)initWithContext:(JSContext<HYPRJSContextProtocol> *)context
                  placementName:(NSString *)placementName
                          queue:(NSOperationQueue *)queue;
- (NSString *)bindViewModel:(nullable NSObject *)nativeObject hash:(NSUInteger)hash;
@end

NS_ASSUME_NONNULL_END
