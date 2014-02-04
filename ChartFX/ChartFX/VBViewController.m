//
//  VBViewController.m
//  ChartFX
//
//  Created by Ariel Rodriguez on 2/4/14.
//  Copyright (c) 2014 Ariel Rodriguez. All rights reserved.
//

#import "VBViewController.h"
#import <ChartFX/ChartFX.h>
#import "VBDataSource.h"

@interface VBViewController ()

@end

@implementation VBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    CFXChart *scatterChart = [[CFXChart alloc] init];
    scatterChart.gallery = CFXGalleryScatter;

    UIView *view = [self view];
    
    [view addSubview:scatterChart];
    
    [scatterChart setTranslatesAutoresizingMaskIntoConstraints:NO];
    [scatterChart addConstraint:[NSLayoutConstraint constraintWithItem:scatterChart
                                                             attribute:NSLayoutAttributeWidth
                                                             relatedBy:NSLayoutRelationEqual
                                                                toItem:nil
                                                             attribute:NSLayoutAttributeNotAnAttribute
                                                            multiplier:1.0
                                                              constant:600.0]];
    [scatterChart addConstraint:[NSLayoutConstraint constraintWithItem:scatterChart
                                                             attribute:NSLayoutAttributeHeight
                                                             relatedBy:NSLayoutRelationEqual
                                                                toItem:nil
                                                             attribute:NSLayoutAttributeNotAnAttribute
                                                            multiplier:1.0
                                                              constant:400.0]];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeCenterX
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:scatterChart
                                                     attribute:NSLayoutAttributeCenterX
                                                    multiplier:1.0
                                                      constant:0.0]];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeCenterY
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:scatterChart
                                                     attribute:NSLayoutAttributeCenterY
                                                    multiplier:1.0
                                                      constant:0.0]];
    
    VBDataSource *dataSource = [VBDataSource new];
    CFXDataSourceSettings *dataSourceSettings = [scatterChart dataSourceSettings];

    CFXFieldMapCollection *fields = [dataSourceSettings fields];
    
    // fields have to be configured before passing the data source
    CFXFieldMap *fieldX = [CFXFieldMap new];
    [fieldX setName:@"X"];
    [fieldX setUsage:CFXFieldUsageXValue];
    [fields add:fieldX];
    
    CFXFieldMap *fieldY = [CFXFieldMap new];
    [fieldY setName:@"Y"];
    [fieldY setUsage:CFXFieldUsageValue];
    [fields add:fieldY];
    
    [dataSourceSettings setDataSource:dataSource];
    
    CFXTitleDockable* myTitle = [[CFXTitleDockable alloc] init];
    myTitle.text = @"This is my Title";
    [scatterChart.titles add:myTitle];
    
//    CFXSeriesAttributes* series0 = scatterChart.series[0];
//    series0.color = [UIColor redColor];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
