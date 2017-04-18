#import "HTTPResponse.h"

@interface DAVResponse : NSObject <HTTPResponse> {
@private
  UInt64 _offset;
  NSMutableDictionary* _headers;
  NSData* _data;
  NSInteger _status;
}
- (instancetype) initWithMethod:(NSString*)method headers:(NSDictionary*)headers bodyData:(NSData*)body resourcePath:(NSString*)resourcePath rootPath:(NSString*)rootPath NS_DESIGNATED_INITIALIZER;
@end
