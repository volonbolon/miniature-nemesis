@class CFXAxis, CFXCustomGridLineCollection, CFXLabelCollection, CFXAxisSectionCollection, CFXPane, CFXAxisYCollection, CFXChart, CFXGetTipEventArgs, CFXCompactFormulaHandler, CFXAxisLabelEventArgs, CFXHitTestEventArgs, CFXPointLabelEventArgs, CFXConditionalAttributesEventArgs;

typedef NS_ENUM(NSInteger, CFXDashStyle) 
{
    CFXDashStyleSolid = 0,
	CFXDashStyleDash = 1,
    CFXDashStyleDot = 2,
	CFXDashStyleDashDot = 3,
    CFXDashStyleCustom = 5,
};

typedef NS_ENUM(NSInteger, CFXStringAlignment) 
{
    CFXStringAlignmentNear = 0,
    CFXStringAlignmentCenter = 1,
    CFXStringAlignmentFar = 2,
};

typedef NS_ENUM(NSInteger, CFXLineCap) 
{
    CFXLineCapFlat = 0,
};

typedef NS_ENUM(NSInteger, CFXFontStyle) 
{
    CFXFontStyleRegular = 0,
    CFXFontStyleBold = 1,
    CFXFontStyleItalic = 2,
    CFXFontStyleUnderline = 4,
    CFXFontStyleStrikeout = 8,
};

typedef NS_ENUM(NSInteger, CFXStringTrimming) 
{
    CFXStringTrimmingNone = 0,
};

typedef NS_ENUM(NSInteger, CFXHatchStyle) 
{
    CFXHatchStyleBackwardDiagonal = 3,
    CFXHatchStylePercent50 = 12,
};

typedef NS_ENUM(NSInteger, CFXAnchorStyles) 
{
    CFXAnchorStylesNone = 0,
    CFXAnchorStylesTop = 1,
    CFXAnchorStylesBottom = 2,
    CFXAnchorStylesLeft = 4,
    CFXAnchorStylesRight = 8,
};

@protocol CFXChartDelegate <NSObject>
@optional
- (void) chart:(CFXChart*)chart getTipForElement:(CFXGetTipEventArgs*)args;
- (void) chart:(CFXChart*)chart getLabelForAxis:(CFXAxisLabelEventArgs*)args;
- (void) chart:(CFXChart*)chart didSelectElement:(CFXHitTestEventArgs*)args;
- (void) chart:(CFXChart*)chart getLabelForPoint:(CFXPointLabelEventArgs*)args;
- (void) chart:(CFXChart*)chart applyConditionalAttributes:(CFXConditionalAttributesEventArgs*)args;
@end

@protocol CFXChartDataSource <NSObject>
@required
- (int) numberOfObjectsInChart:(CFXChart*)chart;
- (id) chart:(CFXChart*)chart objectAtIndex:(int)index;
@end

typedef NS_ENUM(NSInteger, CFXAnimationDelay) 
{
    CFXAnimationDelayAuto = 0,
    CFXAnimationDelayNone = 4096,
    CFXAnimationDelayPerPoint = 1,
    CFXAnimationDelayPerSeries = 2,
    CFXAnimationDelayPerPointInverse = 17,
    CFXAnimationDelayPerSeriesInverse = 18,
    CFXAnimationDelayPerPointRandom = 33,
    CFXAnimationDelayPerSeriesRandom = 34,
    CFXAnimationDelayPerPointSeries = 3,
    CFXAnimationDelayPerPointSeriesRandom = 35
};

typedef NS_ENUM(NSInteger, CFXAnimationDirection) 
{
    CFXAnimationDirectionAuto = 0,
    CFXAnimationDirectionUpward = 1,
    CFXAnimationDirectionDownward = 2,
    CFXAnimationDirectionFromCenter = 3
};

typedef NS_ENUM(NSInteger, CFXAnimationTiming) 
{
    CFXAnimationTimingAuto = 0,
    CFXAnimationTimingLinear = 1,
    CFXAnimationTimingEaseIn = 2,
    CFXAnimationTimingEaseOut = 3,
    CFXAnimationTimingEaseInEaseOut = 4,
    CFXAnimationTimingEaseOutBounce = 5
};

typedef NS_ENUM(NSInteger, CFXAxesStyle) 
{
    CFXAxesStyleNone = 0,
    CFXAxesStyleMath = 2,
    CFXAxesStyleFlatFrame = 3,
    CFXAxesStyleX = 4,
    CFXAxesStyleY = 5
};

typedef NS_ENUM(NSInteger, CFXAxisFormat) 
{
    CFXAxisFormatNone = 0,
    CFXAxisFormatNumber = 1,
    CFXAxisFormatCurrency = 2,
    CFXAxisFormatScientific = 3,
    CFXAxisFormatPercentage = 4,
    CFXAxisFormatDate = 5,
    CFXAxisFormatLongDate = 6,
    CFXAxisFormatTime = 7,
    CFXAxisFormatDateTime = 8
};

typedef NS_ENUM(NSInteger, CFXAxisPosition) 
{
    CFXAxisPositionNear = 0,
    CFXAxisPositionFar = 2
};

typedef NS_ENUM(NSInteger, CFXAxisStyles) 
{
    CFXAxisStylesHideText = 1,
    CFXAxisStylesNotify = 2,
    CFXAxisStylesShow2Levels = 4,
    CFXAxisStylesSingleLine = 8,
    CFXAxisStylesAutoScaleUnit = 16,
    CFXAxisStylesBreakZero = 32,
    CFXAxisStylesHide = 64,
    CFXAxisStylesNotClipped = 128,
    CFXAxisStylesClientScroll = 256,
    CFXAxisStylesCentered = 512,
    CFXAxisStylesRotateText = 1024,
    CFXAxisStylesLongTick = 2048,
    CFXAxisStylesAutoScale = 4096,
    CFXAxisStylesForceZero = 8192,
    CFXAxisStylesShowEnds = 16384,
    CFXAxisStylesRoundStep = 32768,
    CFXAxisStylesIgnoreLabels = 65536,
    CFXAxisStylesGridFront = 131072,
    CFXAxisStylesInverted = 262144,
    CFXAxisStylesDetectArea = 524288,
    CFXAxisStylesShowIntermediateLogLabels = 1048576,
    CFXAxisStylesAutoMinorStep = 2097152,
    CFXAxisStylesAutoFirstLabel = 4194304,
    CFXAxisStylesAutoCenter = 8388608,
    CFXAxisStylesInside = 16777216,
    CFXAxisStylesAutoLabelLayout = 33554432,
    CFXAxisStylesAllowHalf = 67108864,
    CFXAxisStylesLeftAligned = 268435456,
    CFXAxisStylesDoNotReset = 536870912,
    CFXAxisStylesAutoDecimals = 1073741824,
    CFXAxisStylesDefault = 1323874360
};

typedef NS_ENUM(NSInteger, CFXBarAnimation) 
{
    CFXBarAnimationValue = 0,
    CFXBarAnimationDrop = 1
};

typedef NS_ENUM(NSInteger, CFXBarShape) 
{
    CFXBarShapeRectangle = 0,
    CFXBarShapeCylinder = 1,
    CFXBarShapeCone = 2,
    CFXBarShapePyramid = 3
};

typedef NS_ENUM(NSInteger, CFXBorderEffect) 
{
    CFXBorderEffectNone = 0,
    CFXBorderEffectRaised = 1,
    CFXBorderEffectLight = 2,
    CFXBorderEffectDark = 3,
    CFXBorderEffectOpposite = 4,
    CFXBorderEffectShadow = 5
};

typedef NS_ENUM(NSInteger, CFXBubbleAnimation) 
{
    CFXBubbleAnimationPosition = 0,
    CFXBubbleAnimationSize = 1,
    CFXBubbleAnimationPositionAndSize = 2
};

typedef NS_ENUM(NSInteger, CFXChartStyles) 
{
    CFXChartStylesDoubleBuffer = 2,
    CFXChartStylesNoLegInvalidate = 8,
    CFXChartStylesOnlyChart = 64,
    CFXChartStylesSideBySide = 256,
    CFXChartStylesMonochrome = 512,
    CFXChartStylesFastLegends = 32768,
    CFXChartStylesScrollBars = 524288,
    CFXChartStylesAllowScroll = 1048576,
    CFXChartStylesForceDataDriven = 2097152,
    CFXChartStylesPaintNoChart = 536870912,
    CFXChartStylesHideZLabels = 1073741824,
    CFXChartStylesDefault = 1852418
};

typedef NS_ENUM(NSInteger, CFXConditionSpecialValue) 
{
    CFXConditionSpecialValueNone = 0,
    CFXConditionSpecialValueFirst = 1,
    CFXConditionSpecialValueLast = 2,
    CFXConditionSpecialValueMin = 3,
    CFXConditionSpecialValueMax = 4
};

