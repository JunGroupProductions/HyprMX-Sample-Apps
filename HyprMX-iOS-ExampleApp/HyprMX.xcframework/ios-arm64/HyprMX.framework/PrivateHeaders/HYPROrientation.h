//
//  HYPROrientation.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 12/1/20.
//  Copyright © 2020 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.4))
@interface HYPROrientation : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithApplication:(UIApplication *)app window:(UIWindow *)window;
- (instancetype)initWithApp:(UIApplication*)app window:(nullable UIWindow *)window;
- (UIInterfaceOrientationMask)supportedOrientations;
- (NSArray<NSString*>*)orientationList;
- (BOOL)isPortraitSupported;

@property (nonatomic, readonly) UIInterfaceOrientationMask mask;
- (UIInterfaceOrientation)preferredInterfaceOrientation;
- (BOOL)shouldAutorotate;
-(void)setDesiredOrientationMask:(UIInterfaceOrientationMask)mask;
-(void)setDesiredOrientationMaskWithOrientation:(UIInterfaceOrientation)orientation;

+ (UIWindow *)activeWindow;
+ (UIInterfaceOrientation)currentOrientation;

@end

NS_ASSUME_NONNULL_END
