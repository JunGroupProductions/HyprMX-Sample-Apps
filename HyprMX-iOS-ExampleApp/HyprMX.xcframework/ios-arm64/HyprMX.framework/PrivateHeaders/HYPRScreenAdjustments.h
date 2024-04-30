//
//  HYPRScreenAdjustments.h
//  HyprMX-Framework
//
//  Created by Guilherme Endres on 11/28/14.
//  Copyright (c) 2014 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <math.h>
#import <CoreGraphics/CoreGraphics.h>

@interface HYPRScreenAdjustments : NSObject

/**
 * Convert the Screen to Landscape if the screen is in Portrait.
 *
 * @param width screen width size.
 * @param height screen height size.
 * @return CGSize with the correct screen size.
 *
 **/
+ (CGSize)convertToLandscapeIfNeededWithWidth:(CGFloat)width andHeight:(CGFloat)height;
@end
