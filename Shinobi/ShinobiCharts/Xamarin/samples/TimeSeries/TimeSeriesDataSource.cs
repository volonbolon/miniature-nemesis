//
// TimeSeriesDataSource.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using ShinobiCharts;
using System.Collections.Generic;
using System.Json;
using System.IO;

namespace TimeSeries
{
	public class TimeSeriesDataSource : SChartDataSource
	{
		List<SChartDataPoint> timeSeries = new List<SChartDataPoint>();

		public TimeSeriesDataSource()
		{
			NSDateFormatter dateFormatter = new NSDateFormatter { DateFormat = "dd-MM-yyyy" };
			JsonValue stocks = JsonObject.Load(new StreamReader("./AppleStockPrices.json"));
			foreach (JsonValue stock in stocks) {
				timeSeries.Add (new SChartDataPoint {
					XValue = dateFormatter.Parse(stock["date"]),
					YValue = new NSNumber((double)stock["close"]),
				});
			};
		}

		public override int GetNumberOfSeries (ShinobiChart chart)
		{
			return 1;
		}

		public override SChartSeries GetSeries (ShinobiChart chart, int dataSeriesIndex)
		{
			SChartLineSeries series = new SChartLineSeries ();
			return series;
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

