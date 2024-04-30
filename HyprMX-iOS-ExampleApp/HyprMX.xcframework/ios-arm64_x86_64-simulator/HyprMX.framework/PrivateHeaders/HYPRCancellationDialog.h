#import <Foundation/Foundation.h>

/**
 * Representation of the cancellation dialog in the JSON model
 */
@interface HYPRCancellationDialog : NSObject

/* The exit button text */
@property (nonatomic, strong) NSString *exitText;

/* The message to display in the alert */
@property (nonatomic, strong) NSString *messageText;

/* The continue button text */
@property (nonatomic, strong) NSString *continueText;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
