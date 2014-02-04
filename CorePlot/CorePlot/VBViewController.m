//
//  VBViewController.m
//  CorePlot
//
//  Created by Ariel Rodriguez on 2/4/14.
//  Copyright (c) 2014 Ariel Rodriguez. All rights reserved.
//

#import "VBViewController.h"

NSString *const kPassPlot = @"pass";
NSString *const kFailPlot = @"fail";


@interface VBValue : NSObject
@property (nonatomic, strong) NSNumber *x;
@property (nonatomic, strong) NSNumber *y;

+ (instancetype)valueWithX:(NSNumber *)x y:(NSNumber *)y;
@end

@implementation VBValue

+ (instancetype)valueWithX:(NSNumber *)x y:(NSNumber *)y
{
    
    VBValue *v = [self new];
    [v setX:x];
    [v setY:y];
    
    return v;
    
}
@end

@interface VBViewController ()
@property (nonatomic, strong) CPTGraphHostingView *hostView;
@property (nonatomic, strong) CPTTheme *theme;
@property (nonatomic, strong) NSArray *pass;
@property (nonatomic, strong) NSArray *fail;

- (void)initPlot;
- (void)configureHost;
- (void)configureGraph;
- (void)configurePlots;
- (void)configureAxes;

@end

@implementation VBViewController
- (void)viewDidLoad
{

    [self setPass:@[[VBValue valueWithX:@(-100) y:@5],[VBValue valueWithX:@(12) y:@(19)],[VBValue valueWithX:@(-36) y:@(100)],[VBValue valueWithX:@(8) y:@(91)],[VBValue valueWithX:@(-43) y:@(87)],[VBValue valueWithX:@(93) y:@(-22)],[VBValue valueWithX:@(-50) y:@(-100)],[VBValue valueWithX:@(-77) y:@(82)],[VBValue valueWithX:@(7) y:@(-37)],[VBValue valueWithX:@(100) y:@(34)]]];
    
    [self setFail:@[[VBValue valueWithX:@(85) y:@(84)],[VBValue valueWithX:@(-7) y:@(47)],[VBValue valueWithX:@(-57) y:@(-95)],[VBValue valueWithX:@(69) y:@(32)],[VBValue valueWithX:@(-96) y:@(-67)],[VBValue valueWithX:@(-96) y:@(-53)],[VBValue valueWithX:@(-89) y:@(38)],[VBValue valueWithX:@(-54) y:@(64)],[VBValue valueWithX:@(-57) y:@(-36)],[VBValue valueWithX:@(38) y:@(78)]]];
    
}


- (void)viewDidAppear:(BOOL)animated
{
    
    [super viewDidAppear:animated];
    
    [self initPlot];
    
}

- (void)initPlot
{
    
    [self configureHost];
    [self configureGraph];
    [self configurePlots];
    [self configureAxes];
    
}

- (void)configureHost
{

    CPTGraphHostingView *host = [[CPTGraphHostingView alloc] initWithFrame:CGRectZero];
    [host setAllowPinchScaling:YES];
    [self setHostView:host];

    UIView *view = [self view];
    
    [view addSubview:host];
    
    [host setTranslatesAutoresizingMaskIntoConstraints:NO];
    [host addConstraint:[NSLayoutConstraint constraintWithItem:host
                                                             attribute:NSLayoutAttributeWidth
                                                             relatedBy:NSLayoutRelationEqual
                                                                toItem:nil
                                                             attribute:NSLayoutAttributeNotAnAttribute
                                                            multiplier:1.0
                                                              constant:600.0]];
    [host addConstraint:[NSLayoutConstraint constraintWithItem:host
                                                             attribute:NSLayoutAttributeHeight
                                                             relatedBy:NSLayoutRelationEqual
                                                                toItem:nil
                                                             attribute:NSLayoutAttributeNotAnAttribute
                                                            multiplier:1.0
                                                              constant:400.0]];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeCenterX
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:host
                                                     attribute:NSLayoutAttributeCenterX
                                                    multiplier:1.0
                                                      constant:0.0]];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeCenterY
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:host
                                                     attribute:NSLayoutAttributeCenterY
                                                    multiplier:1.0
                                                      constant:0.0]];
    
    
}

- (void)configureGraph
{
    
    // 1 - Create the graph
    CPTGraph *graph = [[CPTXYGraph alloc] initWithFrame:self.hostView.bounds];
    [graph applyTheme:[CPTTheme themeNamed:kCPTDarkGradientTheme]];
    self.hostView.hostedGraph = graph;
    // 2 - Set graph title
    NSString *title = @"Some Title";
    graph.title = title;
    // 3 - Create and set text style
    CPTMutableTextStyle *titleStyle = [CPTMutableTextStyle textStyle];
    titleStyle.color = [CPTColor whiteColor];
    titleStyle.fontName = @"Helvetica-Bold";
    titleStyle.fontSize = 16.0f;
    graph.titleTextStyle = titleStyle;
    graph.titlePlotAreaFrameAnchor = CPTRectAnchorTop;
    graph.titleDisplacement = CGPointMake(0.0f, 10.0f);
    // 4 - Set padding for plot area
    [graph.plotAreaFrame setPaddingLeft:30.0f];
    [graph.plotAreaFrame setPaddingBottom:30.0f];
    // 5 - Enable user interactions for plot space
    CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *) graph.defaultPlotSpace;
    plotSpace.allowsUserInteraction = YES;
    
}

