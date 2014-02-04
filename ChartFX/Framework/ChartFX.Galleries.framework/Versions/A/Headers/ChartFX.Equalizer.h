@interface CFXEqualizerItem : NSObject 
{
}

@property (nonatomic, retain) UIColor* borderColor;
@property (nonatomic, retain) UIColor* color;
@property (nonatomic, assign) int count;

@end

@interface CFXEqualizerItemCollection : NSObject 
{
}

@property (nonatomic, assign, readonly) int count;
- (CFXEqualizerItem*) objectAtIndex:(int)index;
- (void) add:(CFXEqualizerItem*)item;
- (void) clear;

@end

@interface CFXEqualizerBar : NSObject 
{
}

@property (nonatomic, assign) float gapRatio;
@property (nonatomic, assign) float heightRatio;
@property (nonatomic, retain) UIColor* offBorderColor;
@property (nonatomic, retain) UIColor* offColor;
@property (nonatomic, assign) float roundnessRatio;
@property (nonatomic, assign) BOOL showBorders;
@property (nonatomic, retain) NSString* templateText;
@property (nonatomic, retain, readonly) CFXEqualizerItemCollection* topItems;

@end

