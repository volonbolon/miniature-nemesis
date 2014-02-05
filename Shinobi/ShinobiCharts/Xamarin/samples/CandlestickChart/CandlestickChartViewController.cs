//
// CandlestickChartViewController.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;
using ShinobiCharts;

namespace CandlestickChart
{
	public partial class CandlestickChartViewController : UIViewController
	{
		static bool UserInterfaceIdiomIsPhone {
			get { return UIDevice.CurrentDevice.UserInterfaceIdiom == UIUserInterfaceIdiom.Phone; }
		}

		ShinobiChart chart;

		public CandlestickChartViewController ()
			: base (UserInterfaceIdiomIsPhone ? "CandlestickChartViewController_iPhone" : "CandlestickChartViewController_iPad", null)
		{
		}

		public override void ViewDidLoad ()
		{
			base.ViewDidLoad ();

			// Create the chart
			View.BackgroundColor = UIColor.White;
			float margin = UserInterfaceIdiomIsPhone ? 10 : 50;
			RectangleF frame = new RectangleF (margin, margin, View.Bounds.Width - 2 * margin, View.Bounds.Height - 2 * margin);
			chart = new ShinobiChart (frame) {
				Title = "Apple Stock Price",
				AutoresizingMask = ~UIViewAutoresizing.None,
				LicenseKey = "" // TODO: add your trail licence key here!
			};

			// Add a discountinuous date axis
			chart.XAxis = new SChartDateTimeAxis () {
				Title = "Date",
				EnableGesturePanning = true,
				EnableGestureZooming = true
			};

			chart.YAxis = new SChartNumberAxis () {
				Title = "Price (USD)",
				EnableGesturePanning = true,
				EnableGestureZooming = true
			};

			// Add to the view
			View.AddSubview (chart);

			chart.DataSource = new CandlestickChartDataSource ();
		}
	}
}

