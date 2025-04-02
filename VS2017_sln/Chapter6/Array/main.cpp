#include "Array.h"
#include "Matrix.h"
#include <iostream>

int main()
{
		// Test Array
		Array		d(6);

		// Test Matrix
		int			m, n;
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

