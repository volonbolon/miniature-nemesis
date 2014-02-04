typedef NS_ENUM(NSInteger, CFXAnnImageMode) 
{
    CFXAnnImageModeOriginal = 0,
    CFXAnnImageModeStretch = 1,
    CFXAnnImageModeTile = 2
};

typedef NS_ENUM(NSInteger, CFXAttachMode) 
{
    CFXAttachModeNone = 0,
    CFXAttachModePoint = 1,
    CFXAttachModeElastic = 2
};

typedef NS_ENUM(NSInteger, CFXBalloonTailCorner) 
{
    CFXBalloonTailCornerTopLeft = 0,
    CFXBalloonTailCornerTopRight = 1,
    CFXBalloonTailCornerBottomRight = 2,
    CFXBalloonTailCornerBottomLeft = 3,
    CFXBalloonTailCornerTop = 4,
    CFXBalloonTailCornerRight = 5,
    CFXBalloonTailCornerBottom = 6,
    CFXBalloonTailCornerLeft = 7
};

@interface CFXAnnotationObject : NSObject 
{
}

@property (nonatomic, assign) CFXAnchorStyles anchor;
@property (nonatomic, retain) CFXLine* border;
@property (nonatomic, retain) UIColor* color;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) int left;
@property (nonatomic, assign) BOOL paintBefore;
@property (nonatomic, assign) CFXHatchStyle pattern;
@property (nonatomic, assign) BOOL plotAreaOnly;
@property (nonatomic, retain) id tag;
@property (nonatomic, assign) int top;
@property (nonatomic, assign) BOOL visible;
@property (nonatomic, assign) int width;
- (void) attachAtXAxisValue:(double)xAxisValue andYAxisValue:(double)yAxisValue;
- (void) attachElasticFromXAxis:(double)xAxis toXAxis:(double)toXAxis andFromYAxis:(double)fromYAxis toYAxis:(double)toYAxis;
- (void) attachWithHorizontalAlignment:(CFXStringAlignment)horizontalAlignment atXAxisValue:(double)xAxisValue andVerticalAlignment:(CFXStringAlignment)verticalAlignment atYAxisValue:(double)yAxisValue;
- (void) detach;
- (void) flipHorizontal:(BOOL)horizontal;
- (void) refresh;
- (void) rotateClockwise:(BOOL)clockWise;

@end


@interface CFXAnnotationVector : CFXAnnotationObject 
{
}

@property (nonatomic, retain) NSString* templateText;

@end

@interface CFXAnnotationText : CFXAnnotationObject 
{
}

@property (nonatomic, assign) CFXStringAlignment align;
@property (nonatomic, assign) BOOL clip;
@property (nonatomic, assign) int cornerRadius;
@property (nonatomic, retain) UIFont* font;
@property (nonatomic, assign) CFXStringAlignment lineAlignment;
@property (nonatomic, assign) int orientation;
@property (nonatomic, retain) NSString* text;
@property (nonatomic, retain) UIColor* textColor;
@property (nonatomic, assign) BOOL wordWrap;
- (void) sizeToFit;

@end

@interface CFXAnnotationBalloon : CFXAnnotationText 
{
}

@property (nonatomic, assign) CFXBalloonTailCorner tailCorner;
@property (nonatomic, assign) int tailFactor;

@end

@interface CFXAnnotationRectangle : CFXAnnotationObject 
{
}


@end

@interface CFXAnnotationPicture : CFXAnnotationObject 
{
}

@property (nonatomic, assign) CFXAnnImageMode mode;
@property (nonatomic, retain) UIImage* picture;
- (void) sizeToFit;

@end

@interface CFXAnnotationContainer : CFXAnnotationObject 
{
}

@property (nonatomic, retain) id element;

@end

@interface CFXAnnotationCircle : CFXAnnotationObject 
{
}


@end

@interface CFXAnnotationArrow : CFXAnnotationObject 
{
}


@end

@interface CFXAnnotationArc : CFXAnnotationObject 
{
}


@end

@interface CFXAnnotationList : NSObject 
{
}

- (CFXAnnotationObject*) objectAtIndex:(int)n;
- (void) add:(CFXAnnotationObject*)annObj;
- (BOOL) contains:(CFXAnnotationObject*)annObj;
- (int) indexOf:(CFXAnnotationObject*)annObject;
- (void) insertObject:(CFXAnnotationObject*)annObj atIndex:(int)index;
- (void) remove:(CFXAnnotationObject*)annObj;

@end

@interface CFXAnnotations : NSObject 
{
}

@property (nonatomic, retain, readonly) CFXAnnotationList* list;
+(NSString*)version;

@end

