#include <iostream>
#include "Array.hpp"

int main()
{
		int			n;
		std::cin >> n;
		Array<int>		ary(n);
		Array<double>		ary2(n);
		for (int i = 0; i < n; i++)
				std::cin >> ary[i];			//operator[]

		StaticArray<int, 20>	ary2();	// n 是一个变量
		int			a[20];
		// ary2 对象， 成员函数
		return 0;
}