typedef NS_ENUM(NSInteger, CFXConditionUnit) 
{
    CFXConditionUnitPercentage = 1
};

typedef NS_ENUM(NSInteger, CFXContentLayout) 
{
    CFXContentLayoutSpread = 0,
    CFXContentLayoutNear = 1,
    CFXContentLayoutCenter = 2,
    CFXContentLayoutFar = 3
};

typedef NS_ENUM(NSInteger, CFXCustomGridLineStyles) 
{
    CFXCustomGridLineStylesHideText = 1,
    CFXCustomGridLineStylesHide = 2,
    CFXCustomGridLineStylesBackOnly = 8,
    CFXCustomGridLineStylesColorText = 16,
    CFXCustomGridLineStylesHideLine = 32,
    CFXCustomGridLineStylesOutsideText = 64,
    CFXCustomGridLineStylesShowValue = 128
};

typedef NS_ENUM(NSInteger, CFXDataSourceStyles) 
{
    CFXDataSourceStylesKeepScale = 8,
    CFXDataSourceStylesTranspose = 16,
    CFXDataSourceStylesKeepSeriesLegend = 64,
    CFXDataSourceStylesKeepLabels = 128,
    CFXDataSourceStylesReadXValues = 512,
    CFXDataSourceStylesReadYFromValues = 1024,
    CFXDataSourceStylesDatesAsLabels = 2048,
    CFXDataSourceStylesRewindBeforeReading = 4096,
    CFXDataSourceStylesDataChange = 8192,
    CFXDataSourceStylesDefault = 4096
};

typedef NS_ENUM(NSInteger, CFXDockArea) 
{
    CFXDockAreaLeft = 0,
    CFXDockAreaTop = 1,
    CFXDockAreaRight = 2,
    CFXDockAreaBottom = 3
};

typedef NS_ENUM(NSInteger, CFXDockBorder) 
{
    CFXDockBorderNone = 0,
    CFXDockBorderInternal = 2
};

typedef NS_ENUM(NSInteger, CFXExplodingMode) 
{
    CFXExplodingModeNone = 0,
    CFXExplodingModeAll = 1,
    CFXExplodingModeFirst = 2,
    CFXExplodingModeLast = 3
};

typedef NS_ENUM(NSInteger, CFXFieldUsage) 
{
    CFXFieldUsageDefault = 0,
    CFXFieldUsageLabel = 1,
    CFXFieldUsageValue = 2,
    CFXFieldUsageXValue = 3,
    CFXFieldUsageFromValue = 5,
    CFXFieldUsageKeyLabel = 4,
    CFXFieldUsageColumnHeading = 6,
    CFXFieldUsageRowHeading = 7,
    CFXFieldUsageNotUsed = 8
};

typedef NS_ENUM(NSInteger, CFXFillMode) 
{
    CFXFillModeSolid = 0,
    CFXFillModeMonochrome = 1,
    CFXFillModePattern = 2,
    CFXFillModeGradient = 3
};

typedef NS_ENUM(NSInteger, CFXGallery) 
{
    CFXGalleryLines = 1,
    CFXGalleryBar = 2,
    CFXGalleryArea = 3,
    CFXGalleryScatter = 4,
    CFXGalleryPie = 5,
    CFXGalleryStep = 8,
    CFXGalleryHighLowClose = 9,
    CFXGalleryRadar = 11,
    CFXGalleryCube = 12,
    CFXGalleryBubble = 15,
    CFXGalleryOpenHighLowClose = 16,
    CFXGalleryCandlestick = 17,
    CFXGalleryGantt = 20,
    CFXGalleryCurve = 6,
    CFXGalleryPareto = 7,
    CFXGallerySurface = 10,
    CFXGalleryDoughnut = 13,
    CFXGalleryPyramid = 14,
    CFXGalleryContour = 18,
    CFXGalleryCurveArea = 19
};

typedef NS_ENUM(NSInteger, CFXHighlightState) 
{
    CFXHighlightStateNever = -3,
    CFXHighlightStateAlways = -2,
    CFXHighlightStateNormal = 0
};

typedef NS_ENUM(NSInteger, CFXHighLowClose) 
{
    CFXHighLowCloseLow = 0,
    CFXHighLowCloseClose = 1,
    CFXHighLowCloseHigh = 2
};

typedef NS_ENUM(NSInteger, CFXHitType) 
{
    CFXHitTypeNone = 0,
    CFXHitTypeBackground = 1,
    CFXHitTypeInsideArea = 2,
    CFXHitTypeBetween = 3,
    CFXHitTypePoint = 4,
    CFXHitTypeAxis = 5,
    CFXHitTypeTitle = 6,
    CFXHitTypeCustomGridLine = 7,
    CFXHitTypeCrosshair = 9,
    CFXHitTypeZoom = 10,
    CFXHitTypeOther = 14,
    CFXHitTypeAxisSection = 15
};

typedef NS_ENUM(NSInteger, CFXInterlaced) 
{
    CFXInterlacedNone = 0,
    CFXInterlacedHorizontal = 1,
    CFXInterlacedVertical = 2
};

typedef NS_ENUM(NSInteger, CFXLegendBoxStyles) 
{
    CFXLegendBoxStylesWordbreak = 1,
    CFXLegendBoxStylesShowMenu = 4,
    CFXLegendBoxStylesRightAlign = 16,
    CFXLegendBoxStylesNoColor = 32,
    CFXLegendBoxStylesHidePartial = 64
};

typedef NS_ENUM(NSInteger, CFXLineAnimation) 
{
    CFXLineAnimationDrawX = 0,
    CFXLineAnimationYData = 1,
    CFXLineAnimationYProgress = 2
};

typedef NS_ENUM(NSInteger, CFXMarkerShape) 
{
    CFXMarkerShapeNone = 0,
    CFXMarkerShapeRect = 1,
    CFXMarkerShapeCircle = 2,
    CFXMarkerShapeTriangle = 3,
    CFXMarkerShapeDiamond = 4,
    CFXMarkerShapeMarble = 5,
    CFXMarkerShapeHorizontalLine = 6,
    CFXMarkerShapeVerticalLine = 7,
    CFXMarkerShapeCross = 8,
    CFXMarkerShapeInvertedTriangle = 9,
    CFXMarkerShapeX = 10,
    CFXMarkerShapePicture = 11,
    CFXMarkerShapeMany = 12
};

typedef NS_ENUM(NSInteger, CFXMarkerStyle) 
{
    CFXMarkerStyleFilled = 0,
    CFXMarkerStyleHollow = 1
};

typedef NS_ENUM(NSInteger, CFXOpenHighLowClose) 
{
    CFXOpenHighLowCloseLow = 0,
    CFXOpenHighLowCloseOpen = 1,
    CFXOpenHighLowCloseClose = 2,
    CFXOpenHighLowCloseHigh = 3
};

typedef NS_ENUM(NSInteger, CFXPieAnimation) 
{
    CFXPieAnimationRadial = 1,
    CFXPieAnimationAngle = 2,
    CFXPieAnimationRadialAndAngle = 3,
    CFXPieAnimationAngleFromTop = 258,
    CFXPieAnimationRadialAngleFromTop = 259
};

typedef NS_ENUM(NSInteger, CFXRandomDataStyles) 
{
    CFXRandomDataStylesNone = 0,
    CFXRandomDataStylesXValues = 1,
    CFXRandomDataStylesFromValues = 2,
    CFXRandomDataStylesNegativeValues = 4,
    CFXRandomDataStylesLabels = 8,
    CFXRandomDataStylesDisabled = 16
};

typedef NS_ENUM(NSInteger, CFXRealTimeAction) 
{
    CFXRealTimeActionAppend = 0
};

typedef NS_ENUM(NSInteger, CFXRealTimeMode) 
{
    CFXRealTimeModeLoop = 1
};

typedef NS_ENUM(NSInteger, CFXShadow) 
{
    CFXShadowNone = 0,
    CFXShadowFixed = 1
};

typedef NS_ENUM(NSInteger, CFXStacked) 
{
    CFXStackedNo = 0,
    CFXStackedNormal = 1,
    CFXStackedStacked100 = 2
};

typedef NS_ENUM(NSInteger, CFXTickMark) 
{
    CFXTickMarkNone = 0,
    CFXTickMarkOutside = 1,
    CFXTickMarkInside = 2,
    CFXTickMarkCross = 3
};

typedef NS_ENUM(NSInteger, CFXGradientType) 
{
    CFXGradientTypeHorizontal = 0,
    CFXGradientTypeVertical = 1,
    CFXGradientTypeBackwardDiagonal = 2,
    CFXGradientTypeForwardDiagonal = 3,
    CFXGradientTypeRadial = 4,
    CFXGradientTypeAngled = 5
};

