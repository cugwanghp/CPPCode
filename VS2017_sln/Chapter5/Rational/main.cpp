#include <iostream>
#include "rational.h" // class Rational

int main()
{
		Rational f1(1, 2); // 表示1/2
		Rational f2(1.2, 0.5); // 表示1.2/0.5
		Rational f3(0.6); //转换为分数3/5
		Rational f4;
		Rational f5 = f3; //拷贝构造
		std::cin >> f4; //输入分子，分母，并简化

		std::cout << f1 + f2 << std::endl;
		std::cout << f1 - f2 << std::endl;
		std::cout << f1 * f2 << std::endl;
		std::cout << f1 / f2 << std::endl;

		std::cout << f3 + 0.5 << std::endl; // -*/都支持
		std::cout << 0.5 + f3 << std::endl; // -*/都支持

		std::cout << f4 + 1 << std::endl;
		std::cout << 1 + f4 << std::endl;
		std::cout << double(f5) + 0.5 << std::endl;

		return 0;
}
