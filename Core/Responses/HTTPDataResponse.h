#import <Foundation/Foundation.h>
#import "HTTPResponse.h"


@interface HTTPDataResponse : NSObject <HTTPResponse>
{
	NSUInteger offset;
	NSData *data;
}

- (instancetype)initWithData:(NSData *)data NS_DESIGNATED_INITIALIZER;

@end
