#include <iostream>
#include "Array.hpp"
#include "StaticArray.hpp"

void testStaticArray()
{
		// Declare an char array of size 14
		StaticArray<char, 14> char14{};	//数据+函数，对象化
		char		a[14];	//仅仅定义数据
		//strcpy_s(char14.getArray(), 14, "Hello, world!");

		// Print the array
		std::cout << char14 << std::endl;

		// Now declare an char array of size 12
		StaticArray<char, 12> char12{};

		//strcpy_s(char12.getArray(), 12, "Hello, mom!");

		// Print the array
		std::cout << char12 << std::endl;

		StaticArray<int, 4>	int6;
		int6[0] = 1;		int6[1] = 2;
		int6[2] = 2;		int6[3] = 3;
		std::cout << int6 << std::endl;
}

int main()
{
		testStaticArray();
		return 0;

		int			n;
		std::cin >> n;
		Array<int>		ary(n);
		Array<double>		ary2(n);
		for (int i = 0; i < n; i++)
				std::cin >> ary[i];			//operator[]
		return 0;
}