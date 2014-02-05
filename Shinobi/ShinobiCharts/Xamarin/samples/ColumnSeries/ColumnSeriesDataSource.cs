//
// ColumnSeriesDataSource.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using ShinobiCharts;
using System.Collections.Generic;
using MonoTouch.Foundation;

namespace ColumnSeries
{
	public class ColumnSeriesDataSource : SChartDataSource
	{
		class SalesRecord
		{
			public class Sale
			{
				public string Name { get; set; }
				public double Volume { get; set; }
			}

			public class SalesList : List<Sale>
			{
				public void Add(string name, double value) {
					this.Add (new Sale() { Name = name, Volume = value });
				}
			}

			public int Year { get; set; }
			public SalesList Sales { get; set; }
		}

		SalesRecord[] sales;

		public ColumnSeriesDataSource ()
			: base ()
		{
			sales = new SalesRecord[] {
				new SalesRecord() {
					Year = 2011,
					Sales = new SalesRecord.SalesList() {
						{ "Broccoli", 5.65 },
						{ "Carrots", 12.6 },
						{ "Mushrooms", 8.4 },
					}
				},
				new SalesRecord() {
					Year = 2012,
					Sales = new SalesRecord.SalesList() {
						{ "Broccoli", 4.35 },
						{ "Carrots", 13.2 },
						{ "Mushrooms", 8.4 },
						{ "Okra", 0.6 },
					}
				}
			};
		}

		public override int GetNumberOfSeries (ShinobiChart chart)
		{
			return sales.Length;
		}

		public override SChartSeries GetSeries (ShinobiChart chart, int dataSeriesIndex)
		{
			return new SChartColumnSeries () {
				Title = sales[dataSeriesIndex].Year.ToString()
			};
		}

		public override int GetNumberOfDataPoints (ShinobiChart chart, int dataSeriesIndex)
		{
			return sales [dataSeriesIndex].Sales.Count;
		}

		public override SChartData GetDataPoint (ShinobiChart chart, int dataIndex, int dataSeriesIndex)
		{
			return new SChartDataPoint () {
				XValue = new NSString(sales[dataSeriesIndex].Sales[dataIndex].Name),
				YValue = new NSNumber(sales[dataSeriesIndex].Sales[dataIndex].Volume)
			};
		}
	}
}

