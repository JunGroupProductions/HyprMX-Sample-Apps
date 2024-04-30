//
//  HYPRNoOfferAppearance.h
//  HyprMX-Framework
//
//  Created on 4/16/12.
//  Copyright (c) 2012 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HYPRNoOfferAppearance : NSObject

/** property title specifies the title to use on the no offer presentation */
@property (nonatomic, copy) NSString *title;

/** property titleColor specifies the color of the title on the no offer presentation. This is specifed in Hex form and later converted to a color as needed. */
@property (nonatomic, copy) NSString *titleColor;

/** property titleSize is the string value of the size of text to draw for the title. This is specified in pts. */
@property (nonatomic, copy) NSString *titleSize;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
