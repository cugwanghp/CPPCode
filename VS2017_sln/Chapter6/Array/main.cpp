#include "Array.h"
#include "Matrix.h"
#include <iostream>
#include <memory>

int main()
{
	Array	a(6);	//6个元素的数组
	Array	b(a);	//拷贝构造函数

	return 0;

		// Test Matrix
		int			m;
		std::cout << "Input Matrix's row, col and data: ";
		std::cin >> m >> n;
		Matrix	m1(m, n);
		for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
						std::cin >> m1[i][j];
				}
		}

		Matrix	m2 = m1.transpose();
		m2.print(std::cout);
		std::cout << std::endl;

		return 0;
}

