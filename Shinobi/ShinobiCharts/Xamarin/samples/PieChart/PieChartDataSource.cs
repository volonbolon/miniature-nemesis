//
// PieChartDataSource.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using System.Collections.Generic;
using ShinobiCharts;

namespace PieChart
{
	public class PieChartDataSource : SChartDataSource
	{
		List<Tuple<string, double>> countrySizes;

		public PieChartDataSource()
		{
			// create the data
			countrySizes = new List<Tuple<string, double>> {
				new Tuple<string, double>("Russia", 17),
				new Tuple<string, double>("Canada", 9.9),
				new Tuple<string, double>("USA", 9.6),
				new Tuple<string, double>("China", 9.5),
				new Tuple<string, double>("Brazil", 8.5),
				new Tuple<string, double>("Australia", 7.6)
			};
		}

		public override int GetNumberOfSeries (ShinobiChart chart)
		{
			return 1;
		}

		public override SChartSeries GetSeries (ShinobiChart chart, int dataSeriesIndex)
		{
			SChartPieSeries series = new SChartPieSeries ();
			series.SelectedStyle.Protrusion = 10;
			series.SelectionAnimation.Duration = 0.4;
			series.SelectedPosition = 0;
			return series;
		}

		public override int GetNumberOfDataPoints (ShinobiChart chart, int dataSeriesIndex)
		{
			return countrySizes.Count;
		}

		public override SChartData GetDataPoint (ShinobiChart chart, int dataIndex, int dataSeriesIndex)
		{
			return new SChartRadialDataPoint {
				Name = countrySizes[dataIndex].Item1,
				Value = countrySizes[dataIndex].Item2
			};
		}
	}
}

