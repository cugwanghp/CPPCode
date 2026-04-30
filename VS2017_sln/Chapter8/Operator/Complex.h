#pragma once
#include <iostream>

class Complex {
public:
		Complex(double real, double img) : m_real(real), m_img(img) {}
		~Complex() = default;
		
		//运算符函数重载为Complex类的成员函数
		Complex operator+(Complex c2);	//+
		Complex& operator++();			//++c
		Complex operator++(int);		//c++

		//声明友元函数
		friend std::ostream& operator<<(std::ostream&, Complex);
private:
		double	m_real, m_img;	//
};

std::ostream& operator<<(std::ostream&, Complex);		//重载<<函数

int add(int, int);	//函数的原型声明,*.h头文件

class Int {
public:
		Int(int val);
		~Int() = default;
		void print();
		int	m_val;
};

void print(Int*);		//函数原型