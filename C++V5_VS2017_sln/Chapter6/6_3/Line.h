#pragma once
#include "Point.h"

class Line
{
public:
		Line() = default;
		Line(int x1, int y1, int x2, int y2);
		Line(const Point& pt1, const Point& pt2);
		Line(const Point pts[], int n);		//2
		~Line() = default;

		double distance() const;
private:
		Point m_pts[2];
};

