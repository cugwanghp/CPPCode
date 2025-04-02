#include <iostream>

int main()
{
	int val = 0;
	int i = 1;
	do
	{
		val += i;
	} while (++i <= 10);
	std::cout << val << std::endl;

	return 0;
}