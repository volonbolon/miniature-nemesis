typedef NS_ENUM(NSInteger, CFXRowHeadingSettings) 
{
    CFXRowHeadingSettingsAuto = 0,
    CFXRowHeadingSettingsDatesAsLabels = 1,
    CFXRowHeadingSettingsXValues = 2,
    CFXRowHeadingSettingsCompressedXValues = 3
};

@interface CFXCrosstabDataProvider : NSObject 
{
}

@property (nonatomic, retain) NSString* culture;
@property (nonatomic, retain) id dataSource;
@property (nonatomic, retain) NSString* dateFormat;
@property (nonatomic, retain) NSString* nullColumnHeading;
@property (nonatomic, assign) CFXRowHeadingSettings rowHeadingSettings;
@property (nonatomic, retain) NSString* separator;

@end

