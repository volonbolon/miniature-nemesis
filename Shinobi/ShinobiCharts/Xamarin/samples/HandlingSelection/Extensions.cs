//
// Extensions.cs
//
// Copyright 2013 Scott Logic Ltd. All rights reserved.
//
using System;
using System.Collections.Generic;
using System.Drawing;

namespace HandlingSelection
{
	public static class Extensions
	{
		public static void Add(this List<Tuple<string, double>> list, string item1, double item2)
		{
			list.Add(new Tuple<string, double>(item1, item2));
		}

		public static void Add(this List<Tuple<string, List<Tuple<string, double>>>> List, string s, List<Tuple<string, double>> data)
		{
			List.Add (new Tuple<string, List<Tuple<string, double>>> (s, data));
		}

		public static RectangleF Inset(this RectangleF rect, float margin)
		{
			return new RectangleF(rect.X + margin, rect.Y + margin, rect.Width - 2 * margin, rect.Height - 2 * margin);
		}
	}
}

