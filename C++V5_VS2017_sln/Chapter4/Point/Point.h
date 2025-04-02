#pragma once

#include <iostream>

class Point
{
public:
	Point(int x=0, int y=0);
	Point(const Point& pt);
	Point(Point&& pt);
	Point clone();

	Point move(int dx, int dy);

	int getX() const { return m_x; }
	int getY() const { return m_y; }
private:
	int	m_x, m_y;
};

double getDistance(const Point& pt1, const Point& pt2);	//

std::ostream& operator<<(std::ostream& os,const Point& pt);
