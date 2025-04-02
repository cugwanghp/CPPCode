#include "Point.h"
#include <iostream>

Point::Point(int xx, int yy) : x(xx), y(yy)
{
	std::cout << "Calling the constructor" << std::endl;
}

//成员函数的实现
Point::Point(const Point &p) : x(p.x), y(p.y)
{
	std::cout << "Calling the copy constructor" << std::endl;
}

Point::Point(Point&& p) : x(p.x), y(p.y)
{
	p.x = p.y = 0;
	std::cout << "Calling the move constructor" << std::endl;
}
//形参为Point类对象的函数
double distance(const Point& p1, const Point& p2) {
	double	dx = p1.getX() - p2.getX();
	double	dy = p1.getY() - p2.getY();

	return sqrt(dx*dx + dy * dy);
}

//返回值为Point类对象的函数
Point move(const Point& p1, const Point& p2) {
	Point pt(p1.getX()+p2.getX(), p1.getY()+p2.getY());
	return pt;
}