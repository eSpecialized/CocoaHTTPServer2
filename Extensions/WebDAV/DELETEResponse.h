#import "HTTPResponse.h"

@interface DELETEResponse : NSObject <HTTPResponse> {
  NSInteger _status;
}
- (instancetype) initWithFilePath:(NSString*)path NS_DESIGNATED_INITIALIZER;
@end
