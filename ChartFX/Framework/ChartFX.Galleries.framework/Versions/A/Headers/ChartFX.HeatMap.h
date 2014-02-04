@interface CFXColorGradientStop : NSObject 
{
}

@property (nonatomic, assign) double offset;
@property (nonatomic, retain) UIColor* color;

@end

@interface CFXColorGradientCollection : NSObject 
{
}

@property (nonatomic, assign, readonly) int count;
- (CFXColorGradientStop*) objectAtIndex:(int)index;
- (void) replaceObjectAtIndex:(int)index withObject:(CFXColorGradientStop*)object;
- (void) add:(CFXColorGradientStop*)stop;
- (void) clear;
- (void) insertObject:(CFXColorGradientStop*)stop atIndex:(int)index;

@end

@interface CFXHeatMap : NSObject <CFXILegendBoxItemCollection,CFXILegendBoxItem>
{
}

@property (nonatomic, retain, readonly) CFXColorGradientCollection* gradientStops;
@property (nonatomic, assign) int legendHeight;

@end

