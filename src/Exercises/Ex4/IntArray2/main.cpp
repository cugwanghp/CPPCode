#include "IntArray2.h"
#include <iostream>

int main()
{
	int	m, n;
	std::cout << "Input a matrix row and col: ";
	std::cin >> m >> n;

	IntArray2	arr(m, n);
	std::cin >> arr;

	IntArray2	arr2(arr);
	std::cout << arr2 << std::endl;

	return 0;
}