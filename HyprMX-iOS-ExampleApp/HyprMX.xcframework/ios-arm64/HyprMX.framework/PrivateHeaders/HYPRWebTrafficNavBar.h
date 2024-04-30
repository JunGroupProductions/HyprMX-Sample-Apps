//
//  HYPRNavBar.h
//  HyprMX-SDK
//
//  Created by Ben Balcomb on 3/12/18.
//  Copyright © 2018 HyprMX Mobile LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HYPRConstants.h"

@protocol HYPRWebTrafficNavBarDelegate

- (void)didTapClose;
- (void)didTapNext;
- (void)didTapFinish;

@end
@class HYPROfferNavBar;
HYPR_CLASS_AVAILABLE_IOS
@interface HYPRWebTrafficNavBar : UIView

@property (weak, nonatomic) id<HYPRWebTrafficNavBarDelegate> delegate;
@property (nonatomic, assign) BOOL isClosable;
@property (nonatomic, assign) BOOL nextButtonEnabled;
@property (nonatomic, assign) BOOL finishButtonEnabled;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *timeRemaining;
@property (nonatomic, assign) NSUInteger pageNumber;
@property (nonatomic, assign) NSInteger pageCount;

- (instancetype)initWithModel:(HYPROfferNavBar *)navBarModel;

@end
