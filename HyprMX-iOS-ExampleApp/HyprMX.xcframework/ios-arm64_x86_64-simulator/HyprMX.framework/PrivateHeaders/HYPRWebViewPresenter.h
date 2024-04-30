//
//  HYPRWebViewPresenter.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 3/9/21.
//  Copyright © 2021 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "HYPREnvironment.h"
#import "HYPRPresenterDelegate.h"
#import "HYPRWebViewModelConnector.h"
#import "HYPRWebViewNativeDelegate.h"
#import "HYPRPresentationAdapterProtocol.h"
#import "HYPRJSContext.h"
NS_ASSUME_NONNULL_BEGIN
extern NSString * const kHYPRWebViewViewModel;
@class HYPRWebView, HYPRWebViewUpdateConfiguration, HYPROrientation;
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRWebViewPresenter : NSObject <WKNavigationDelegate, WKUIDelegate, WKScriptMessageHandler, UIScrollViewDelegate, HYPRWebViewDelegate, HYPRWebViewNativeDelegate>
@property (strong, nonatomic) HYPRWebViewModelConnector *viewModel;
-(instancetype)initWithContext:(JSContext<HYPRJSContextProtocol> *)context
                     viewModel:(HYPRWebViewModelConnector *)viewModel
             presenterDelegate:(id<HYPRPresentationAdapterDelegate>)delegate
                   orientation:(HYPROrientation *)orientation;
-(HYPRWebViewUpdateConfiguration *)webViewConfiguration:(NSString *)mode;
@end
NS_ASSUME_NONNULL_END
