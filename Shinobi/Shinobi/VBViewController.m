//
//  VBViewController.m
//  Shinobi
//
//  Created by Ariel Rodriguez on 2/5/14.
//  Copyright (c) 2014 Ariel Rodriguez. All rights reserved.
//

#import "VBViewController.h"
 
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
@property (nonatomic, strong) ShinobiChart *chart;
@property (nonatomic, strong) NSArray *pass;
@property (nonatomic, strong) NSArray *fail;
@end

@implementation VBViewController

- (void)viewDidLoad
{
    
    [super viewDidLoad];

    [self setPass:@[[VBValue valueWithX:@(-100) y:@5],[VBValue valueWithX:@(12) y:@(19)],[VBValue valueWithX:@(-36) y:@(100)],[VBValue valueWithX:@(8) y:@(91)],[VBValue valueWithX:@(-43) y:@(87)],[VBValue valueWithX:@(93) y:@(-22)],[VBValue valueWithX:@(-50) y:@(-100)],[VBValue valueWithX:@(-77) y:@(82)],[VBValue valueWithX:@(7) y:@(-37)],[VBValue valueWithX:@(100) y:@(34)]]];
    
    [self setFail:@[[VBValue valueWithX:@(85) y:@(84)],[VBValue valueWithX:@(-7) y:@(47)],[VBValue valueWithX:@(-57) y:@(-95)],[VBValue valueWithX:@(69) y:@(32)],[VBValue valueWithX:@(-96) y:@(-67)],[VBValue valueWithX:@(-96) y:@(-53)],[VBValue valueWithX:@(-89) y:@(38)],[VBValue valueWithX:@(-54) y:@(64)],[VBValue valueWithX:@(-57) y:@(-36)],[VBValue valueWithX:@(38) y:@(78)]]];
    
    UIView *view = [self view];
    
    [view setBackgroundColor:[UIColor whiteColor]];
    ShinobiChart *chart = [[ShinobiChart alloc] initWithFrame:CGRectMake(0, 0, 300, 400)];
    [chart setTranslatesAutoresizingMaskIntoConstraints:NO];
    [view addSubview:chart];
    
    // Autolayout
    [chart addConstraint:[NSLayoutConstraint constraintWithItem:chart
                                                     attribute:NSLayoutAttributeWidth
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:nil
                                                     attribute:NSLayoutAttributeNotAnAttribute
                                                    multiplier:1.0
                                                      constant:600.0]];
    [chart addConstraint:[NSLayoutConstraint constraintWithItem:chart
                                                     attribute:NSLayoutAttributeHeight
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:nil
                                                     attribute:NSLayoutAttributeNotAnAttribute
                                                    multiplier:1.0
                                                      constant:400.0]];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeCenterX
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:chart
                                                     attribute:NSLayoutAttributeCenterX
                                                    multiplier:1.0
                                                      constant:0.0]];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeCenterY
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:chart
                                                     attribute:NSLayoutAttributeCenterY
                                                    multiplier:1.0
                                                      constant:0.0]];
    
    [chart setTitle:@"Some Title"];
    [chart setLicenseKey:@"WmO0xWZISh11EZxMjAxNDAzMDdpbmZvQHNoaW5vYmljb250cm9scy5jb20=dD/v7OK5unWIDNSRV18kqx34DvAELXJc8msda+ZlNY8fkjg2GG+sR+j1JRsPUsz6RSn2tLoepr4CPvsyUgqpO0ZCkCOvlEv8bnx5gx+zVRMQhvy4gJsX8dIvwMLR34qhJkp9+kDoZmZ5QuQnLt3gTxBuIilc=BQxSUisl3BaWf/7myRmmlIjRnMU2cA7q+/03ZX9wdj30RzapYANf51ee3Pi8m2rVW6aD7t6Hi4Qy5vv9xpaQYXF5T7XzsafhzS3hbBokp36BoJZg8IrceBj742nQajYyV7trx5GIw9jy/V6r0bvctKYwTim7Kzq+YPWGMtqtQoU=PFJTQUtleVZhbHVlPjxNb2R1bHVzPnh6YlRrc2dYWWJvQUh5VGR6dkNzQXUrUVAxQnM5b2VrZUxxZVdacnRFbUx3OHZlWStBK3pteXg4NGpJbFkzT2hGdlNYbHZDSjlKVGZQTTF4S2ZweWZBVXBGeXgxRnVBMThOcDNETUxXR1JJbTJ6WXA3a1YyMEdYZGU3RnJyTHZjdGhIbW1BZ21PTTdwMFBsNWlSKzNVMDg5M1N4b2hCZlJ5RHdEeE9vdDNlMD08L01vZHVsdXM+PEV4cG9uZW50PkFRQUI8L0V4cG9uZW50PjwvUlNBS2V5VmFsdWU+"];
    SChartNumberAxis *xAxis = [[SChartNumberAxis alloc] init];
    [chart setXAxis:xAxis];
    
    SChartNumberAxis *yAxis = [[SChartNumberAxis alloc] init];
    [chart setYAxis:yAxis];
    
    [chart setDatasource:self];
    
    [self setChart:chart];
    
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (int)numberOfSeriesInSChart:(ShinobiChart *)chart
{
    return 2;
}

-(SChartSeries *)sChart:(ShinobiChart *)chart
          seriesAtIndex:(int)index
{
    
    SChartScatterSeries *scatterSeries = [[SChartScatterSeries alloc] init];
    
    // the first series is a cosine curve, the second is a sine curve
    if (index == 0) {
        scatterSeries.title = [NSString stringWithFormat:@"Pass"];
    } else {
        scatterSeries.title = [NSString stringWithFormat:@"Fail"];
    }
    
    return scatterSeries;
}

- (int)sChart:(ShinobiChart *)chart
numberOfDataPointsForSeriesAtIndex:(int)seriesIndex
{
    
    int numberOfDataPoints = 0;

    switch ( seriesIndex ) {
        case 0:
            numberOfDataPoints = [[self pass] count];
            break;
            
        case 1:
            numberOfDataPoints = [[self fail] count];
            break;
    }
    
    return numberOfDataPoints;

}

- (id<SChartData>)sChart:(ShinobiChart *)chart
        dataPointAtIndex:(int)dataIndex
        forSeriesAtIndex:(int)seriesIndex
{
    
    VBValue *value = nil;
    
    switch ( seriesIndex ) {
        case 0:
            value = [[self pass] objectAtIndex:dataIndex];
            break;
            
        case 1:
            value = [[self fail] objectAtIndex:dataIndex];
            break;
    }
    
    SChartDataPoint *datapoint = [[SChartDataPoint alloc] init];
    [datapoint setXValue:[value x]];
    [datapoint setYValue:[value y]];

    return datapoint;
    
}
@end
