#include "Point.h"
#include <iostream>

// 构造函数的实现
Point::Point(int xx, int yy) : x(xx), y(yy) {
	std::cout << "Calling the constructor of Point" << std::endl;
}

//复制构造函数的实现
Point::Point(const Point &p) : x(p.x), y(p.y) {
    std::cout << "Calling the copy constructor of Point" << std::endl;
}