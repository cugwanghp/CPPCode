#include "fun.h"
#include <cmath>

float dist(Point &p1, Point &p2) {	//函数实现
		double x = p1.x - p2.x;	//通过对象访问私有数据成员
		double y = p1.y - p2.y;
		return static_cast<float>(sqrt(x * x + y * y));
}