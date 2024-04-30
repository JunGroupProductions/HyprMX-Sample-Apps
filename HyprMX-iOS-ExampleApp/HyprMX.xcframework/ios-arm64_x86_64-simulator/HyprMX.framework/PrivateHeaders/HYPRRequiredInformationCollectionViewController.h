//
//  HYPRRequiredInformationCollectionViewController.h
//  HyprMX-Framework
//
//  Copyright © 2017 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HYPRPresentationResultsDelegate.h"
#import "HYPRConstants.h"

@class HYPRUserInterface, HYPRRequiredInfoQuestion, HYPRUserInfoElementFont;
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRRequiredInformationCollectionViewController : UICollectionViewController

/*
 * Initializer - stores styling, questions and delegate
 * @param requiredInformation - Required Info Questions
 * @param userInterface - UI Components for the presentation
  * @param statusDelegate - the presentation delegate to callback to
 *
 * @return self
 */
- (instancetype)initWithQuestions:(NSArray<HYPRRequiredInfoQuestion *>*)requiredInformation
                    userInterface:(HYPRUserInterface *)userInterface
                   statusDelegate:(NSObject<HYPRPresentationResultsDelegate> *)statusDelegate
                 footerImageLinks:(NSArray<NSString *>*)imageLinks;

/*
 * Helper that parses a font name or returns a system font
 * @param fontModel - Mapped JSON spec for a font
 * @param defaultSize - default size to initialize a system font with if the font model is invalid
 *
 * @return font
 */
+ (UIFont *)fontFromFontModel:(HYPRUserInfoElementFont *)fontModel withDefaultSize:(CGFloat)defaultSize;

@end
