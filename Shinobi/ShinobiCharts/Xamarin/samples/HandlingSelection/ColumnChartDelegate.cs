//
// ColumnChartDelegate.cs
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
	class ColumnChartDelegate : SChartDelegate
	{
		public delegate void ToggledSelectionEventHandler (ShinobiChart chart, SChartSeries series, SChartDataPoint dataPoint, PointF pixelPoint);

		public event ToggledSelectionEventHandler ToggledSelection;

		protected override void OnToggledSelection (ShinobiChart chart, SChartSeries series, SChartDataPoint dataPoint, PointF pixelPoint)
		{
			if (ToggledSelection != null) {
				ToggledSelection (chart, series, dataPoint, pixelPoint);
			}
		}
	}
}

