#include <iostream>

int sum(int a[], int n)
{
		int	sum{ 0 };
		for (int i = 0; i<n; ++i){
		//for (const auto& e : a) {
				sum += a[i];
		}
		return sum;
}
/*
int main() {
		int	array[] = { 1,2,3,4,5,6 };
		for (const auto& e : array) {
				std::cout << e << "\t";
		}
		std::cout << std::endl;

		std::cout << sum(array, 6) << std::endl;
		return 0;
}
*/
#include "Header.h"

int			i = 0;	//文件作用域，静态static,定义--->End

void f() {		
		static int			i = 1;
		std::cout << ++i << std::endl;
		std::cout << ::i << std::endl;	//namespace
		//class, class union, class enum,
}

int main() {
		int&&		rref = 10;
		int			i = 10;
		int&		lref = i;
		std::cout << std::hex << &rref << "\t" << &lref << std::endl;

		int			j = 1;	//局部作用域{}, 从定义---
		for (; j <= 10; j++)
				f();
		std::cout << ++i << std::endl;
		f2();		//
		return 0;
}