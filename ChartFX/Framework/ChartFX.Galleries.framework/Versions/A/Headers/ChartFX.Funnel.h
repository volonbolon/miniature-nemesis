@interface CFXFunnel : NSObject 
{
}

@property (nonatomic, assign) BOOL conic;
@property (nonatomic, assign) int faces;
@property (nonatomic, assign) BOOL labelInside;
@property (nonatomic, retain, readonly) CFXLine* labelLine;
@property (nonatomic, assign) BOOL labelLineAsSeries;
@property (nonatomic, assign) int separation;
@property (nonatomic, retain) NSString* templateText;
@property (nonatomic, assign) double tipHeight;
@property (nonatomic, assign) double tipWidth;

@end

