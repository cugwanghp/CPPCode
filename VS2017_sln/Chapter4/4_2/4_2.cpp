//4_2.cpp
#include <iostream>
#include "Point.h"
#include <utility>

//主程序
int main() {
	Point a(4, 5);	//第一个对象A
	Point b = a;	//情况一，用A初始化B。第一次调用复制构造函数

	std::cout << b.getX() << "," << b.getY() << std::endl;
	distance(a, b);		//情况二，对象B作为fun1的实参。第二次调用复制构造函数

	Point	rref(move(a, b));
	std::cout << rref.getX() << "," << rref.getY() << std::endl;
	Point	c = move(a, b);
	//b = move(a, b);		//情况三，函数的返回值是类对象，函数返回时，调用复制构造函数
	std::cout << b.getX() << "," << b.getY() << std::endl;

	return 0;
}
