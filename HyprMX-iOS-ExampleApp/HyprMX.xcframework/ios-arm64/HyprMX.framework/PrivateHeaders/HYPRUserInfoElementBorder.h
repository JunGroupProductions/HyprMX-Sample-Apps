//
//  HYPRUserInfoElementBorder.h
//  HyprMX-Framework
//
//  Created by Sean Reinhardt on 5/10/17.
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HYPRUserInfoElementBorder : NSObject

/** Border Color */
@property (nonatomic, copy) NSString *borderColor;

/** Border Width */
@property (nonatomic, copy) NSNumber *borderWidth;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
