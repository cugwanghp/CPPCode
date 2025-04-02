#include <iostream>

int main()
{
		int	num;
		std::cin >> num;

		std::cout << "百位:" << num / 100 << std::endl;
		num %= 100;

		std::cout << "十位:" << num / 10 << std::endl;
		num %= 10;

		std::cout << "个位:" << num  << std::endl;

		return 0;
}