//
// CandlestickChartDataSource.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using ShinobiCharts;
using System.Json;
using System.IO;
using System.Collections.Generic;

namespace CandlestickChart
{
	public class CandlestickChartDataSource : SChartDataSource
	{
		List<SChartDataPoint> timeSeries = new List<SChartDataPoint>();

		public CandlestickChartDataSource()
		{
			NSDateFormatter dateFormatter = new NSDateFormatter { DateFormat = "dd-MM-yyyy" };
			JsonValue stocks = JsonObject.Load(new StreamReader("./AppleStockPrices.json"));
			foreach (JsonValue stock in stocks) {
				timeSeries.Add (new SChartMultiYDataPoint {
					XValue = dateFormatter.Parse(stock["date"]),
					YValues = new NSMutableDictionary() {
						{ new NSString(SChartCandlestickSeries.KeyOpen), new NSNumber((double)stock["open"]) },
						{ new NSString(SChartCandlestickSeries.KeyHigh), new NSNumber((double)stock["high"]) },
						{ new NSString(SChartCandlestickSeries.KeyLow), new NSNumber((double)stock["low"]) },
						{ new NSString(SChartCandlestickSeries.KeyClose), new NSNumber((double)stock["close"]) },
					}
				});
			};
		}

		public override int GetNumberOfSeries (ShinobiChart chart)
		{
			return 1;
		}

		public override SChartSeries GetSeries (ShinobiChart chart, int dataSeriesIndex)
		{
			return new SChartCandlestickSeries ();
		}

		public override int GetNumberOfDataPoints (ShinobiChart chart, int dataSeriesIndex)
		{
			return timeSeries.Count;
		}

		public override SChartData GetDataPoint (ShinobiChart chart, int dataIndex, int dataSeriesIndex)
		{
			return timeSeries [dataIndex];
		}
	}
}

