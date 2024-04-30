//
//  HYPRWeakTimerTarget.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 4/2/21.
//  Copyright © 2021 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HYPRWeakTimerTarget :NSObject
- (instancetype)initWithTarget:(id)target selector:(SEL)selector;
- (void)timerDidFire:(NSTimer *)timer;
@end


NS_ASSUME_NONNULL_END
