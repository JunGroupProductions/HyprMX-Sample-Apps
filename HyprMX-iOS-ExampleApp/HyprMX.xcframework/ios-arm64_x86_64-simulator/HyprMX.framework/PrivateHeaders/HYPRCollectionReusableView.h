//
//  HYPRCollectionReusableView.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HYPRConstants.h"

typedef NS_ENUM(NSInteger, HYPRRequiredInfoSectionViewType) {
    
    HYPRRequiredInfoSectionViewTypeHeader = 0,
    HYPRRequiredInfoSectionViewTypeQuestion = 1,
    HYPRRequiredInfoSectionViewTypeFooter = 2,
};

@class HYPRUserInfoElementStyle, HYPRUserInfoElementImage;
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRCollectionReusableView : UICollectionReusableView

// Section text label
@property (strong, nonatomic) UILabel *textLabel;

// Section Sticks to top or bottom of layout - should have high zIndex
@property (nonatomic) BOOL isSticky;

/*
 * Adds a UIImage to the section's imageView
 */
- (void)setImageViewWithImage:(UIImage *)image size:(CGSize)size;

/*
 * Sets all styling on the section
 * @param style - Mapped JSON style object
 * @param defaultType - used for which default font sizes to fall back on
 */
- (void)applyStyle:(HYPRUserInfoElementStyle *)style withDefault:(HYPRRequiredInfoSectionViewType)defaultType;

- (void)styleForErrorMessageWithFont:(UIFont*)font;

/*
 * Sets text label text
 * @param text 
 */
- (void)setTextLabelText:(NSString *)text;

/*
 * Attaches image to section
 * @param image - Mapped JSON image spec
 * @param size - size the image will be displayed in the section
 *
 */
- (void)attachImageToSection:(HYPRUserInfoElementImage *)image withSize:(CGSize)size;

/*
 * Makes section clickable with a URL to open in Safari View controller
 * @param url
 */
- (void)addClickURL:(NSString *)urlString;
@end