typedef NS_ENUM(NSInteger, CFXDataElement) 
{
    CFXDataElementYValue = 0,
    CFXDataElementXValue = 1,
    CFXDataElementIniValue = 2
};

@protocol CFXIDataArray <NSObject>
@required
    // Sets the Data Compacting Formula.
    @property (nonatomic, retain) CFXCompactFormulaHandler* compactFormula;
    // Returns false if this collection contains no elements.
    @property (nonatomic, assign, readonly) BOOL hasData;
    // If true, means the value is shared for all series.
    @property (nonatomic, assign) BOOL shared;
    - (double) valueForPoint:(int)point;
    - (void) setValue:(double)value forPoint:(int)point;
    - (double) valueForSeries:(int)series andPoint:(int)point;
    - (void) setValue:(double)value forSeries:(int)series andPoint:(int)point;
    - (void) clear;
@end

@protocol CFXILegendBoxItem <NSObject>
@end

@protocol CFXILegendBoxItemCollection <CFXILegendBoxItem>
@end

@protocol CFXIAdornment <NSObject>
@end

@protocol CFXIBackgroundAdornment <CFXIAdornment>
@end

@protocol CFXIBorderAdornment <NSObject>
@end

@protocol CFXICondition <NSObject>
@end

@interface CFXAttributes3D : NSObject 
{
}

// Gets or Sets the 3D rotation angle around the X-axis.
@property (nonatomic, assign) int angleX;
// Gets or Sets a 3D rotation angle around the Y-axis.
@property (nonatomic, assign) int angleY;
// Gets or Sets the thickness for the box surrounding the chart.
@property (nonatomic, assign) int boxThickness;
// Displays a z-clustered 3D chart.When set to True, the chart will show as clustered; when set to False, the chart displays the series side-by-side. 
@property (nonatomic, assign) BOOL cluster;
// Gets or Sets the thickness along the Z-axis for the series.
@property (nonatomic, assign) int depth;
// Gets or Sets a value indicating whether 3D effects should be applied.
@property (nonatomic, assign) BOOL enabled;
// Allows you to set a 3D perspective to control the view of the chart depth. 
@property (nonatomic, assign) int perspective;
// Gets or Sets a value indicating the chart is Rotated.
@property (nonatomic, assign) BOOL rotated;
// Gets or Sets a value indicating the type of shading to display when rotating the chart.
@property (nonatomic, assign) CFXShadow shadow;

@end

@interface CFXMargins : NSObject 
{
}

// Gets or Sets the distance in pixels between the bottom border of the bounding rectangle and the bottom border of the plot area of the chart.  
@property (nonatomic, assign) int bottom;
// Gets or Sets the distance in pixels between the left border of the bounding rectangle and the left border of the plot area of the chart.  
@property (nonatomic, assign) int left;
// Gets or Sets the distance in pixels between the right border of the bounding rectangle and the right border of the plot area of the chart.  
@property (nonatomic, assign) int right;
// Gets or Sets the distance in pixels between the top border of the bounding rectangle and the top border of the plot area of the chart.  
@property (nonatomic, assign) int top;

@end

@interface CFXFieldMap : NSObject 
{
}

// Gets or sets the name of the field which will be displayed by the Chart.
@property (nonatomic, retain) NSString* displayName;
// Gets or sets the name of the ResultSet's field related to the FieldMap. 
@property (nonatomic, retain) NSString* name;
// Gets or sets the usage of the related column of the ResultSet.
@property (nonatomic, assign) CFXFieldUsage usage;

@end

@interface CFXFieldMapCollection : NSObject 
{
}

@property (nonatomic, assign, readonly) int count;
- (CFXFieldMap*) objectAtIndex:(int)n;
- (void) replaceObjectAtIndex:(int)n withObject:(CFXFieldMap*)object;
- (void) add:(CFXFieldMap*)item;
- (void) clear;
- (BOOL) contains:(CFXFieldMap*)item;
- (int) indexOf:(CFXFieldMap*)obj;
- (void) insertObject:(CFXFieldMap*)item atIndex:(int)index;
- (void) remove:(CFXFieldMap*)item;
- (void) removeAt:(int)index;
- (CFXFieldMap*)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)setObject:(CFXFieldMap*)obj atIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXDataSourceSettings : NSObject 
{
}

// Gets or Sets the source containing the values used to populate the chart.
@property (nonatomic, retain) id dataSource;
//  Returns a collection of FieldMap objects. Those objects allows you to configure how ChartFX will store the data provided by the DataProvider.
@property (nonatomic, retain, readonly) CFXFieldMapCollection* fields;
// Gets or Sets a value defining the label separator character used when concatenating labels.
@property (nonatomic, retain) NSString* labelSeparator;
// Controls how Chart FX plots the fields in the resultset.
@property (nonatomic, assign) CFXDataSourceStyles style;
- (void) reloadData;

@end

@interface CFXRequiresAmbientCollection : NSObject <NSFastEnumeration>
{
}

@property (nonatomic, assign, readonly) int count;
- (void) clear;
- (BOOL) contains:(id)item;
- (int) indexOf:(id)obj;
- (void) removeAt:(int)index;
-(NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id *)stackbuf count:(NSUInteger)len;

@end

@interface CFXTitle : NSObject 
{
}

// Allows you to set the alignment of the specified title.
@property (nonatomic, assign) CFXStringAlignment alignment;
// Specifies the space in pixels to the front and back of the selected title when read from top to bottom.
@property (nonatomic, assign) int indentation;
// Gets or sets the vertical alignment for the lines of the chart title.
@property (nonatomic, assign) CFXStringAlignment lineAlignment;
// Specifies the space in pixels above and below the selected title text when read from right to left.
@property (nonatomic, assign) int separation;
// Gets or sets the text for the selected title.
@property (nonatomic, retain) NSString* text;
@property (nonatomic, retain) UIColor* backColor;
@property (nonatomic, retain) UIFont* font;
@property (nonatomic, retain) UIColor* textColor;

@end

@interface CFXTitleDockable : CFXTitle 
{
}

// Sets or Gets the Dock property, which sets the position where the title will be docked.
@property (nonatomic, assign) CFXDockArea dock;
// Gets or sets a value indicating whether the title may use the entire length of the chart, or only above the plot area.
@property (nonatomic, assign) BOOL plotAreaOnly;

@end

@interface CFXTitleCollection : CFXRequiresAmbientCollection 
{
}

- (CFXTitleDockable*) objectAtIndex:(int)index;
- (void) add:(CFXTitleDockable*)title;
- (void) insertObject:(CFXTitleDockable*)title atIndex:(int)index;
- (CFXTitleDockable*)objectAtIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXLine : NSObject 
{
}

@property (nonatomic, assign) CFXLineCap endCap;
@property (nonatomic, assign) CFXLineCap startCap;
@property (nonatomic, assign) CFXDashStyle style;
@property (nonatomic, assign) int width;
@property (nonatomic, retain) UIColor* color;

@end

@interface CFXCustomGridLine : CFXLine <CFXILegendBoxItem>
{
}

// Gets or Sets the Alignment for the Label in a CustomGridLine.
@property (nonatomic, assign) CFXStringAlignment alignment;
@property (nonatomic, retain) CFXAxis* axis;
// Allows you to set additional visual attributes in a custom grid line.
@property (nonatomic, assign) CFXCustomGridLineStyles extraStyle;
@property (nonatomic, assign) double from;
// Gets or Sets the alignment for the Text line relative to the CustomeGridLine.
@property (nonatomic, assign) CFXStringAlignment lineAlignment;
@property (nonatomic, assign) int margin;
// Gets or Set the OutsideText which controls the positioning of the CustomGridLine label outside the chart area.
@property (nonatomic, assign) BOOL outsideText;
// Gets or Set the ShowLine, which shows or hides the CustomGridLine line.
@property (nonatomic, assign) BOOL showLine;
// Gets or Set the Showtext, which shows or hides the CustomGridLine text.
@property (nonatomic, assign) BOOL showText;
// Gets or Sets the Text for a label in a CustomGridLine.
@property (nonatomic, retain) NSString* text;
@property (nonatomic, assign) double to;
// Gets or Sets the Value for a CustomGridLine.
@property (nonatomic, assign) double value;
@property (nonatomic, retain) UIFont* font;
@property (nonatomic, retain) UIColor* textColor;

@end

@interface CFXGridLine : CFXLine 
{
}

@property (nonatomic, assign) int margin;
// Gets or sets the style for the tick marks of an GridLine object.
@property (nonatomic, assign) CFXTickMark tickMark;
// Gets or sets a value indicating whether the grid line for the selected Gridline will be visible.
@property (nonatomic, assign) BOOL visible;

@end

@interface CFXGrids : NSObject 
{
}

