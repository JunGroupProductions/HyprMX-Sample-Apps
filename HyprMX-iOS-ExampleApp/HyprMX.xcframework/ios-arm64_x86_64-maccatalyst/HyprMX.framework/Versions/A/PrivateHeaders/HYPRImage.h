//
//  HYPRImage.h
//  HyprMX-Framework
//
//  Created on 3/5/12.
//  Copyright (c) 2012 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HYPRImage;

/* A HyprMX Mobile API specified instance of an image */
@interface HYPRImage : NSObject

extern HYPRImage* HYPRImageForWidth(NSArray* images, float width);

/* URL location of this image */
@property (nonatomic, copy) NSString *url;

/* Width of the image for the current scale */
@property (nonatomic, assign) NSUInteger width;

/* Height of the image for the current scale */
@property (nonatomic, assign) NSUInteger height;

/* Scale of the image. (e.g., 1.0 non-retina, 2.0 retina) */
@property (nonatomic, assign) float scale;

/* Is this image meant to be tiled? */
@property (nonatomic, assign, getter = isTiled) BOOL tiled;

/* x position of the image to cut out */
@property (nonatomic, assign) float x;

/* y position of the image to cut out */
@property (nonatomic, assign) float y;

@end
