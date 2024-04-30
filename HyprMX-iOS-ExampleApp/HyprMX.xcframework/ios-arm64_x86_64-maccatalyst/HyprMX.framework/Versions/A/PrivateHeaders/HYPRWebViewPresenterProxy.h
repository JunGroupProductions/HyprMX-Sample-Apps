//
//  HYPRWebViewPresenterProxy.h
//  HyprMX
//
//  Created by Sean Reinhardt on 7/18/22.
//  Copyright © 2022 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <HyprMX/HYPRAvailability.h>

@class HYPRWebViewPresenter;
NS_ASSUME_NONNULL_BEGIN

HYPR_CLASS_AVAILABLE_IOS
@interface HYPRWebViewPresenterProxy : NSObject <WKScriptMessageHandler>
+(instancetype)proxyForPresenter:(HYPRWebViewPresenter *)presenter;
@end

NS_ASSUME_NONNULL_END
