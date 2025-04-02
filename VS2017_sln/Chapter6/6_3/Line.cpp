#include "Line.h"
#include <iostream>
#include <cmath>
//#include "Point.cpp"		//error
Line::Line(int x1, int y1, int x2, int y2) : 
		m_pts{Point(x1,y1), Point(x2,y2)}
{
		std::cout << std::endl;
}

Line::Line(const Point& pt1, const Point& pt2) :
		m_pts{pt1, pt2}
{
}

Line::Line(const Point pts[], int n) :
		m_pts{pts[0], pts[1]}
{
}

extern double distanceOfPoints(const Point& pt1, const Point& pt2);

double Line::distance() const
{
		return distanceOfPoints(m_pts[0], m_pts[1]);
		//double	dx = m_pts[0].getX() - m_pts[1].getX();
		//double	dy = m_pts[0].getY() - m_pts[1].getY();
		//return sqrt(dx*dx + dy * dy);
}