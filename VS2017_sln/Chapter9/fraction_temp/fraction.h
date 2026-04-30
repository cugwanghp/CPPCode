#pragma once

//实现分数类fraction的功能，完成简单的运算。
//数据成员包括：分子和分母（整数）
//成员函数包括：构造函数、分数简化、分数与double的强制转换，输入输出操作符重载，分数运算（包
//括分数与分数之间的 + -*/ 运算，分数与整数的 + -*/ 运算，浮点与分数的 + -*/ 运算）
#include <iostream>
using std::ostream;
using std::istream;

class fraction
{
private:
	int numerator;	//分子
	int denominator;	//分母
public:
	fraction(int num = 0, int den = 1);
	template <typename T = double>
	fraction(T d, double eps = 1e-6);	//将浮点数转化为分数
	void simplify();	//分数简化

	operator double()const;	//分数与double的强制转换
	bool operator>(const fraction& f);

	friend ostream& operator<<(ostream& os, const fraction& f);	//输出操作符重载
	friend istream& operator>>(istream& is, fraction& f);	//输入操作符重载

	friend fraction operator+(const fraction& f1, const fraction& f2);	//分数与分数加法运算符重载
	friend fraction operator-(const fraction& f1, const fraction& f2);	//分数与分数减法运算符重载
	friend fraction operator*(const fraction& f1, const fraction& f2);	//分数与分数乘法运算符重载
	friend fraction operator/(const fraction& f1, const fraction& f2);	//分数与分数除法运算符重载

	template<typename T>
	friend fraction operator + (const fraction& f, T n);	//分数与整数和浮点数加法运算符重载

	template<typename T>
	friend fraction operator+(T n, const fraction& f);	//整数和浮点数与分数加法运算符重载

	template<typename T>
	friend fraction operator-(const fraction& f, T n);

	template<typename T>
	friend fraction operator-(T n, const fraction& f);

	template<typename T>
	friend fraction operator*(const fraction& f, T n);

	template<typename T>
	friend fraction operator*(T n, const fraction& f);

	template<typename T>
	friend fraction operator/(const fraction& f, T n);

	template<typename T>
	friend fraction operator/(T n, const fraction& f);
};

// 函数声明	
ostream& operator<<(ostream& os, const fraction& f);	//输出操作符重载
istream& operator>>(istream& is, fraction& f);	//输入操作符重载

fraction operator+(const fraction& f1, const fraction& f2);	//分数与分数加法运算符重载
fraction operator-(const fraction& f1, const fraction& f2);	//分数与分数减法运算符重载
fraction operator*(const fraction& f1, const fraction& f2);	//分数与分数乘法运算符重载
fraction operator/(const fraction& f1, const fraction& f2);	//分数与分数除法运算符重载

template<typename T>
T gcd(T a, T b)
{
	return b == 0 ? a : gcd(b, a % b);
}

template <typename T>
fraction::fraction(T d, double eps)
{
	// 否则，将d乘以10^k，其中k是小数点后位数，转换为整数
	int scale = 1;
	while (fabs(d - floor(d)) >= eps) {
		d *= 10;
		scale *= 10;
	}

	// 将整数d转换为分数numerator/denominator
	numerator = (int)d;
	denominator = scale;
	int g = gcd(numerator, denominator);  // 计算最大公约数

	numerator /= g;
	denominator /= g;
}

template<typename T>
fraction operator + (const fraction& f, T n)	//分数与整数和浮点数加法运算符重载
{
	fraction	f2(n);
	return operator+(f, f2);
}

template<typename T>
fraction operator+(T n, const fraction& f)	//整数和浮点数与分数加法运算符重载
{
	return operator+(f, n);
}

template<typename T>
fraction operator-(const fraction& f, T n)
{
	fraction	f2(n);
	return operator-(f, f2);
}

template<typename T>
fraction operator-(T n, const fraction& f)
{
	return operator-(f, n);
}

template<typename T>
fraction operator*(const fraction& f, T n)
{
	return operator*(f, fraction(n));
}

template<typename T>
fraction operator*(T n, const fraction& f)
{
	return operator*(fraction(n), f);
}

template<typename T>
fraction operator/(const fraction& f, T n)
{
	return operator/(f, fraction(n));
}

template<typename T>
fraction operator/(T n, const fraction& f)
{
	return operator/(fraction(n), f);
}