// Creates a grid of alternating colors for a selected axis to improve chart readability.
@property (nonatomic, assign) BOOL interlaced;
// Provides access to the GridLine class to customize the Mayor Grid.
@property (nonatomic, retain, readonly) CFXGridLine* major;
// Provides access to the GridLine class to customize the Minor Grid.
@property (nonatomic, retain, readonly) CFXGridLine* minor;
// Gets or sets the AlternateColor for a selected Grids object.
@property (nonatomic, retain) UIColor* interlacedColor;

@end

@interface CFXAxisSectionBase : NSObject 
{
}

// Allows customization of grid lines by providing access to the supported members of the Grids class.
@property (nonatomic, retain, readonly) CFXGrids* grids;
@property (nonatomic, retain) UIColor* textColor;

@end

@interface CFXAxisSection : CFXAxisSectionBase <CFXILegendBoxItem>
{
}

@property (nonatomic, retain) CFXAxis* axis;
@property (nonatomic, assign) CFXFontStyle fontStyle;
// Gets or sets a value indicating the beginning value of the range for a selected AxisSection object.
@property (nonatomic, assign) double from;
// Gets or Sets the text string for a selected BaseAxisSection object.
@property (nonatomic, retain) NSString* text;
// Gets or sets a value indicating the ending value of the range for a selected AxisSection object.
@property (nonatomic, assign) double to;
// Shows or hides the selected axis section.
@property (nonatomic, assign) BOOL visible;
@property (nonatomic, retain) UIColor* backColor;

@end

@interface CFXValueFormat : NSObject 
{
}

// Gets or sets a custom format to the selected label, mouseover tip or value.
@property (nonatomic, retain) NSString* customFormat;
// Gets or sets the number of decimals for the selected label, mouseover tip or value.
@property (nonatomic, assign) int decimals;
// Used to format the selected label, mouseover tip or value to numbers, date, time, scientific or currency.
@property (nonatomic, assign) CFXAxisFormat format;
// Returns a value indicating whether or not a value is a Date.
@property (nonatomic, assign, readonly) BOOL isDate;
// Returns a value indicating whether or not a value is a DateTime.
@property (nonatomic, assign, readonly) BOOL isDateTime;
// Returns a value indicating whether or not a value is a Percentage.
@property (nonatomic, assign, readonly) BOOL isPercentage;
// Returns a value indicating whether or not a value is a Time.
@property (nonatomic, assign, readonly) BOOL isTime;
@property (nonatomic, retain) NSString* culture;

@end

@interface CFXAxis : CFXAxisSectionBase <CFXILegendBoxItemCollection,CFXILegendBoxItem>
{
}

// Instructs Chart FX to always recalculate the specified Axis scale values (Min, Max) when new values are set to the chart.
@property (nonatomic, assign) BOOL autoScale;
// Enables or disables scrolling in an Axis.
@property (nonatomic, assign) BOOL autoScroll;
// Gets the collection of CustomGridLines that belong to the Chart.
@property (nonatomic, retain, readonly) CFXCustomGridLineCollection* customGridLines;
// Used to format the data displayed on point labels, and tool tips shown at mouseover.
@property (nonatomic, retain, readonly) CFXValueFormat* dataFormat;
// Gets or sets a value used to customize the first label displayed on a selected axis.
@property (nonatomic, assign) int firstLabel;
// Used to set the minimum value of a numerical axis to zero even if the data minimum value does not start at zero.
@property (nonatomic, assign) BOOL forceZero;
// Returns a boolean value specifying whether the selected axis is a horizontal or vertical axis.
@property (nonatomic, assign, readonly) BOOL horizontal;
// Sets a selected numerical axis max value lesser than the min value.
@property (nonatomic, assign) BOOL inverted;
// Used to assign a key (short) legend to tickmarks in a categorical axis.
@property (nonatomic, retain, readonly) CFXLabelCollection* keyLabels;
// Sets the text rotation for the labels in the selected axis.
@property (nonatomic, assign) short labelAngle;
// Allows you to get or set the tick mark labels for the selected axis.
@property (nonatomic, retain, readonly) CFXLabelCollection* labels;
// Used to format the labels displayed on the selected axis.
@property (nonatomic, retain, readonly) CFXValueFormat* labelsFormat;
@property (nonatomic, assign) CFXStringTrimming labelTrimming;
// Allows you to set and associate text labels to major tick marks in a numerical axis.This property can get or set the LabelValue assigned to any of the axes.
@property (nonatomic, assign) double labelValue;
// Allows you to apply supported Line class members to a selected axis line.
@property (nonatomic, retain, readonly) CFXLine* line;
// Gets or sets a value indicating the LineSpacing for an axis.
@property (nonatomic, assign) double lineSpacing;
// Used to set a logarithmic scale for a numerical axis and recalculate the values as powers equal to the setting of this property.
@property (nonatomic, assign) double logBase;
// Gets or sets the Max value assigned to the specified axis.
@property (nonatomic, assign) double max;
// Allows you to specify the maximum percentage of the chart area the AxisX labels may occupy.
@property (nonatomic, assign) int maxSizePercentage;
// Gets or sets the Min value assigned to the specified axis.
@property (nonatomic, assign) double min;
// Specifies the increment you want between minor tick marks and minor gridlines (if they are displayed) on the selected axis.
@property (nonatomic, assign) double minorStep;
// Used to enable or disable the GetAxisLabel event so you can customize labels on the specified axis.
@property (nonatomic, assign) BOOL notify;
// Gives you the ability to control how many pixels per unit are in the selected axis. This property is very useful if you want a scroll bar in the selected axis.
@property (nonatomic, assign) double pixelsPerUnit;
// Specifies the placement of the axis labels and tick marks relative to the chart.
@property (nonatomic, assign) CFXAxisPosition position;
// Returns or sets the scale unit of a selected axis. 
@property (nonatomic, assign) double scaleUnit;
// Allows you to set the starting scroll position when a chart is scrollable.
@property (nonatomic, assign) int scrollPosition;
// Returns the number of scrolls in a chart based on the scroll view configuration.
@property (nonatomic, assign, readonly) int scrollSize;
// Returns a selected AxisSection object.
@property (nonatomic, retain, readonly) CFXAxisSectionCollection* sections;
// Allows you to specify a gap in pixels between multiple axis.
@property (nonatomic, assign) int separation;
// Alternates the level of the axis labels for the selected axis.
@property (nonatomic, assign) BOOL staggered;
// Specifies the interval of major tick marks and gridlines on the selected axis.It also controls the gap or interval between labels in the selected axis.
@property (nonatomic, assign) double step;
// Allows you to add additional styles to the selected axis.   
@property (nonatomic, assign) CFXAxisStyles style;
// Gets or sets the title for a specific axis.
@property (nonatomic, retain) CFXTitle* title;
// Shows or hides the lines, labels, tick marks and grids for the selected axis.
@property (nonatomic, assign) BOOL visible;
@property (nonatomic, retain) UIFont* font;
- (void) adjustScale;
- (int) distanceToPixel:(double)distance;
// Used to retrieve values set by the SetScrollView method.
- (void) scrollViewMin:(double*)min andMax:(double*)max;
// Converts a position in pixels in the chart area to its representation on the respective axis.
- (double) pixelToValue:(int)pixel;
- (void) resetScale;
// Creates a scroll bar to view a portion of the selected axis.
- (void) setScrollViewMin:(double)min andMax:(double)max;
// Converts a value to its position in pixels on a selected axis.
- (int) valueToPixel:(double)value;

@end


@interface CFXAxisX : CFXAxis 
{
}


@end

@interface CFXAxisY : CFXAxis 
{
}

// Gets or sets an integer value specifying the Pane for a Y Axis object.
@property (nonatomic, retain, readonly) CFXPane* pane;

@end

@interface CFXPane : NSObject 
{
}

// Provides access to the Y Axis Collection for the selected Pane.
@property (nonatomic, retain, readonly) CFXAxisYCollection* axes;
// Provides access to the members of the main Y Axis for the selected Pane.
@property (nonatomic, retain, readonly) CFXAxisY* axisY;
// Gets or sets an ImageBackground or GradientBackground object for a pane.
@property (nonatomic, retain) id<CFXIAdornment> background;
// Gets or sets a value indicating the proportional size of the selected pane.
@property (nonatomic, assign) double proportion;
// Gets or sets a value indicating the space between panes.
@property (nonatomic, assign) int separation;
// Gets the Title object for a selected pane.
@property (nonatomic, retain) CFXTitle* title;
// Gets or Sets a value indicating if the Pane object should be shown or not.
@property (nonatomic, assign) BOOL visible;
@property (nonatomic, retain) UIColor* backColor;

@end

@interface CFXPaneCollection : CFXRequiresAmbientCollection 
{
}

- (CFXPane*) objectAtIndex:(int)index;
- (void) add:(CFXPane*)pane;
- (void) clear;
- (void) insertObject:(CFXPane*)pane atIndex:(int)index;
- (void) remove:(CFXPane*)pane;
- (void) removeAt:(int)index;
- (CFXPane*)objectAtIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXAxisCollection : CFXRequiresAmbientCollection 
{
}

