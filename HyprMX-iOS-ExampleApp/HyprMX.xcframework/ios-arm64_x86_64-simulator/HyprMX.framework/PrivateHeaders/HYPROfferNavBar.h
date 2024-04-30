//
//  HYPROfferNavBar.h
//  HyprMX-SDK
//
//  Created by Sean Reinhardt on 1/28/19.
//  Copyright © 2019 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HyprMX/HYPRJSContext.h>

NS_ASSUME_NONNULL_BEGIN

@interface HYPROfferNavBar : NSObject

@property (strong, nonatomic) NSString *titleText;
@property (strong, nonatomic) NSString *nextButtonText;
@property (strong, nonatomic) NSString *finishButtonText;
@property (strong, nonatomic) NSString *countdownText;

@property (strong, nonatomic) NSAttributedString *titleAttributedText;
@property (strong, nonatomic) NSAttributedString *nextButtonAttributedText;
@property (strong, nonatomic) NSAttributedString *finishButtonAttributedText;
@property (strong, nonatomic) NSAttributedString *countdownAttributedText;

@property (strong, nonatomic) NSNumber *minimumHeaderHeight;
@property (strong, nonatomic) NSNumber *finishButtonMinHeight;
@property (strong, nonatomic) NSNumber *finishButtonMinWidth;
@property (strong, nonatomic) NSNumber *nextButtonMinHeight;
@property (strong, nonatomic) NSNumber *nextButtonMinWidth;

@property (strong, nonatomic) NSString *headerBackgroundColor;
@property (strong, nonatomic) NSString *nextButtonColor;
@property (strong, nonatomic) NSString *finishButtonColor;
@property (strong, nonatomic) NSString *pageIndicatorColor;
@property (strong, nonatomic) NSString *pageIndicatorColorSelected;
@property (strong, nonatomic) NSString *closeButtonColor;
@property (strong, nonatomic) NSString *chevronColor;
@property (strong, nonatomic) NSString *spinnerTintColor;
@property (strong, nonatomic) NSDictionary *closeButtonImage;

+ (void)navBarWithJson:(NSDictionary *)json barTitle:(NSString *)title context:(JSContext<HYPRJSContextProtocol> *)context completion:(void (^)(HYPROfferNavBar *))completion;
@end

NS_ASSUME_NONNULL_END
