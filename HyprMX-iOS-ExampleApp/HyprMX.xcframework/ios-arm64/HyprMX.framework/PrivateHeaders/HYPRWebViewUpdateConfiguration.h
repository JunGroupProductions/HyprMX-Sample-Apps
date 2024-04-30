//
//  HYPRWebViewAsyncScriptEvent.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 3/31/21.
//  Copyright © 2021 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HYPRWebViewUpdateConfiguration : NSObject
@property (nonatomic) BOOL shouldScrollBounce;
@property (nonatomic) BOOL isScrollingEnabled;
@property (nonatomic) BOOL allowsPinchGesture;
@property (nonatomic) BOOL allowsLinkPreview;
@property (nonatomic) BOOL isOpaque;
@property (strong, nonatomic) NSString *customUserAgent;
@property (strong, nonatomic) UIColor *backgroundColor;
@property (nonatomic) WKAudiovisualMediaTypes playbackRequiresUserAction API_AVAILABLE(ios(10.0));
@property (nonatomic) BOOL allowsInlineMediaPlayback;
@property (nonatomic) BOOL allowsAirPlayForMediaPlayback;
@property (nonatomic) BOOL allowsPictureInPictureMediaPlayback;
@property (nonatomic) BOOL isNavigationLimited;
@property (nonatomic, strong) NSArray<NSString *> *headScripts;
+(nullable instancetype)fromDictionary:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
