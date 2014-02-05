//
// BubbleSeriesDataSource.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.IO;
using System.Json;
using System.Collections.Generic;
using MonoTouch.Foundation;

using ShinobiCharts;

namespace BubbleSeries
{
	public class BubbleSeriesDataSource : SChartDataSource
	{
		List<SChartBubbleDataPoint> _data = new List<SChartBubbleDataPoint> ();

		public BubbleSeriesDataSource()
			: base()
		{
			JsonValue data = JsonObject.Load(new StreamReader("./punchcard.json"));
			foreach (JsonValue jsonPoint in data) {
				int commits = jsonPoint ["commits"];
				if (commits > 0) {
					_data.Add (new SChartBubbleDataPoint {
						XValue = new NSNumber((int)jsonPoint["hour"]),
						YValue = new NSString(jsonPoint["day"]),
						Area = commits
					});
				}
			};
		}

		#region implemented abstract members of SChartDataSource

		public override int GetNumberOfSeries (ShinobiChart chart)
		{
			return 1;
		}

		public override SChartSeries GetSeries (ShinobiChart chart, int dataSeriesIndex)
		{
			return new SChartBubbleSeries {
				AutoScalingBiggestBubbleDiameter = 40
			};
		}

		public override int GetNumberOfDataPoints (ShinobiChart chart, int dataSeriesIndex)
		{
			return _data.Count;
		}

		public override SChartData GetDataPoint (ShinobiChart chart, int dataIndex, int dataSeriesIndex)
		{
			return _data [dataIndex];
		}

		#endregion

	}
}

