#include <iostream>

void swap(int& a, int& b)
{
	int	t = a;
	a = b;
	b = t;
}

int main()
{
	int	x, y;
	std::cin >> x >> y;

	std::cout << x << "\t" << y << std::endl;
	swap(x, y);
	std::cout << x << "\t" << y << std::endl;

	return 0;
}