- (void) clear;
- (void) removeAt:(int)index;

@end

@interface CFXAxisYCollection : CFXAxisCollection 
{
}

- (CFXAxisY*) objectAtIndex:(int)index;
- (void) replaceObjectAtIndex:(int)index withObject:(CFXAxisY*)object;
- (void) add:(CFXAxisY*)item;
- (void) insertObject:(CFXAxisY*)item atIndex:(int)index;
- (void) remove:(CFXAxisY*)item;
- (CFXAxisY*)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)setObject:(CFXAxisY*)obj atIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXAxisXCollection : CFXAxisCollection 
{
}

- (CFXAxisX*) objectAtIndex:(int)index;
- (void) replaceObjectAtIndex:(int)index withObject:(CFXAxisX*)object;
- (void) add:(CFXAxisX*)item;
- (void) insertObject:(CFXAxisX*)item atIndex:(int)index;
- (void) remove:(CFXAxisX*)item;
- (CFXAxisX*)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)setObject:(CFXAxisX*)obj atIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXLabelAwareCollection : CFXRequiresAmbientCollection 
{
}

- (void) clear;
- (void) removeAt:(int)index;

@end

@interface CFXBorderAttributes : NSObject 
{
}

// Gets or Sets a property which makes the border to be shown between segments.
@property (nonatomic, assign) BOOL betweenSegments;
// Gets or Sets the BorderEffect for the border of a point marker.
@property (nonatomic, assign) CFXBorderEffect effect;
// Represents the style of the line for the border of a point marker.
@property (nonatomic, assign) CFXDashStyle style;
// Gets or sets a property which applies the Border Attributes to the lines of a Line Chart.
@property (nonatomic, assign) BOOL useForLines;
// Gets or Sets a value making the border visible or not.
@property (nonatomic, assign) BOOL visible;
// Gets or Sets a value in pixels.
@property (nonatomic, assign) short width;
// Gets or Sets the color of the border of a point marker.
@property (nonatomic, retain) UIColor* color;

@end

@interface CFXLineAttributes : NSObject 
{
}

// Gets or Sets a marker shape at the end of a PointAttribute's Line.
@property (nonatomic, assign) CFXLineCap endCap;
// Gets or Sets a marker shape at the start of a PointAttribute's Line.
@property (nonatomic, assign) CFXLineCap startCap;
// Gets or Sets the style for a PointAttribute's Line.
@property (nonatomic, assign) CFXDashStyle style;
// Gets or Sets the width for a PointAttribute's Line.
@property (nonatomic, assign) short width;

@end

@interface CFXPointLabelAttributes : NSObject 
{
}

// Gets or Sets the vertical alignment for the point label.
@property (nonatomic, assign) CFXStringAlignment alignment;
// Gets or Sets the angle of the point label.
@property (nonatomic, assign) short angle;
// Gets or Sets the backgrond color of the point label.
@property (nonatomic, retain) UIColor* backColor;
// Gets or Sets the border color of the point label.
@property (nonatomic, retain) UIColor* borderColor;
// Gets or Sets a value indicating the width of the border surrounding the point label.
@property (nonatomic, assign) short borderWidth;
// Gets or Sets a string pattern mask used to format the label.
@property (nonatomic, retain) NSString* format;
// Gets or Sets the horizontal alignment for the point label.
@property (nonatomic, assign) CFXStringAlignment lineAlignment;
// Gets or Sets a value indicating if point label should be displayed or not.
@property (nonatomic, assign) BOOL visible;
// Gets or Sets a Font object to use as rendering font for the point label.
@property (nonatomic, retain) UIFont* font;
// Gets or Sets a value for the point label color.
@property (nonatomic, retain) UIColor* textColor;

@end

@interface CFXPointAttributes : NSObject 
{
}

// Gets or Sets the Shape for the Bars.
@property (nonatomic, assign) CFXBarShape barShape;
// Provides access to the border attributes object.
@property (nonatomic, retain, readonly) CFXBorderAttributes* border;
// Gets or Sets a value indicating how Chart FX should fill the area representing the point.
@property (nonatomic, assign) CFXFillMode fillMode;
// Gets the LineAttributes object for the particular point.
@property (nonatomic, retain, readonly) CFXLineAttributes* line;
// Gets or Sets the the type used to paint markers for the selected item.
@property (nonatomic, assign) CFXMarkerShape markerShape;
// Gets or Sets a value controlling the size of the markers for the selected item.     
@property (nonatomic, assign) short markerSize;
// Description goes here
@property (nonatomic, assign) CFXMarkerStyle markerStyle;
@property (nonatomic, assign) int markerWidth;
@property (nonatomic, assign) CFXHatchStyle pattern;
// Provides access to PointLabelAttributes allowing for the manipulation of attributes pertaining to the point label.
@property (nonatomic, retain, readonly) CFXPointLabelAttributes* pointLabels;
// Gets or Sets a value allowing you to separate a slice of a Pie or Doughnut chart for a selected item.
@property (nonatomic, assign) short separateSlice;
// Gets or Sets and object for the specific item.
@property (nonatomic, retain) id tag;
// Gets or Sets a value for labeling the point or series attribute.
@property (nonatomic, retain) NSString* text;
// Gets or Sets a value indicating a volume for a data point markers in supported galleries.  By adjusting the volume, you can modify the amount of space you want between the items.
@property (nonatomic, assign) short volume;
// Gets or Sets the alternate color for a selected item when using gradient FillMode.
@property (nonatomic, retain) UIColor* alternateColor;
// Allows you to set a color for the selected item. 
@property (nonatomic, retain) UIColor* color;
// Gets or Sets a value specifying the picture associated to the selected item.
@property (nonatomic, retain) UIImage* picture;

@end


@interface CFXConditionalAttributes : CFXPointAttributes <CFXILegendBoxItem>
{
}

// Returns a Condition object for the specified ConditionalAttributes object.  
@property (nonatomic, retain) id<CFXICondition> condition;
@property (nonatomic, assign, readonly) int index;
@property (nonatomic, assign) BOOL interpolateColor;
// Gets or Sets a value indicating which series index the ConditionalAttribute will be applied to.
@property (nonatomic, assign) int series;
@property (nonatomic, assign) BOOL visible;

@end

@interface CFXSeriesAttributes : CFXPointAttributes <CFXILegendBoxItem>
{
}

// Gets or Sets a value indicating the AxisX the series is connected to.
@property (nonatomic, retain) CFXAxisX* axisX;
// Gets or Sets a value indicating the AxisY the series is connected to.
@property (nonatomic, retain) CFXAxisY* axisY;
// Gets or Sets a gallery type for a particular series.  All chart types are available in both 2D and 3D modes.    
@property (nonatomic, assign) CFXGallery gallery;
// Description goes here
@property (nonatomic, retain) id galleryAttributes;
// Gets or Sets a wingding font for use as marker shapes.
@property (nonatomic, retain) UIFont* markerFont;
// Controls how frequently point markers are shown in the selected series.  
@property (nonatomic, assign) short markerStep;
// Returns the original position of the item in the SeriesAttributes Collection.
@property (nonatomic, assign) int originalPosition;
// Gets or Sets the Pane which the series belongs to.
@property (nonatomic, retain) CFXPane* pane;
// Gets or Sets a value allowing you to stack the selected series with the previous series to achieve multi-stacked charts.  
@property (nonatomic, assign) BOOL stacked;
// Gets or Sets a value allowing you to show or hide the series.
@property (nonatomic, assign) BOOL visible;
- (void) bringToFront;
- (void) sendToBack;

@end

@interface CFXGlobalAttributes : CFXSeriesAttributes 
{
}

// Gets and sets the chart type for all Series. 
@property (nonatomic, assign) CFXGallery gallery;
// Gets or sets a value specifying to transpose X and Y axes in a chart.
@property (nonatomic, assign) BOOL horizontal;
// Gets and sets the Multiple colors to allow for independently colored data points.  
@property (nonatomic, assign) BOOL multipleColors;
// Gets or sets the Stacked style in the chart. 
@property (nonatomic, assign) CFXStacked stackedStyle;

@end

@interface CFXSeriesAttributesCollection : CFXLabelAwareCollection <CFXILegendBoxItemCollection,CFXILegendBoxItem>
{
}

- (CFXSeriesAttributes*) objectAtIndex:(int)index;
- (void) add:(CFXSeriesAttributes*)series;
- (void) insertObject:(CFXSeriesAttributes*)item atIndex:(int)index;
- (void) remove:(CFXSeriesAttributes*)item;
- (void) removeAt:(int)index;
- (void) resetOrder;
- (CFXSeriesAttributes*)objectAtIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXPointAttributesAwareCollection : CFXLabelAwareCollection <CFXILegendBoxItemCollection,CFXILegendBoxItem>
{
}


