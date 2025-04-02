#include "Point.h"

int Point::count = 0;	//静态数据成员定义和初始化，使用类名限定

Point::Point(int x, int y) : x(x), y(y) { //构造函数
		//在构造函数中对count累加，所有对象共同维护同一个count
	count++;
}

Point::Point(Point &p) {	//复制构造函数
	x = p.x;
	y = p.y;
	count++;
}

Point::~Point()
{
	count--;
}

void
Point::showCount() {		//输出静态数据成员
	std::cout << "  Object count = " << count << std::endl;
}
