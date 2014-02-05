//
// PieChartDelegate.cs
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
	public class PieChartDelegate : SChartDelegate
	{
		protected override void OnToggledSelection (ShinobiChart chart, SChartRadialDataPoint dataPoint, SChartRadialSeries series, PointF pixelPoint)
		{
			Console.WriteLine ("{0} country: {1}", dataPoint.Selected ? "Selected" : "Deselected", dataPoint.Name);
		}
	}
}

