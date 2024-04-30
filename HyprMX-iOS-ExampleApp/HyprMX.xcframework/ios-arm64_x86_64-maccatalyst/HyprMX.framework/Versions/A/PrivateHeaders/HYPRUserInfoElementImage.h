//
//  HYPRUserInfoElementImage.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HYPRUserInfoElementImage : NSObject

/** Factory method to init based on a dictionary */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/** URL for Image */
@property (nonatomic, copy) NSString *portraitUrl;

/** Image Height */
@property (nonatomic, copy) NSNumber *height;

/** Image Width */
@property (nonatomic, copy) NSNumber *width;

/** Sets if the Image should aspect fit to the section width */
@property (nonatomic) BOOL fillScreenWidth;

@end
