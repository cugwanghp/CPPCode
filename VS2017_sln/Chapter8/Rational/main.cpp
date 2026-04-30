#include "Rational.h"
#include <iostream>

// --- Main 用例展示 ---
int main() {
		try {
				Rational r1(1, 2); // 1/2
				Rational r2(1, 3); // 1/3

				std::cout << "r1: " << r1 << ", r2: " << r2 << std::endl;

				// 算术运算
				Rational r3 = r1 + r2;
				std::cout << "r1 + r2 = " << r3 << " (应为 5/6)" << std::endl;

				Rational r4 = r1 - r2;
				std::cout << "r1 - r2 = " << r4 << " (应为 1/6)" << std::endl;

				// 混合运算（利用隐式构造函数 int -> Rational）
				Rational r5 = r1 + 2;
				std::cout << "r1 + 2 = " << r5 << " (应为 5/2)" << std::endl;

				// 复合赋值
				r1 += r2;
				std::cout << "执行 r1 += r2 后, r1 = " << r1 << std::endl;

				// 自增演示
				std::cout << "当前 r1: " << r1 << std::endl;
				std::cout << "后置 r1++ 返回: " << r1++ << std::endl;
				std::cout << "后置之后 r1 为: " << r1 << std::endl;
				std::cout << "前置 ++r 返回: " << ++r1 << std::endl;

				// 比较运算
				Rational a(1, 4), b(2, 8);
				std::cout << a << " == " << b << " ? " << (a == b ? "Yes" : "No") << std::endl;

				// 类型转换
				double val = static_cast<double>(r1);
				std::cout << "r1 的浮点数值: " << val << std::endl;

				// 异常处理
				std::cout << "尝试创建分母为0的有理数..." << std::endl;
				Rational bad(1, 0);

		}
		catch (const std::exception& e) {
				std::cerr << "错误: " << e.what() << std::endl;
		}

		return 0;
}