@end

@interface CFXCustomLegendItem : NSObject <CFXILegendBoxItem>
{
}

// Gets or Sets the background color of a custom legend item marker when a pattern is configured using the Pattern  property. 
@property (nonatomic, retain) UIColor* alternateColor;
// Gets or Sets the PointAttributes object for the custom legend item.
@property (nonatomic, retain) CFXPointAttributes* attributes;
// Gets a BorderAttributes object allowing you to modify the border properties for this CustomLegendItem.
@property (nonatomic, retain, readonly) CFXBorderAttributes* border;
// Gets or Sets the Color for the marker of the Custom Legend Item.
@property (nonatomic, retain) UIColor* color;
// Represents the shape of the marker.
@property (nonatomic, assign) CFXMarkerShape markerShape;
// Gets or Sets a HatchStyle pattern for the marker of a CustomLegendItem.
@property (nonatomic, assign) CFXHatchStyle pattern;
// Gets or Sets an image to be used as a marker for a CustomLegendItem.
@property (nonatomic, retain) UIImage* picture;
// Gets or Sets a value used to display a line marker for a CustomLegendItem.
@property (nonatomic, assign) BOOL showLine;
// Gets or Sets the text string of the custom legend item.
@property (nonatomic, retain) NSString* text;

@end

@interface CFXCustomLegendItemCollection : CFXPointAttributesAwareCollection 
{
}

- (CFXCustomLegendItem*) objectAtIndex:(int)index;
- (void) add:(CFXCustomLegendItem*)item;
- (BOOL) contains:(CFXCustomLegendItem*)item;
- (int) indexOf:(CFXCustomLegendItem*)item;
- (void) insertObject:(CFXCustomLegendItem*)item atIndex:(int)index;
- (void) remove:(CFXCustomLegendItem*)item;
- (CFXCustomLegendItem*)objectAtIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXConditionalAttributesCollection : CFXPointAttributesAwareCollection 
{
}

@property (nonatomic, assign) BOOL showInLegend;
- (CFXConditionalAttributes*) objectAtIndex:(int)index;
- (void) add:(CFXConditionalAttributes*)item;
- (void) clear;
- (void) insertObject:(CFXConditionalAttributes*)item atIndex:(int)index;
- (void) recalculate;
- (void) remove:(CFXConditionalAttributes*)item;
- (void) removeAt:(int)index;
- (void) resumeUpdate;
- (void) suspendUpdate;
- (CFXConditionalAttributes*)objectAtIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXCustomGridLineCollection : CFXLabelAwareCollection <CFXILegendBoxItemCollection,CFXILegendBoxItem>
{
}

@property (nonatomic, retain) CFXAxis* axis;
- (CFXCustomGridLine*) objectAtIndex:(int)index;
- (void) add:(CFXCustomGridLine*)constLine;
- (void) insertObject:(NSString*)item atIndex:(int)index;
- (void) remove:(CFXCustomGridLine*)item;
- (CFXCustomGridLine*)objectAtIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXAxisSectionCollection : CFXLabelAwareCollection <CFXILegendBoxItemCollection,CFXILegendBoxItem>
{
}

@property (nonatomic, retain) CFXAxis* axis;
- (CFXAxisSection*) objectAtIndex:(int)index;
- (void) add:(CFXAxisSection*)axisSection;
- (void) insertObject:(CFXAxisSection*)axisSection atIndex:(int)index;
- (void) remove:(CFXAxisSection*)item;
- (CFXAxisSection*)objectAtIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXLabelCollection : CFXLabelAwareCollection 
{
}

- (NSString*) objectAtIndex:(int)index;
- (void) replaceObjectAtIndex:(int)index withObject:(NSString*)object;
- (void) add:(NSString*)item;
- (void) insertObject:(NSString*)item atIndex:(int)index;
- (NSString*)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)setObject:(NSString*)obj atIndexedSubscript:(NSUInteger)idx;

@end

@interface CFXDataValues : NSObject 
{
}

// Gets or Sets a value indicating ChartFX should agreesively allocate space for future values.  This increases performance at the cost of additional memory usage.
@property (nonatomic, assign) BOOL aggressiveAllocation;
// Gets a value indicating whether or not the data is compacted.
@property (nonatomic, assign, readonly) BOOL compacted;
// Gets or sets a value indicating the interval of units to compress data.
@property (nonatomic, assign) double compactedBy;
// Gets or Sets a value indicating to intialize all non-initialized values to hidden value.
@property (nonatomic, assign) BOOL initializeHidden;
// Gets or sets a value specifying to draw a connecting line over a missing data point.
@property (nonatomic, assign) BOOL interpolateHidden;
// Provides access to label collection of the main x-axis.
@property (nonatomic, retain, readonly) CFXLabelCollection* labels;
// Gets or Sets a value indicating the number of series allocated for the chart.
@property (nonatomic, assign) int points;
// Gets or Sets a value indicating the number of series allocated for the chart.
@property (nonatomic, assign) int series;
// Allows you to set X-Values for specific point of XY plots.
@property (nonatomic, retain, readonly) id<CFXIDataArray> x;
// Allows you to access the Y coordinates of the data points.
@property (nonatomic, retain, readonly) id<CFXIDataArray> y;
// Allows you to set the starting Y-value for a specific value on the chart.
@property (nonatomic, retain, readonly) id<CFXIDataArray> yFrom;
- (double) valueForSeries:(int)series andPoint:(int)point;
- (void) setValue:(double)value forSeries:(int)series andPoint:(int)point;
- (void) clear;
- (BOOL) commitChanges;
// Compacts the data in order to display more summarized information.
- (void) compactByStep:(double)step;
- (void) recalculateScale;
// Remove a Series from the collection by index.
- (void) removeSeries:(int)seriesIndex;
- (void) undoCompact;

@end

#define CFXDataValues_Hidden 1E+108

@interface CFXPointAttributesCollection : NSObject 
{
}

@property (nonatomic, assign, readonly) int count;
- (CFXPointAttributes*) attributesForPoint:(int)point;
- (void) setAttributes:(CFXPointAttributes*)value forPoint:(int)point;
- (CFXPointAttributes*) attributesForSeries:(int)series andPoint:(int)point;
- (void) setAttributes:(CFXPointAttributes*)value forSeries:(int)series andPoint:(int)point;
- (void) clear;

@end

@interface CFXToolTipAttributes : NSObject 
{
}

@property (nonatomic, assign) CFXStringAlignment alignment;
@property (nonatomic, assign) BOOL allSeries;
@property (nonatomic, retain) UIColor* backColor;
@property (nonatomic, retain, readonly) CFXLine* border;
@property (nonatomic, retain) NSString* borderTemplate;
@property (nonatomic, retain) NSString* contentTemplate;
@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, retain) NSString* format;
@property (nonatomic, retain) UIColor* textColor;
@property (nonatomic, retain) UIFont* font;

@end

@interface CFXDockableBar : NSObject 
{
}

// Allows Chart FX to calculate the best size according to the tool position.
@property (nonatomic, assign) BOOL autoSize;
// Allows the developer to specify the border style.
@property (nonatomic, assign) CFXDockBorder border;
@property (nonatomic, retain) id<CFXIAdornment> borderObject;
// Sets the position of the data grid.
@property (nonatomic, assign) CFXDockArea dock;
// Gets or Sets the height of the dockable bar in pixels.
@property (nonatomic, assign) int height;
// Gets or Sets a value indicating the Dockablebar object should be shown or not.
@property (nonatomic, assign) BOOL visible;
// Sets the height in pixels.
@property (nonatomic, assign) int width;
// Gets or sets the z-order for a dockable bar.
@property (nonatomic, assign) int zOrder;
// Gets or Sets a value for the background color of a dockable bar.
@property (nonatomic, retain) UIColor* backColor;

@end

@interface CFXLegendItemAttributes : NSObject 
{
}

// Gets or Sets the font style for the legend box item.
@property (nonatomic, assign) CFXFontStyle fontStyle;
// Gets or Sets a value allowing you to invert the order of the LegendBox Items.
@property (nonatomic, assign) BOOL inverted;
// Gets or Sets the index for ordering the legend  box items.
@property (nonatomic, assign) int orderIndex;
// Gets or Sets a value allowing you to set the text color for the legend item.
@property (nonatomic, retain) UIColor* textColor;
// Gets or Sets a value allowing you hide or show the legend item.
@property (nonatomic, assign) BOOL visible;

@end

@interface CFXLegendItemAttributesCollection : NSObject 
{
}

