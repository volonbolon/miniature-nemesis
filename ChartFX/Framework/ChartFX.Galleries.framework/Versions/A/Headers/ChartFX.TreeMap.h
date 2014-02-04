typedef NS_ENUM(NSInteger, CFXTreeMapLayout) 
{
    CFXTreeMapLayoutNaive = 0,
    CFXTreeMapLayoutSquarified = 1
};

@interface CFXTreeMap : NSObject 
{
}

@property (nonatomic, assign) CFXTreeMapLayout layout;
@property (nonatomic, assign) BOOL randomLocations;
@property (nonatomic, retain) NSString* templateText;

@end

