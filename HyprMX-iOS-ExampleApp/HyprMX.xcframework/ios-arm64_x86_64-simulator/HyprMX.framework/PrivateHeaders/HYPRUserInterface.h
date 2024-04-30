//
//  HYPRUserInterface.h
//  HyprMX-Framework
//
//  Created on 4/11/12.
//  Copyright (c) 2012 HyprMX Mobile LLC. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <HyprMX/HYPRNoOfferAppearance.h>

@class HYPRUserInfoAppearance, HYPRImage, HYPRWebLoadingScreenAppearance;

/** User interface settings defines the user interface design as specified by a HyprMX Mobile API request */
@interface HYPRUserInterface : NSObject

/** property noOfferAppearance is an instance of class HYPRNoOfferAppearance that defines the user interface for an offer selector */
@property (nonatomic, strong) HYPRNoOfferAppearance *noOfferAppearance;

/** property userInformationAppearance is an instance of class HYPRUserInformationAppearance that defines the user interface for a required information form */
@property (nonatomic, strong) HYPRUserInfoAppearance *userInfoAppearance;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

+ (HYPRUserInterface *)uiFromJSON:(NSString *)json;
@end
