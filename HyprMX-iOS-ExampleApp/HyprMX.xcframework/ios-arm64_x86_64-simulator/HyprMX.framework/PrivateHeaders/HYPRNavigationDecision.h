//
//  HYPRNavigationDecision.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 7/31/20.
//  Copyright © 2020 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, HYPRUrlNavigationResult) {
    HYPRUrlNavigationResultNavigationAllowed = 0,
    HYPRUrlNavigationResultNavigationBlocked = 1,
    HYPRUrlNavigationResultOpenOutsideApp = 2,
    HYPRUrlNavigationResultRedirected = 3,
};

NS_ASSUME_NONNULL_BEGIN

@interface HYPRNavigationDecision : NSObject
@property (nonatomic) HYPRUrlNavigationResult decision;
@property (strong, nonatomic) NSString *redirectUrl;
+(nullable instancetype)fromJSON:(NSString *)json;
-(instancetype) init __attribute__((unavailable("init not available")));  
@end

NS_ASSUME_NONNULL_END