- (void)configurePlots
{
    
    // 1 - Get graph and plot space
    CPTGraph *graph = self.hostView.hostedGraph;
    CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *) graph.defaultPlotSpace;

    CPTScatterPlot *passPlot = [[CPTScatterPlot alloc] init];
    passPlot.dataSource = self;
    passPlot.identifier = kPassPlot;
    CPTColor *passColor = [CPTColor redColor];
    [graph addPlot:passPlot
       toPlotSpace:plotSpace];
    
    
    CPTScatterPlot *failPlot = [[CPTScatterPlot alloc] init];
    failPlot.dataSource = self;
    failPlot.identifier = kFailPlot;
    CPTColor *failColor = [CPTColor greenColor];
    [graph addPlot:failPlot toPlotSpace:plotSpace];
    

    [plotSpace scaleToFitPlots:@[passPlot, failPlot]];
    
    CPTMutablePlotRange *xRange = [plotSpace.xRange mutableCopy];
    [xRange expandRangeByFactor:CPTDecimalFromCGFloat(1.1f)];
    plotSpace.xRange = xRange;
    CPTMutablePlotRange *yRange = [plotSpace.yRange mutableCopy];
    [yRange expandRangeByFactor:CPTDecimalFromCGFloat(1.2f)];
    plotSpace.yRange = yRange;
    
    // 4 - Create styles and symbols
    CPTMutableLineStyle *passLineStyle = [passPlot.dataLineStyle mutableCopy];
    passLineStyle.lineWidth = .0;
    passLineStyle.lineColor = passColor;
    passPlot.dataLineStyle = passLineStyle;
    CPTMutableLineStyle *passSymbolLineStyle = [CPTMutableLineStyle lineStyle];
    passSymbolLineStyle.lineColor = passColor;
    CPTPlotSymbol *passSymbol = [CPTPlotSymbol ellipsePlotSymbol];
    passSymbol.fill = [CPTFill fillWithColor:passColor];
    passSymbol.lineStyle = nil;
    passSymbol.size = CGSizeMake(6.0f, 6.0f);
    passPlot.plotSymbol = passSymbol;
    
    
    CPTMutableLineStyle *failLineStyle = [failPlot.dataLineStyle mutableCopy];
    failLineStyle.lineWidth = .0;
    failLineStyle.lineColor = failColor;
    failPlot.dataLineStyle = failLineStyle;
    CPTMutableLineStyle *failSymbolLineStyle = [CPTMutableLineStyle lineStyle];
    failSymbolLineStyle.lineColor = failColor;
    CPTPlotSymbol *failSymbol = [CPTPlotSymbol starPlotSymbol];
    failSymbol.fill = [CPTFill fillWithColor:failColor];
    failSymbol.lineStyle = nil;
    failSymbol.size = CGSizeMake(6.0f, 6.0f);
    failPlot.plotSymbol = failSymbol;
    
}

#pragma mark - CPTPlotDataSource methods
- (NSUInteger)numberOfRecordsForPlot:(CPTPlot *)plot
{
    
    NSUInteger numberOfRecordsForPlot = 0;
    if ( [(NSString *)[plot identifier] isEqualToString:kPassPlot] ) {
        
        numberOfRecordsForPlot = [[self pass] count];
        
    } else if ( [(NSString *)[plot identifier] isEqualToString:kFailPlot] ) {
        
        numberOfRecordsForPlot = [[self fail] count];
        
    }

    return numberOfRecordsForPlot;

}

- (NSNumber *)numberForPlot:(CPTPlot *)plot field:(NSUInteger)fieldEnum recordIndex:(NSUInteger)index {
    
    NSNumber *numberForPlot = [NSNumber numberWithInt:0];
    switch (fieldEnum) {

        case CPTScatterPlotFieldX:
            
            if ( [(NSString *)[plot identifier] isEqualToString:kPassPlot] ) {
                
                numberForPlot = [(VBValue *)[[self pass] objectAtIndex:index] x];
                
            } else if ( [(NSString *)[plot identifier] isEqualToString:kFailPlot] ) {
                
                numberForPlot = [(VBValue *)[[self fail] objectAtIndex:index] x];
                
            }

            break;
            
        case CPTScatterPlotFieldY:

            if ( [(NSString *)[plot identifier] isEqualToString:kPassPlot] ) {
                
                numberForPlot = [(VBValue *)[[self pass] objectAtIndex:index] y];
                
            } else if ( [(NSString *)[plot identifier] isEqualToString:kFailPlot] ) {
                
                numberForPlot = [(VBValue *)[[self fail] objectAtIndex:index] y];
                
            }
            
            break;
    }
    
    return numberForPlot;

}

- (void)configureAxes
{
    
    // 1 - Configure styles
    CPTMutableTextStyle *axisTitleStyle = [CPTMutableTextStyle textStyle];
    axisTitleStyle.color = [CPTColor whiteColor];
    axisTitleStyle.fontName = @"Helvetica-Bold";
    axisTitleStyle.fontSize = 12.0f;
    CPTMutableLineStyle *axisLineStyle = [CPTMutableLineStyle lineStyle];
    axisLineStyle.lineWidth = 2.0f;
    axisLineStyle.lineColor = [[CPTColor whiteColor] colorWithAlphaComponent:1];
    // 2 - Get the graph's axis set
    CPTXYAxisSet *axisSet = (CPTXYAxisSet *) self.hostView.hostedGraph.axisSet;
    // 3 - Configure the x-axis
    axisSet.xAxis.labelingPolicy = CPTAxisLabelingPolicyNone;
    axisSet.xAxis.titleTextStyle = axisTitleStyle;
    axisSet.xAxis.titleOffset = 10.0f;
    axisSet.xAxis.axisLineStyle = axisLineStyle;
    // 4 - Configure the y-axis
    axisSet.yAxis.labelingPolicy = CPTAxisLabelingPolicyNone;
    axisSet.yAxis.titleTextStyle = axisTitleStyle;
    axisSet.yAxis.titleOffset = 5.0f;
    axisSet.yAxis.axisLineStyle = axisLineStyle;
    
}

@end
