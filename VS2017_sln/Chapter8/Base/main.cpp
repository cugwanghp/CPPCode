#include "Base.h"
#include <iostream>

int main()
{
		Circle	c(1.0);
		std::cout << c.area() << std::endl;

		Rectangle		r(3.0, 4.0);
		std::cout << r.area() << std::endl;

		Shape*	ps = &c;//基类的指针指向派生类对象的地址？？
		Shape&  rs = c;	//基类的引用指向派生类的对象
		Shape		s2 = c;	//基类的对象=派生类对象？？

		std::cout << ps->area() << std::endl;

		ps = &r;		//ps--> rectangle
		std::cout << ps->area() << std::endl;

		return 0;
}