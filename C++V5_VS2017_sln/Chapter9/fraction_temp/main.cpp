/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//实现分数类fraction的功能，完成简单的运算。
//数据成员包括：分子和分母（整数）
//成员函数包括：构造函数、分数简化、分数与double的强制转换，输入输出操作符重载，分数运算（包
//括分数与分数之间的 + -*/ 运算，分数与整数的 + -*/ 运算，浮点与分数的 + -*/ 运算）
//主函数如下
#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	fraction f1(1, 2); // 表示1/2
	fraction f2(1.2 / 0.5); // 表示1.2/0.5
	fraction f3(0.6); //转换为分数3/5
	fraction f4;
	fraction f5 = f3; //拷贝构造
	cin >> f4; //输入分子，分母，并简化
	cout << f1 + f2 << endl;
	cout << f1 - f2 << endl;
	cout << f1 * f2 << endl;
	cout << f1 / f2 << endl;
	cout << f3 + 0.5 << endl; // -*/都支持
	cout << 0.5 + f3 << endl; // -*/都支持
	cout << f4 + 1 << endl;
	cout << 1 + f4 << endl;
	cout << double(f5) + 0.5 << endl;
	return 0;
}