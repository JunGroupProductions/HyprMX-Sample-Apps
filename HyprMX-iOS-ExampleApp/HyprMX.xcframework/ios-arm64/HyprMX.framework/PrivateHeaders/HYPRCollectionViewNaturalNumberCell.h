//
//  HYPRCollectionViewNaturalNumberCell.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import "HYPRConstants.h"
#import "HYPRCollectionViewCell.h"
#import <UIKit/UIKit.h>
@class HYPRUserInfoElementStyle, HYPRUserInfoElementImage, HYPRRequiredInfoSelectionShape;
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRCollectionViewNaturalNumberCell : HYPRCollectionViewCell<UITextFieldDelegate>

// Editable text field property
@property (nonatomic, strong, nonnull) UITextField *textInput;

// Callback when text field changes values
@property (nonatomic, strong, nonnull) void(^valueChanged)( NSString * _Nullable string);

@end
