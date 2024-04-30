//
//  HYPRWebViewModelConnector.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 4/13/21.
//  Copyright © 2021 HyprMX Mobile LLC. All rights reserved.
//

#import "HYPRViewModelConnector.h"
#import "HYPRAvailability.h"
NS_ASSUME_NONNULL_BEGIN

@protocol HYPRWebViewModelInterface <NSObject>
@property(strong, nonatomic, readonly) NSString *adBaseUrl;
@property(strong, nonatomic, readonly) NSString *adBaseEncoding;
@property(strong, nonatomic, readonly) NSString *adBaseMime;
@property(strong, nonatomic, readonly) NSString *userAgent;
@property(strong, nonatomic, readonly) NSString *queryParams;
@property(strong, nonatomic, readonly) NSString *catalogFrameParams;
- (NSString*)getWebViewConfigurationString:(NSDictionary *)arg;
- (NSString*)urlNavigationAttempt:(NSDictionary *)arg;
- (NSString *)shouldRedirectURL:(NSDictionary *)arg;
-(BOOL)onWebViewCrash;
- (nullable NSString *)windowOpenAttempt:(NSDictionary *)arg;
- (BOOL)javaScriptAlertAttempt:(NSDictionary *)arg;
- (void)onHistoryChanged:(NSDictionary *)arg;
- (void)onPageStarted:(NSDictionary *)arg;
- (void)onPageFinished:(NSDictionary *)arg;
- (void)onReceivedError:(NSDictionary *)arg;
- (void)onJSMessage:(NSDictionary *)arg;
- (void)webViewSizeChange:(NSDictionary *)arg;
- (void)onLoadData;
-(BOOL)shouldTakeFocus;
-(BOOL)shouldKeepFocus;
-(BOOL)shouldLoadAboutBlank;
-(NSString *)webviewDestroyScript;
@end

HYPR_CLASS_AVAILABLE_IOS
@interface HYPRWebViewModelConnector : HYPRViewModelConnector <HYPRWebViewModelInterface>
@property (strong, nonatomic, readonly) NSString *baseAdId;
- (instancetype)initWithContext:(JSContext<HYPRJSContextProtocol> *)context
                    viewModelId:(nullable NSString *)viewModelId
                          queue:(NSOperationQueue *)queue;

@end

NS_ASSUME_NONNULL_END
