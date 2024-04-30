#import <Foundation/Foundation.h>
#import "HYPRUserInfoElementImage.h"
/**
 * Representation of the footer in the JSON model
 */
@interface HYPRFooter : NSObject

/* The footer text in HTML format */
@property (nonatomic) NSString *footerText;
@property (strong, nonatomic) NSAttributedString *footerAttributedText;

/* The background color of the footer */
@property (nonatomic) NSString *bgColor;

/* The minimum height of the footer */
@property (nonatomic) float minHeight;

/* The first image to display */
@property (nonatomic) HYPRUserInfoElementImage *firstImage;

/* The first second image to display */
@property (nonatomic) HYPRUserInfoElementImage *secondImage;

+ (void)createFooterWithDictionary:(NSDictionary *)dictionary completion:(void (^)(HYPRFooter *))completion;

/**
 * Allocates and inits a new HYPRFooter object.
 *
 * @param dictionary May be nil.
 * @return Returns a new footer, or nil if the dictionary is nil
 */
+ (HYPRFooter*)footerWithDictionary:(NSDictionary *)dictionary;

/**
 * Allocates and inits a default footer with BG Color
 * @param bgColor The background color to set
 * @return Returns a new footer
 */
+ (HYPRFooter *)footerWithBGColor:(NSString *)bgColor;

@end
