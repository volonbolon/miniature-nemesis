//
//  VBDataSource.m
//  ChartFX
//
//  Created by Ariel Rodriguez on 2/4/14.
//  Copyright (c) 2014 Ariel Rodriguez. All rights reserved.
//

#import "VBDataSource.h"

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

@interface VBDataSource ()
@property (nonatomic, strong) NSArray *items;
@end

@implementation VBDataSource

- (id)init
{
    
    self = [super init];
    
    if ( self != nil ) {
        
        _items = @[[VBValue valueWithX:@(-100) y:@5],[VBValue valueWithX:@(12) y:@(19)],[VBValue valueWithX:@(-36) y:@(100)],[VBValue valueWithX:@(8) y:@(91)],[VBValue valueWithX:@(-43) y:@(87)],[VBValue valueWithX:@(93) y:@(-22)],[VBValue valueWithX:@(-50) y:@(-100)],[VBValue valueWithX:@(-77) y:@(82)],[VBValue valueWithX:@(7) y:@(-37)],[VBValue valueWithX:@(100) y:@(34)]];
        
    }
    
    return self;
    
}

#pragma mark - CFXChartDataSource
- (int)numberOfObjectsInChart:(CFXChart *)chart
{
    
    return (int)[[self items] count];
    
}

- (id)chart:(CFXChart*)chart objectAtIndex:(int)index
{
    
    return [[self items] objectAtIndex:index];
    
}

@end