- (CFXLegendItemAttributes*) attributesForList:(id<CFXILegendBoxItemCollection>)list;
- (void) setAttributes:(CFXLegendItemAttributes*)value forList:(id<CFXILegendBoxItemCollection>)list;
- (CFXLegendItemAttributes*) attributesForList:(id<CFXILegendBoxItemCollection>)list andIndex:(int)index;
- (void) setAttributes:(CFXLegendItemAttributes*)value forList:(id<CFXILegendBoxItemCollection>)list andIndex:(int)index;
- (void) clear;
- (void) removeItemFromList:(id<CFXILegendBoxItemCollection>)list index:(int)index;

@end

@interface CFXLegendBox : CFXDockableBar 
{
}

// Allows you to align the content for the legend box. 
@property (nonatomic, assign) CFXContentLayout contentLayout;
// Returns the collection of the custom items in the legend box.
@property (nonatomic, retain, readonly) CFXCustomLegendItemCollection* customItems;
// Allows you to configure the Legend Box Items in the chart.
@property (nonatomic, retain, readonly) CFXLegendItemAttributesCollection* itemAttributes;
// Description goes here
@property (nonatomic, assign) double lineSpacing;
// Gets or sets a value specifying the margin width for a LegendBox.
@property (nonatomic, assign) int marginX;
// Gets or sets a value specifying the margin height for a LegendBox.
@property (nonatomic, assign) int marginY;
@property (nonatomic, assign) BOOL plotAreaOnly;
@property (nonatomic, assign) CFXLegendBoxStyles style;
@property (nonatomic, retain, readonly) CFXTitleCollection* titles;
// Gets or Sets the font of the Legend Box.
@property (nonatomic, retain) UIFont* font;
// Gets or Sets the color used for the text in the legend box.
@property (nonatomic, retain) UIColor* textColor;
- (void) sizeToFit;

@end

@interface CFXAnimationSettings : NSObject 
{
}

@property (nonatomic, assign) CFXAnimationDelay delay;
@property (nonatomic, assign) CFXAnimationDirection direction;
@property (nonatomic, assign) double duration;
@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, assign) CFXAnimationTiming timing;

@end

@interface CFXAnimationAttributes : NSObject 
{
}

@property (nonatomic, retain, readonly) CFXAnimationSettings* dataChange;
@property (nonatomic, retain, readonly) CFXAnimationSettings* load;
@property (nonatomic, assign) BOOL showSpeed;
- (void) reset;

@end

@interface CFXExtensionCollection : NSObject 
{
}

@property (nonatomic, assign, readonly) int count;
- (id) objectAtIndex:(int)n;
- (void) add:(id)obj;
- (void) clear;
- (int) indexOf:(id)extension;
- (void) remove:(id)obj;

@end

@interface CFXRealTimeSettings : NSObject 
{
}

// Gets or Sets the buffer size for real-time charts. When setting this property, the data array will be cleared.
@property (nonatomic, assign) int bufferSize;
// Gets or Sets the Fast Scrolling feature.
@property (nonatomic, assign) BOOL fastScroll;
// Gets the status of the Buffer to see if it is full.
@property (nonatomic, assign, readonly) BOOL isBufferFull;
// Allows you to apply the supported Lineclass members to the real-time loop marker.
@property (nonatomic, retain, readonly) CFXLine* loopMarker;
// Sets or Gets the RealTime Mode.
@property (nonatomic, assign) CFXRealTimeMode mode;
- (void) beginAddDataForNumberOfPoints:(int)points action:(CFXRealTimeAction)action;
// Refreshs the real-time chart after having added the points using BeginAddData.
- (void) endAddDataScrollingLabels:(BOOL)scrollLabels scrollToEnd:(BOOL)scrollToEnd;

@end

@interface CFXChart : UIView 
{
}

// Gets the global attributes which are shared across the series of the chart.
@property (nonatomic, retain, readonly) CFXGlobalAttributes* allSeries;
@property (nonatomic, retain, readonly) CFXAnimationAttributes* animations;
// Used to change the style of the axes.
@property (nonatomic, assign) CFXAxesStyle axesStyle;
// Returns the collection of the X axes of the chart.
@property (nonatomic, retain, readonly) CFXAxisXCollection* axesX;
// Returns the collection of the Y axes of the chart.
@property (nonatomic, retain, readonly) CFXAxisYCollection* axesY;
// Assigns properties specifically to the primary X axis.
@property (nonatomic, retain, readonly) CFXAxisX* axisX;
// Assigns properties specifically to the primary Y axis of the chart.
@property (nonatomic, retain, readonly) CFXAxisY* axisY;
// Assigns properties specifically to the secondary Y axis of the chart.
@property (nonatomic, retain, readonly) CFXAxisY* axisY2;
// Allows you to assign a gradient to the background of a chart. FillMode needs to be set to Gradient.
@property (nonatomic, retain) id<CFXIBackgroundAdornment> background;
// Gets or Sets a default or image border to the chart.
@property (nonatomic, retain) id<CFXIBorderAdornment> border;
// Returns the collection of  ConditionalAttributes objects.
@property (nonatomic, retain, readonly) CFXConditionalAttributesCollection* conditionalAttributes;
// Allows you to set the Y values. Alternativelly, the Y values can be access through the Y property of the DataValuesText.
@property (nonatomic, retain, readonly) CFXDataValues* data;
// Gets or Sets the source containing the values used to populate the chart. 
@property (nonatomic, retain) id dataSource;
// Used to assign data related attributes to your chart applications.
@property (nonatomic, retain, readonly) CFXDataSourceSettings* dataSourceSettings;
// Collection used to add, clear and assign Chart FX extension objects.
@property (nonatomic, retain, readonly) CFXExtensionCollection* extensions;
// Allows you to set additional visual attributes in the chart.
@property (nonatomic, assign) CFXChartStyles extraStyle;
// Sets the gallery type for the whole chart. 
@property (nonatomic, assign) CFXGallery gallery;
// Used to create a gallery object to assign additional attributes to the selected gallery type of the chart. The gallery attribute can also be accessed through the AllSeries property.
@property (nonatomic, retain) id galleryAttributes;
// Allows you to acces the legend box of the chart.
@property (nonatomic, retain, readonly) CFXLegendBox* legendBox;
// Gets the default pane of the chart. 
@property (nonatomic, retain, readonly) CFXPane* mainPane;
// Returns the collection of the defined panes of the chart.
@property (nonatomic, retain, readonly) CFXPaneCollection* panes;
// Allows you to assign a gradient to the inside area of a chart.
@property (nonatomic, retain) id<CFXIAdornment> plotAreaBackground;
// Gets and Sets the top, bottom, left and right gaps of the chart.
@property (nonatomic, retain, readonly) CFXMargins* plotAreaMargin;
@property (nonatomic, retain) NSString* plotAreaTemplate;
// Assigns properties directly to a specific point in the chart.
@property (nonatomic, retain, readonly) CFXPointAttributesCollection* points;
// Allows access to the RealTimeSettings class supported members used to create real-time charts.
@property (nonatomic, retain, readonly) CFXRealTimeSettings* realTime;
// Assigns properties directly to the selected series in the chart.
@property (nonatomic, retain, readonly) CFXSeriesAttributesCollection* series;
// Returns the collection of titles defined in the chart.
@property (nonatomic, retain, readonly) CFXTitleCollection* titles;
// Allows you to enable or disable tooltips when the user positions the mouse over a particular element in the chart area only.
@property (nonatomic, retain, readonly) CFXToolTipAttributes* toolTips;
// Allows you to enable or disable 3D view of the chart.  Also permits to customize the 3D view.
@property (nonatomic, retain, readonly) CFXAttributes3D* view3D;
// Allows you to localize charts for a specific language and region.
@property (nonatomic, retain) NSString* culture;
@property (nonatomic, retain) UIColor* plotAreaColor;
@property (nonatomic, assign) id<CFXChartDelegate> delegate;
- (void) beginUpdate;
- (void) cancelUpdate;
- (void) endUpdate;
// Returns the mask string for a selected point or line in a chart.
- (NSString*) expandMacrosWithMask:(NSString*)mask forSeries:(int)series andPoint:(int)point inMarker:(BOOL)inMarker;
// Allows you to obtain default Chart FX stings which are displayed in the chart.
- (NSString*) messageTextForKey:(NSString*)key;
- (void) recalculateScale;
// Allows you to customize default Chart FX strings which are displayed in the chart.
- (void) setMessageText:(NSString*)message forKey:(NSString*)key;
- (void) updateSizeNow;
+ (double)convertDateToDouble:(NSDate*)date;
+ (NSDate*)convertDoubleToDate:(double)date;
+ (void)setLicense:(NSString*)license;
@property (nonatomic, retain) NSString* palette;
@property (nonatomic, assign) CGPoint textShadowOffset;
@property (nonatomic, retain) UIColor* textShadowColor;
@property (nonatomic, retain) UIColor* foreColor;
@property (nonatomic, retain) UIFont* font;
+(NSString*)version;

@end

