#import <Foundation/Foundation.h>

@class GCDAsyncSocket;
@class HTTPMessage;
@class HTTPServer;
@class WebSocket;
@protocol HTTPResponse;


#define HTTPConnectionDidDieNotification  @"HTTPConnectionDidDie"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface HTTPConfig : NSObject
{
#if __has_feature(objc_arc_weak)
	HTTPServer __weak *server;
#else
	HTTPServer __unsafe_unretained *server;
#endif
	NSString __strong *documentRoot;
	dispatch_queue_t queue;
}

- (instancetype)initWithServer:(HTTPServer *)server documentRoot:(NSString *)documentRoot NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithServer:(HTTPServer *)server documentRoot:(NSString *)documentRoot queue:(dispatch_queue_t)q NS_DESIGNATED_INITIALIZER;

#if __has_feature(objc_arc_weak)
@property (nonatomic, weak, readonly) HTTPServer *server;
#else
@property (nonatomic, unsafe_unretained, readonly) HTTPServer *server;
#endif

@property (nonatomic, strong, readonly) NSString *documentRoot;
@property (nonatomic, readonly) dispatch_queue_t queue;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface HTTPConnection : NSObject
{
	dispatch_queue_t connectionQueue;
	GCDAsyncSocket *asyncSocket;
	HTTPConfig *config;
	
	BOOL started;
	
	HTTPMessage *request;
	unsigned int numHeaderLines;
	
	BOOL sentResponseHeaders;
	
	NSString *nonce;
	long lastNC;
	
	NSObject<HTTPResponse> *httpResponse;
	
	NSMutableArray *ranges;
	NSMutableArray *ranges_headers;
	NSString *ranges_boundry;
	int rangeIndex;
	
	UInt64 requestContentLength;
	UInt64 requestContentLengthReceived;
	UInt64 requestChunkSize;
	UInt64 requestChunkSizeReceived;
  
	NSMutableArray *responseDataSizes;
}

- (instancetype)initWithAsyncSocket:(GCDAsyncSocket *)newSocket configuration:(HTTPConfig *)aConfig NS_DESIGNATED_INITIALIZER;

- (void)start;
- (void)stop;

- (void)startConnection;

- (BOOL)supportsMethod:(NSString *)method atPath:(NSString *)path;
- (BOOL)expectsRequestBodyFromMethod:(NSString *)method atPath:(NSString *)path;

@property (NS_NONATOMIC_IOSONLY, getter=isSecureServer, readonly) BOOL secureServer;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray *sslIdentityAndCertificates;

- (BOOL)isPasswordProtected:(NSString *)path;
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL useDigestAccessAuthentication;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *realm;
- (NSString *)passwordForUser:(NSString *)username;

- (NSDictionary *)parseParams:(NSString *)query;
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSDictionary *parseGetParams;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *requestURI;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray *directoryIndexFileNames;
- (NSString *)filePathForURI:(NSString *)path;
- (NSString *)filePathForURI:(NSString *)path allowDirectory:(BOOL)allowDirectory;
- (NSObject<HTTPResponse> *)httpResponseForMethod:(NSString *)method URI:(NSString *)path;
- (WebSocket *)webSocketForURI:(NSString *)path;

- (void)prepareForBodyWithSize:(UInt64)contentLength;
- (void)processBodyData:(NSData *)postDataChunk;
- (void)finishBody;

- (void)handleVersionNotSupported:(NSString *)version;
- (void)handleAuthenticationFailed;
- (void)handleResourceNotFound;
- (void)handleInvalidRequest:(NSData *)data;
- (void)handleUnknownMethod:(NSString *)method;

- (NSData *)preprocessResponse:(HTTPMessage *)response;
- (NSData *)preprocessErrorResponse:(HTTPMessage *)response;

- (void)finishResponse;

@property (NS_NONATOMIC_IOSONLY, readonly) BOOL shouldDie;
- (void)die;

@end

@interface HTTPConnection (AsynchronousHTTPResponse)
- (void)responseHasAvailableData:(NSObject<HTTPResponse> *)sender;
- (void)responseDidAbort:(NSObject<HTTPResponse> *)sender;
@end
