#pragma once
#include "Point.h"

class Line
{
public:
		Line(Point pt1, Point pt2) { pts[0] = pt1; pts[1] = pt2; }
		float length() const;
		//friend class Point;	//Point --> Line.private
private:
		Point		pts[2];	//¶Ïµã
};

