//
//  SChartDateTimeAxis.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SChartDateRange;

/** 
 An SChartDateTimeAxis is a subclass of `SChartAxis` designed to work with data points that use `NSDate`. 
 
  The frequency values for tick marks are expected to be `SChartDateFrequency` objects.
 
 @available Standard
 @available Premium
 
 @sa ChartsUserGuide
 
 @sample FinancialChart
 
 */
@interface SChartDateTimeAxis : SChartAxis

#pragma mark - 
#pragma mark Initialization
/** @name Initialization */
/** Init with a NSDate specific range */
- (id)initWithRange:(SChartDateRange *)range;


#pragma mark -
#pragma mark Subclassing
/** @name Subclassing */

/** Returns a format string for the current frequency.

 For example, to show seconds when the chart has calculated a high tick
 frequency for the current zoom level:

    if(frequency.hour < 12)
        return @"HH:mm:ss";
    else
        return @"HH:mm";

 This is called just prior to automatic tick label generation and allows you to
 override the default date label-format as required.
 */
- (NSString *) formatStringForFrequency:(NSDateComponents *)frequency;

@end
