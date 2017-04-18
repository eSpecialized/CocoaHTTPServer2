#import "HTTPResponse.h"

@interface HTTPErrorResponse : NSObject <HTTPResponse> {
    NSInteger _status;
}

- (instancetype)initWithErrorCode:(int)httpErrorCode NS_DESIGNATED_INITIALIZER;

@end
