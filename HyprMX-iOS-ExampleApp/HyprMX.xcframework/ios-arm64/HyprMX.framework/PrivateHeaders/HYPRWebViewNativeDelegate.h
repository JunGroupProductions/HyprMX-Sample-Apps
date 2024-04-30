//
//  HYPRWebViewNativeDelegate.h
//  HyprMX-Framework
//
#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol HYPRWebViewNativeDelegate <JSExport>

@required
- (void)setUrl:(NSString *)urlString;
- (void)setAdHtml:(NSString *)data;
- (void)runScript:(NSString *)script;
- (void)setUserAgent:(NSString *)userAgent;
- (void)navigateBack;
- (void)navigateForward;
- (void)removeJavascriptInterface;
- (void)updateWebViewConfiguration:(NSString *)data;
@end