#define CFXChart_Hidden 1E+108

@interface CFXVectorGallery : NSObject 
{
}

@property (nonatomic, assign) BOOL cacheResources;
@property (nonatomic, retain) NSString* templateText;

@end

@interface CFXVectorPyramid : CFXVectorGallery 
{
}

@property (nonatomic, assign) BOOL conic;
@property (nonatomic, assign) BOOL distributeHeight;
@property (nonatomic, assign) int faces;
@property (nonatomic, assign) BOOL inverted;
@property (nonatomic, assign) int separation;

@end

@interface CFXVectorPie : CFXVectorGallery 
{
}

@property (nonatomic, assign) CFXPieAnimation animationStyle;
@property (nonatomic, assign) CFXExplodingMode explodingMode;
@property (nonatomic, assign) int labelLineBreak;
@property (nonatomic, assign) BOOL labelsInside;
@property (nonatomic, assign) int maximumLabelMargin;
@property (nonatomic, assign) BOOL shadows;
@property (nonatomic, assign) BOOL showLines;
@property (nonatomic, assign) int sliceSeparation;
@property (nonatomic, assign) BOOL square;
@property (nonatomic, assign) BOOL stacked;
@property (nonatomic, assign) int startAngle;

@end

@interface CFXVectorDoughnut : CFXVectorPie 
{
}

@property (nonatomic, assign) int doughnutThickness;

@end

@interface CFXVectorBubble : CFXVectorGallery 
{
}

@property (nonatomic, assign) CFXBubbleAnimation animationStyle;
@property (nonatomic, assign) int maximumBubbleSize;

@end

@interface CFXVectorBar : CFXVectorGallery 
{
}

@property (nonatomic, assign) CFXBarAnimation animationStyle;
@property (nonatomic, assign) float intraSeriesGap;
@property (nonatomic, assign) BOOL overlap;

@end

@interface CFXVectorGantt : CFXVectorBar 
{
}


@end

@interface CFXVectorCube : CFXVectorBar 
{
}


@end

@interface CFXVectorLine : CFXVectorGallery 
{
}


@end

@interface CFXVectorStepLine : CFXVectorLine 
{
}


@end

@interface CFXVectorCurve : CFXVectorLine 
{
}


@end

@interface CFXVectorArea : CFXVectorGallery 
{
}


@end

@interface CFXVectorCurveArea : CFXVectorArea 
{
}


@end

@interface CFXAxisLabelEventArgs : NSObject 
{
}

@property (nonatomic, retain, readonly) CFXAxis* axis;
@property (nonatomic, retain) NSString* text;

@end

@interface CFXCompactFormulaHandler : NSObject 
{
}

@end

@interface CFXCompactFormulas : NSObject 
{
}

// Returns the average points set by the CompactedBy property.
+ (CFXCompactFormulaHandler*) average;
// Returns the first points set by the CompactedBy property.
+ (CFXCompactFormulaHandler*) first;
// Returns the high, low, and close points set by the CompactedBy property.
+ (CFXCompactFormulaHandler*) hiLowClose;
// Returns the last points set by the CompactedBy property.
+ (CFXCompactFormulaHandler*) last;
// Returns the max points set by the CompactedBy property.
+ (CFXCompactFormulaHandler*) max;
// Returns the min points set by the CompactedBy property.
+ (CFXCompactFormulaHandler*) min;
// Returns the open, high, low, and close points set by the CompactedBy property.
+ (CFXCompactFormulaHandler*) openHiLowClose;

@end

@interface CFXConditionalAttributesEventArgs : NSObject 
{
}

@property (nonatomic, assign) int attributes;
@property (nonatomic, assign) int point;
@property (nonatomic, assign) int series;

@end

@interface CFXConditionDataValue : NSObject <CFXICondition>
{
}

@property (nonatomic, assign) BOOL active;
@property (nonatomic, assign) CFXDataElement dataElement;
@property (nonatomic, assign) double from;
@property (nonatomic, assign) BOOL fromOpen;
@property (nonatomic, assign) BOOL inverse;
@property (nonatomic, assign) CFXConditionSpecialValue specialValue;
@property (nonatomic, assign) double to;
@property (nonatomic, assign) BOOL toOpen;
@property (nonatomic, assign) CFXConditionUnit unit;

@end

@interface CFXDataArray : NSObject <CFXIDataArray>
{
}

// Description goes here
@property (nonatomic, retain) CFXCompactFormulaHandler* compactFormula;
// Description goes here
@property (nonatomic, assign, readonly) BOOL hasData;
// Description goes here
@property (nonatomic, assign) BOOL shared;
- (double) valueForPoint:(int)point;
- (void) setValue:(double)value forPoint:(int)point;
- (double) valueForSeries:(int)series andPoint:(int)point;
- (void) setValue:(double)value forSeries:(int)series andPoint:(int)point;
// Description goes here
- (void) clear;

@end

@interface CFXGetTipEventArgs : NSObject 
{
}

@property (nonatomic, assign, readonly) CFXHitType hitType;
@property (nonatomic, retain, readonly) id object;
@property (nonatomic, assign, readonly) int point;
@property (nonatomic, assign, readonly) int series;
@property (nonatomic, retain) NSString* text;

@end

@interface CFXHitTestEventArgs : NSObject 
{
}

@property (nonatomic, assign) BOOL handled;
@property (nonatomic, assign, readonly) CFXHitType hitType;
@property (nonatomic, retain, readonly) id object;
@property (nonatomic, assign, readonly) int point;
@property (nonatomic, assign, readonly) int series;
@property (nonatomic, assign, readonly) double value;

@end

@interface CFXPointLabelEventArgs : NSObject 
{
}

@property (nonatomic, retain, readonly) CFXAxis* axis;
@property (nonatomic, assign) BOOL handled;
@property (nonatomic, assign, readonly) int point;
@property (nonatomic, assign, readonly) int series;
@property (nonatomic, retain) NSString* text;

@end

@interface CFXGradientBackground_ColorCollection : NSObject 
{
}

@property (nonatomic, assign, readonly) int count;
- (void) add:(UIColor*)color;
- (void) clear;

@end

@interface CFXGradientBackground_FloatCollection : NSObject 
{
}

@property (nonatomic, assign, readonly) int count;
- (float) objectAtIndex:(int)n;
- (void) replaceObjectAtIndex:(int)n withObject:(float)object;
- (void) add:(float)f;
- (void) clear;

@end

@interface CFXGradientBackground : NSObject <CFXIBackgroundAdornment>
{
}

@property (nonatomic, assign) float angle;
@property (nonatomic, retain, readonly) CFXGradientBackground_ColorCollection* colors;
@property (nonatomic, assign) int effectArea;
@property (nonatomic, retain, readonly) CFXGradientBackground_FloatCollection* factor;
@property (nonatomic, retain, readonly) CFXGradientBackground_FloatCollection* position;
@property (nonatomic, assign) CFXGradientType type;
@property (nonatomic, retain) UIColor* colorFrom;
@property (nonatomic, retain) UIColor* colorTo;

@end

@interface CFXImageBackground : NSObject <CFXIBackgroundAdornment>
{
}

@property (nonatomic, retain) UIImage* image;

@end

@interface CFXArea : NSObject 
{
}

@property (nonatomic, assign) CFXLineAnimation animationStyle;

@end

@interface CFXCurve : NSObject 
{
}

@property (nonatomic, assign) CFXLineAnimation animationStyle;

@end

@interface CFXHighLow : NSObject 
{
}

@property (nonatomic, assign) BOOL highLowClose4Series;

@end

@interface CFXLineGallery : NSObject 
{
}

@property (nonatomic, assign) CFXLineAnimation animationStyle;

@end

@interface CFXPareto : NSObject 
{
}


@end

@interface CFXRadar : NSObject 
{
}

@property (nonatomic, assign) BOOL circular;
@property (nonatomic, assign) BOOL clockwise;
@property (nonatomic, assign) BOOL closed;
@property (nonatomic, assign) BOOL fillArea;
@property (nonatomic, assign) BOOL shadows;
@property (nonatomic, assign) BOOL showLines;

@end

@interface CFXScatter : NSObject 
{
}


@end

@interface CFXSurface : NSObject <CFXILegendBoxItemCollection,CFXILegendBoxItem>
{
}

@property (nonatomic, assign) BOOL showContourLines;
@property (nonatomic, assign) BOOL showGridLines;
@property (nonatomic, assign) double step;

@end

@interface CFXSeriesPointIndex : NSObject 
{
}

- (id) initSeriesPointIndex1:(int)seriesIndex pointIndex:(int)pointIndex;
- (BOOL) isEqual:(id)obj;

@end

@interface CFXVectorBorder : NSObject <CFXIBorderAdornment>
{
}

@property (nonatomic, retain) NSString* templateText;
@property (nonatomic, retain) UIColor* color;

@end

