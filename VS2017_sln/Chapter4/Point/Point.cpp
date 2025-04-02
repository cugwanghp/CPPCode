#include "Point.h"
#include <cmath>

Point::Point(int x, int y) : m_x(x), m_y(y)
{
	std::cout << "constructor\n";
}

Point::Point(const Point& pt) : m_x(pt.m_x), m_y(pt.m_y)
{
	std::cout << "copy constructor\n";
}

Point::Point(Point&& pt) : m_x(pt.m_x), m_y(pt.m_y)
{
	std::cout << "move constructor\n";
}

Point Point::clone()
{
		return Point(*this);		//copy constructor
}

Point Point::move(int dx, int dy)
{
	Point	pt(m_x + dx, m_y + dy);
	return pt;
}

double getDistance(const Point& pt1, const Point& pt2)	//
{
	double	dx = pt1.getX() - pt2.getX();
	double	dy = pt1.getY() - pt2.getY();
	return sqrt(dx*dx + dy * dy);
}

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	os << pt.getX() << "," << pt.getY();
	return os;
}
