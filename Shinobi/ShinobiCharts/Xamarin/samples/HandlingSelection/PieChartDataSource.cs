//
// PieChartDataSource.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using ShinobiCharts;
using System.Collections.Generic;
using System.Linq;

namespace HandlingSelection
{
	class PieChartDataSource : SChartDataSource
	{
		public string DisplayYear {
			get;
			set;
		}
		List<Tuple<string, List<Tuple<string, double>>>> sales;

		public PieChartDataSource (List<Tuple<string, List<Tuple<string, double>>>> sales, string year)
		{
			this.sales = sales;
			DisplayYear = year;
		}

		private List<Tuple<string, double>> CurrentData
		{
			get {
				return sales.First (i => i.Item1 == DisplayYear).Item2;
			}
		}

		#region implemented abstract members of SChartDataSource

		public override int GetNumberOfSeries (ShinobiChart chart)
		{
			return 1;
		}

		public override SChartSeries GetSeries (ShinobiChart chart, int dataSeriesIndex)
		{
			return new SChartPieSeries ();
		}

		public override int GetNumberOfDataPoints (ShinobiChart chart, int dataSeriesIndex)
		{
			return CurrentData.Count;
		}

		public override SChartData GetDataPoint (ShinobiChart chart, int dataIndex, int dataSeriesIndex)
		{
			var data = CurrentData[dataIndex];
			return new SChartDataPoint {
				XValue = new NSString(data.Item1),
				YValue = new NSNumber(data.Item2)
			};
		}

		#endregion
	}
}

