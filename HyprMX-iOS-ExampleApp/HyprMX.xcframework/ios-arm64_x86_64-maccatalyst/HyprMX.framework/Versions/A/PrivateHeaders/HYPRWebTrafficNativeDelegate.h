//
//  HYPRWebTrafficNativeDelegate.h
//  HyprMX-Framework
//
#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol HYPRWebTrafficNativeDelegate <JSExport>

@required
- (void)showWebTrafficHeader:(NSNumber *)pageCount;
- (void)loadWebTrafficPage:(NSString *)url :(NSNumber *)index :(id)userAgent;
- (void)loadThankYouPage:(NSString *)url;
- (void)showNextButton;
- (void)showFinishButton;
- (void)startCountDownTimer:(NSNumber *)time;
- (void)pauseCountDownTimer;
- (void)resumeCountDownTimer;
- (void)setForwardButtonEnabled:(BOOL)enabled;
@end
