#import <Foundation/Foundation.h>
#import "HTTPResponse.h"


@interface HTTPRedirectResponse : NSObject <HTTPResponse>
{
	NSString *redirectPath;
}

- (instancetype)initWithPath:(NSString *)redirectPath NS_DESIGNATED_INITIALIZER;

@end
