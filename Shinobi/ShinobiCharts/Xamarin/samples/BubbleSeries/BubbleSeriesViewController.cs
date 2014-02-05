//
// BubbleSeriesViewController.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Drawing;
using MonoTouch.Foundation;
using MonoTouch.UIKit;

using ShinobiCharts;

namespace BubbleSeries
{
	public partial class BubbleSeriesViewController : UIViewController
	{
		static bool UserInterfaceIdiomIsPhone {
			get { return UIDevice.CurrentDevice.UserInterfaceIdiom == UIUserInterfaceIdiom.Phone; }
		}

		ShinobiChart chart;

		public BubbleSeriesViewController ()
			: base (UserInterfaceIdiomIsPhone ? "BubbleSeriesViewController_iPhone" : "BubbleSeriesViewController_iPad", null)
		{
		}

		public override void ViewDidLoad ()
		{
			base.ViewDidLoad ();

			// Create the chart
			float margin = UserInterfaceIdiomIsPhone ? 10 : 50;
			RectangleF frame = new RectangleF (margin, margin, View.Bounds.Width - 2 * margin, View.Bounds.Height - 2 * margin);
			chart = new ShinobiChart (frame) {
				Title = "Project Commit Punchcard",
				AutoresizingMask = ~UIViewAutoresizing.None,

				LicenseKey = "", // TODO: add your trail licence key here!

				DataSource = new BubbleSeriesDataSource(),
				YAxis = new SChartCategoryAxis {
					Title = "Day",
					RangePaddingHigh = new NSNumber(0.5),
					RangePaddingLow = new NSNumber(0.5)
				},
				XAxis = new SChartNumberAxis {
					Title = "Hour",
					RangePaddingHigh = new NSNumber(0.5),
					RangePaddingLow = new NSNumber(0.5)
				}
			};

			View.AddSubview (chart);
		}

		public override bool ShouldAutorotateToInterfaceOrientation (UIInterfaceOrientation toInterfaceOrientation)
		{
			// Return true for supported orientations
			if (UserInterfaceIdiomIsPhone) {
				return (toInterfaceOrientation != UIInterfaceOrientation.PortraitUpsideDown);
			} else {
				return true;
			}
		}
	}
}

