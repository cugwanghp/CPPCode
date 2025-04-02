//5_4.cpp
#include <iostream>
#include "Point.h"
using namespace std;

constexpr int Point::origin; //类外定义常量静态成员，但不可二次初始化
int main() {	//主函数
		return 0;

    Point a(4, 5);	//定义对象a，其构造函数回使count增1
    cout << "Point A: " << a.getX() << ", " << a.getY();
    a.showCount();	//输出对象个数

	const Point	pt(a);	//pt is constant 
    Point b(a);	//定义对象b，其构造函数回使count增1
    cout << "Point B: " << b.getX() << ", " << b.getY();
    b.showCount();	//输出对象个数

    return 0;
}
