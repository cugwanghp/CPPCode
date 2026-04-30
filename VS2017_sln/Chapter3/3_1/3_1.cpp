//3_1.cpp
#include <iostream>
using namespace std;

//计算x的n次方
double power(double x, int n) {
    double val = 1.0;
	if (n >= 0)
	{
		while (n--)
			val *= x;
		return val;
	}
	else
	{
		return 1. / power(x, -n);
	}
}
//n!
unsigned int factor(unsigned int n)
{
	if (n == 0)	return 1;
	return n * factor(n - 1);
}

//定义
int f(int a, int b) {
		int	res = 1;
		for (int i = 0; i < b; i++) {
				res = res * a;
		}
		return res;
}

int main() {
		// 输入两个整数，a^b
		int			a, b;
		int			res = 1;
		std::cin >> a >> b;
		res = f(a, b);	//调用

    cout <<  "5 to the power 2 is " << power(5, 2) << endl;
    //函数调用作为一个表达式出现在输出语句中。
    return 0;
}
