//
//  HYPRFullscreenViewModelConnector.h
//  HyprMX
//
//  Created by Sean Reinhardt on 8/24/22.
//  Copyright © 2022 HyprMX Mobile LLC. All rights reserved.
//

#import <HyprMX/HyprMX.h>
#import "HYPRViewModelConnector.h"
NS_ASSUME_NONNULL_BEGIN
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRFullscreenViewModelConnector : HYPRViewModelConnector  <
HYPRFullScreenViewModelInterface,
HYPRWebTrafficViewModelInterface,
HYPROpenMeasurementViewModelInterface>
- (instancetype)initWithContext:(JSContext<HYPRJSContextProtocol> *)context
                    viewModelId:(nullable NSString *)viewModelId
                          queue:(NSOperationQueue *)queue;
@end

NS_ASSUME_NONNULL_END
