//
//  HYPRHelpers.h
//  HyprMX-Framework
//

#import <UIKit/UIKit.h>
#import "HYPRAvailability.h"

/**
 * HYPR_CAN_CALL(block) should be used as a safeguard when
 * a nil block is not expected.
 *
 * Do not use it for logical branching because the return value
 * can change in debug mode (to prevent hiding errors).
 */
#define HYPR_CAN_CALL(block) HYPRCanCallBlock(block, NSStringFromClass(self.class), NSStringFromSelector(_cmd), __LINE__)
extern BOOL HYPRCanCallBlock(id block, NSString *className, NSString *methodName, int line);

/**
  * HYPRHelpers are support methods are thread safe and do not contain state
  * No Thread Asserts Required
  */
@interface HYPRHelpers : NSObject

/**
 * Method to check that pList key is present and has a value of proper type in given bundle
 * @param key the name of the key being checked for
 * @param bundle bundle being checked
 *
 * @return BOOL describing if key is present with value of the proper type
 */
+ (BOOL)isDescriptionKeyPresent: (NSString *)key forBundle: (NSBundle*) bundle;

/**
* Method added to match format of toISOString() in shared JS.
*
* @param params The NSDictionary to convert to JSON string.
* @param error The reference to an error object
*
* @return An NSString with JSON
*/
+ (NSString *)jsonStringFromDictionary:(NSDictionary *)params error:(NSError **)error;

/**
* Takes a JSON String of a dictionary object and converts it to an NSDictionary.
*
* @param json The NSString to convert to NSDictionary.
*
* @return An NSString with JSON
*/
+ (NSDictionary *)jsonDictionary:(NSString *)json;
+ (NSArray *)jsonArray:(NSString *)json;

/**
 * Generates a UI Color from an RGB HEX String.
 *
 * @param rgbHexString The 6(RRGGBB) or 8(AARRGGBB) character RGB hex string.  If no alpha provided, then 1 is used.
 * @return The generated UI Color.  Nil if there were errors parsing.
 */
+ (UIColor *)generateColorWithRGBHex:(NSString *)rgbHexString;

/**
 * Returns the standard blue color for use as tintColor throughout the framework. This happens to be close to the default color used in iOS 7.
 * @return UIColor of the standard blue color for the framework.
 */
+ (UIColor *) standardBlueColor;

/*
 used for backgroundColor of web traffic header/footer separator line
 */
+ (UIColor *) webTrafficSeparatorColor;

/**
 * Creates a bitmap image using the data contained within a subregion of an existing bitmap image.
 *
 * @param image The image to extract the subimage from.
 * @param rect A rectangle whose coordinates specify the area to create an image from.
 * @return A new UI Image
 */
+ (UIImage *) getImageWithinImage:(UIImage *)image rect:(CGRect)rect;

/**
 * Create custom image with the supplied tint
 *
 * @param image The image to tint
 * @param tintColor The color to tint the image
 * @return Returns a new image with the tint applied.
 */
+ (UIImage *) tintImage:(UIImage *)image tintColor:(UIColor *)tintColor;

/**
 * Converts a Base64 encoded string into an NSData object.
 * Padding '=' characters are optional. Whitespace is ignored.
 * @param string The encoded string
 * @return The NSData object representing the string
 */
+ (NSData *)getNSDataFromBase64EncodedString:(NSString *)string;

/** Returns nil instead of NULL for a given value */
+ (id)valueOrNil:(id)value;

/** Returns the default instead of NULL for a given value */
+ (float)floatValueOrDefault:(id)value defaultFloat:(float)defaultFloat;

+ (UIView*)xGraphicWithHeight:(CGFloat)height
                        color:(UIColor*)color;
+ (UIView*)chevronGraphicWithHeight:(CGFloat)height
                              color:(UIColor*)color;

/** Evaluates String and returns true if content indicates it contains html elements*/
+ (BOOL)isHTMLString:(NSString *)string;

+ (void)setHidesSharedBackgroundFor:(UIBarButtonItem *)item;

@end
