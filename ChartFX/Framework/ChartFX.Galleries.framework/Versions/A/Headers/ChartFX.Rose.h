@interface CFXRose : NSObject 
{
}

@property (nonatomic, assign) BOOL circular;
@property (nonatomic, assign) BOOL clockwise;
@property (nonatomic, assign) float internalRadius;
@property (nonatomic, assign) BOOL sideBySide;
@property (nonatomic, assign) double startAngle;
@property (nonatomic, retain) NSString* templateText;

@end

