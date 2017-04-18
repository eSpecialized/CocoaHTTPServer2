#import "HTTPResponse.h"

@interface PUTResponse : NSObject <HTTPResponse> {
  NSInteger _status;
}
- (instancetype) initWithFilePath:(NSString*)path headers:(NSDictionary*)headers bodyData:(NSData*)body;
- (instancetype) initWithFilePath:(NSString*)path headers:(NSDictionary*)headers bodyFile:(NSString*)body;
@end
