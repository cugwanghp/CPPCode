#include "Complex.h"

Complex Complex::operator++(int)				//c++,返回对象
{
		Complex	c = *this;
		this->m_img += 1;
		this->m_real += 1;
		return c;
}

Complex& Complex::operator++()		//++c，返回引用
{
		this->m_img += 1;
		this->m_real += 1;
		return *this;
}

std::ostream& operator<<(std::ostream& os, Complex c)
{
		os << c.m_real << std::showpos << c.m_img << std::noshowpos<< "i";
		return os;
}

Complex Complex::operator+(Complex c2)
{
		//隐藏了一个 this指针
		return Complex(this->m_real + c2.m_real, this->m_img + c2.m_img);
}

// 函数的实现
int add(int a, int b)		//a,b 形参
{
		return a + b;
}

Int::Int(int val) : m_val(val) {

}

void Int::print()
{
		std::cout << m_val << std::endl;
}

//函数的实现
//y=f(x) x-形参， f(1) f(x)=x*x;
void print(Int* ptr) {
		std::cout << ptr->m_val << std::endl;		}