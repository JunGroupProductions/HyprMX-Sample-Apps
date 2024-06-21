//
//  HYPRWeakNativeProxy.h
//  HyprMX
//
//  Created by Sean Reinhardt on 6/3/22.
//  Copyright © 2022 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HYPRFullscreenNativeDelegate.h"
#import "HYPRWebTrafficNativeDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol HYPRWeakNativeProxyProtocol <NSObject>
-(instancetype)initWithDelegate:(NSObject *)delegate;
@end

NS_ASSUME_NONNULL_END

@interface HYPRWeakNativeProxy: NSObject <HYPRWeakNativeProxyProtocol>
@end

@interface HYPRFullscreenWeakNativeProxy: HYPRWeakNativeProxy <HYPRFullscreenNativeDelegate>
@end

@interface HYPRWebTrafficWeakNativeProxy: HYPRFullscreenWeakNativeProxy <HYPRWebTrafficNativeDelegate>
@end
