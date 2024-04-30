//
//  HYPRNoOfferViewController.h
//  HyprMX-Framework
//

#import <UIKit/UIKit.h>
#import "HYPRPresentationResultsDelegate.h"
#import "HYPRConstants.h"
@class HYPRUserInterface;
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRNoOfferViewController : UIViewController

/** Designated initializer to create an instance of a no offer view controller */
- (instancetype)initWithUI:(HYPRUserInterface *)ui StatusDelegate:(NSObject<HYPRPresentationResultsDelegate> *)statusDelegate;

@end
