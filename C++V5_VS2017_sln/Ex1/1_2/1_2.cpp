#include <iostream>

int main()
{
	int val = 0;
	for (int i = 1; i <= 10; i++)
	{
		val += i;
	}
	std::cout << val << std::endl;

	return 0;
}