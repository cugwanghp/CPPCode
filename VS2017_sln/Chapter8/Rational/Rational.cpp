#include <iostream>
#include <stdexcept> // 用于异常处理
#include "Rational.h"

// 最大公约数函数
static int gcd(int a, int b) {
		while (b != 0) {
				int temp = b;
				b = a % b;
				a = temp;
		}
		return a;
}

// 辅助函数：约分
void Rational::simplify() {
		if (den == 0) throw std::invalid_argument("分母不能为零");
		if (num == 0) {
				den = 1;
				return;
		}
		int common = gcd(num, den);
		num /= common;
		den /= common;
		if (den < 0) { // 确保分母始终为正
				num = -num;
				den = -den;
		}
}

// 构造函数
Rational::Rational(int n, int d) : num(n), den(d) {
		simplify();
}

// --- 1. 赋值运算符 (必须是成员函数) ---
Rational& Rational::operator=(const Rational& rhs) {
		if (this != &rhs) { // 自我赋值检查
				this->num = rhs.num;
				this->den = rhs.den;
		}
		return *this; // 返回引用支持链式赋值 a = b = c
}

// --- 2. 复合赋值运算符 (建议成员函数) ---
Rational& Rational::operator+=(const Rational& rhs) {
		num = num * rhs.den + rhs.num * den;
		den = den * rhs.den;
		simplify();
		return *this;
}

// --- 3. 自增/自减运算符 ---
// 前置 ++ (如 ++r)
Rational& Rational::operator++() {
		num += den; // 有理数加1即分子加分母
		return *this;
}

// 后置 ++ (如 r++)
Rational Rational::operator++(int) {
		Rational temp = *this; // 先备份原值
		++(*this);             // 调用前置++完成逻辑
		return temp;           // 返回备份
}

// --- 6. 类型转换运算符 ---
Rational::operator double() const {
		return static_cast<double>(num) / den;
}

// --- 4. 算术运算符 (全局函数实现，支持对称性) ---
Rational operator+(Rational lhs, const Rational& rhs) {
		lhs += rhs; // 利用已有的 += 实现
		return lhs;
}

Rational operator-(Rational lhs, const Rational& rhs) {
		lhs.num = lhs.num * rhs.den - rhs.num * lhs.den;
		lhs.den = lhs.den * rhs.den;
		lhs.simplify();
		return lhs;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
		return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

// --- 5. 关系运算符 ---
bool operator==(const Rational& lhs, const Rational& rhs) {
		return lhs.num == rhs.num && lhs.den == rhs.den;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
		return lhs.num * rhs.den < rhs.num * lhs.den;
}

// --- 7. 输入输出流 (必须全局) ---
std::ostream& operator<<(std::ostream& os, const Rational& r) {
		if (r.den == 1) os << r.num; // 整数形式
		else os << r.num << "/" << r.den;
		return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
		int n, d;
		char slash;
		is >> n >> slash >> d; // 假设输入格式为 "1/2"
		if (is) {
				r = Rational(n, d);
		}
		return is;
}
