//
//  HYPRCollectionCollectionViewCell.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import "HYPRConstants.h"
#import <UIKit/UIKit.h>
@class HYPRUserInfoElementStyle, HYPRUserInfoElementImage, HYPRRequiredInfoSelectionShape;

HYPR_CLASS_AVAILABLE_IOS
@interface HYPRCollectionViewCell : UICollectionViewCell

// Text label on cell
@property (strong, nonatomic) UILabel *textLabel;

/*
 * Sets all styling on the section
 * @param style - Mapped JSON style object
 */
- (void)applyStyle:(HYPRUserInfoElementStyle *)style;

/*
 * Sets UIImage View with an UIImage object
 */
- (void)setImageViewWithImage:(UIImage *)image size:(CGSize)size;

/*
 * Sets image on a cell
 * @param image model
 * @param size
 */
- (void)attachImageToSection:(HYPRUserInfoElementImage *)image withSize:(CGSize)size;

/*
 * Sets text label text
 * @param text
 */
- (void)setTextLabelText:(NSString *)text;

/*
 * Creaes a selection shape
 * @param selectionShape model
 */- (void)addSelectionShape:(HYPRRequiredInfoSelectionShape *)selectionShape;

/*
 * Sets whether or not the cell is selected
 * @param isSelected
 */
- (void)setSelectedState:(BOOL)isSelected;

@end
