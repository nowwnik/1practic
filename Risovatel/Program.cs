﻿using System;
using System.Collections.Generic;
using System.Drawing;
using GeometryTasks;

namespace GeometryPainting
{
    public static class SegmentExtensions
    {
        static DictionarySegment, Color colorDict = new DictionarySegment, Color();

        public static void SetColor(this Segment segment, Color color)
            = colorDict[segment] = color;

        public static Color GetColor(this Segment segment)
                    = colorDict.ContainsKey(segment) colorDict[segment]  Color.Black;
    }
}