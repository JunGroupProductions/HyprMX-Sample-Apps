//
//  HYPRRequiredInfoSelectionShape.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HYPRRequiredInfoSelectionShape : NSObject

/* Diameter of shape */
@property (nonatomic, copy) NSNumber *diameter;

/* Corner radius to apply to shape */
@property (nonatomic, copy) NSNumber *cornerRadius;

/* Shape Color when cell has not been selected */
@property (nonatomic, copy) NSString *unselectedColor;

/* Shape Color when cell is selected  */
@property (nonatomic, copy) NSString *selectedColor;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
