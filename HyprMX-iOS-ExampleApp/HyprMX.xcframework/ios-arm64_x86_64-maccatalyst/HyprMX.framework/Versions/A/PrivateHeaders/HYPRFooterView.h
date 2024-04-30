
#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"
#import "HYPREnvironment.h"
#import "HYPRFooter.h"

@protocol HYPRFooterDelegate
/**
 * The back button was tapped
 */
- (void)didTapBack;

/**
 * The forward button was tapped
 */
- (void)didTapForward;

/**
 * A link was tapped (text)
 */
- (void)didTapURL:(NSString *)urlString;

/**
 * A link was tapped (icon)
 */
- (void)didTapIconIndex:(NSInteger)index;

@end
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRFooterView : UIView

@property (weak, nonatomic) id<HYPRFooterDelegate> delegate;

/**
 * Sets the back button to the enabled or disabled state.
 *
 * @param enable True = enable, false = disabled.
 */
- (void)enableBackButton:(BOOL) enable;

/**
 * Sets the forward button to the enabled or disabled state.
 *
 * @param enable True = enable, false = disabled.
 */
- (void)enableForwardButton:(BOOL) enable;

- (id)initWithFrame:(CGRect)frame footer:(HYPRFooter *)footer footerDelegate:(id<HYPRFooterDelegate>)footerDelegate showNavigation:(BOOL)showNavigation;

@end
