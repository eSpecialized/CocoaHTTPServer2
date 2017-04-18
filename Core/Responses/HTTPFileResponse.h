#import <Foundation/Foundation.h>
#import "HTTPResponse.h"

@class HTTPConnection;


@interface HTTPFileResponse : NSObject <HTTPResponse>
{
	HTTPConnection *connection;
	
	NSString *filePath;
	UInt64 fileLength;
	UInt64 fileOffset;
	
	BOOL aborted;
	
	int fileFD;
	void *buffer;
	NSUInteger bufferSize;
}

- (instancetype)initWithFilePath:(NSString *)filePath forConnection:(HTTPConnection *)connection ;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *filePath;

@end
