#include "fraction.h"
#include <iostream>
#include <cmath>
using namespace std;

fraction::fraction(int num, int den)
{
	if (den == 0)
	{	//分母为0抛出异常
		throw invalid_argument("Denominator cannot be zero.");
	}
	auto g = gcd(abs(num), abs(den));
	numerator = num / g;
	denominator = den / g;
	//如果分母为负数，则将分子、分母同时取相反数
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}

void fraction::simplify()
{
	if (numerator != 0) {
		int g = gcd(abs(numerator), denominator);   // 计算最大公约数
		numerator /= g;
		denominator /= g;
		// 如果分母为负数，则将分子、分母同时取相反数
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}
	else {
		denominator = 1;
	}
}

fraction::operator double()const
{
	return (double)numerator /(double)denominator;
}

bool fraction::operator>(const fraction& f)
{
		return double(*this) > double(f);
}
ostream& operator<<(ostream& os, const fraction& f)
{
	os << f.numerator << "/" << f.denominator;
	return os;
}

istream& operator>>(istream& is, fraction& f)	//输入操作符重载
{
	is >> f.numerator >> f.denominator;
	f.simplify();

	return is;
}

fraction operator+(const fraction& f1, const fraction& f2)	//分数与分数加法运算符重载
{
	return fraction(f1.numerator*f2.denominator + f2.numerator*f1.denominator,
		f1.denominator*f2.denominator);
}

fraction operator-(const fraction& f1, const fraction& f2)	//分数与分数减法运算符重载
{
	return fraction(f1.numerator*f2.denominator - f2.numerator*f1.denominator,
		f1.denominator*f2.denominator);
}

fraction operator*(const fraction& f1, const fraction& f2)	//分数与分数乘法运算符重载
{
	return fraction(f1.numerator*f2.numerator, f1.denominator*f2.denominator);
}

fraction operator/(const fraction& f1, const fraction& f2)	//分数与分数除法运算符重载
{
	return fraction(f1.numerator*f2.denominator, f1.denominator*f2.numerator);
}