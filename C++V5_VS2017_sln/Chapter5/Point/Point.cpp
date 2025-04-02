#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(int x, int y) : _x(x), _y(y)
{
		//Debug, 输出调试信息
		//Release
#ifdef _DEBUG
		std::cout << "Point()." << std::endl;
#endif
}

double dist(const Point& a, const Point& b)
{
		double	dx = a.getX() - b.getX();
		double	dy = a.getY() - b.getY();

		return sqrt(dx*dx + dy * dy);
}

Line::Line(int x1, int y1, int x2, int y2) : _pt1(x1, y1), _pt2(x2, y2)
{
}

double
Line::dist()
{
		double	dx = _pt1.getX() - _pt2.getX();
		double	dy = _pt1.getY() - _pt2.getY();

		return sqrt(dx*dx + dy * dy);
}