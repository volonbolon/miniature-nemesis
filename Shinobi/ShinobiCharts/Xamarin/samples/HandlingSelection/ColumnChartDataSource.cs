//
// ColumnChartDataSource.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using ShinobiCharts;
using System.Collections.Generic;

namespace HandlingSelection
{
	class ColumnChartDataSource : SChartDataSource
	{
		public string DisplayYear {
			get;
			set;
		}

		List<Tuple<string, List<Tuple<string, double>>>> sales;

		public ColumnChartDataSource (List<Tuple<string, List<Tuple<string, double>>>> sales, string year)
		{
			this.sales = sales;
			DisplayYear = year;
		}

		#region implemented abstract members of SChartDataSource

		public override int GetNumberOfSeries (ShinobiChart chart)
		{
			return sales.Count;
		}

		public override SChartSeries GetSeries (ShinobiChart chart, int dataSeriesIndex)
		{
			string year = sales [dataSeriesIndex].Item1;
			SChartColumnSeries series = new SChartColumnSeries {
				Title = year,
				SelectionMode = SChartSelection.Series
			};
			series.Style.ShowAreaWithGradient = false;
			series.SelectedStyle.ShowAreaWithGradient = false;
			series.SelectedStyle.AreaColor = UIColor.Red;
			series.SelectedStyle.LineWidth = 0;

			// Set the selected state of the line series - this reflects the initial UI state
			series.Selected = year == DisplayYear;
			return series;
		}

		public override int GetNumberOfDataPoints (ShinobiChart chart, int dataSeriesIndex)
		{
			return sales [dataSeriesIndex].Item2.Count;
		}

		public override SChartData GetDataPoint (ShinobiChart chart, int dataIndex, int dataSeriesIndex)
		{
			var data = sales [dataSeriesIndex].Item2 [dataIndex];
			return new SChartDataPoint {
				XValue = new NSString(data.Item1),
				YValue = new NSNumber(data.Item2)
			};
		}

		#endregion
	}
}

