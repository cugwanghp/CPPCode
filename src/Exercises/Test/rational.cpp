#include "rational.h"
#include <iostream>

rational::rational(int a , int b ) {
	int z,k,j;
	z = gongyue(a, b);
		k = a / z;
		j = b / z;
		m_nu= k;
		m_de = j;
}

rational::rational(double a) {
	m_de = 1;
	while(a != (int)a){
		a *= 10;
		m_de *= 10;
	}
	m_nu = (int)a;

	int gcd = gongyue(m_nu, m_de);
	m_nu /= gcd;
	m_de /= gcd;
}

rational::rational(const rational& rat) {
	m_nu = rat.m_nu;
	m_de= rat.m_de;

}
rational::rational(rational&& rat) {
	m_nu = rat.m_nu;
	m_de = rat.m_de;
	rat.m_nu=0;
	rat.m_nu=0;
}

rational::~rational()
{
}

rational rational::operator+(rational& rat) {
	int a, b,a1,b1,w;
	a = this->m_nu * rat.m_de+m_de*rat.m_nu;
	b = this->m_nu * rat.m_de;
	w = gongyue(a, b);
		a1 = a / w;
		b1 = b / w;
		m_nu = a1;
		m_de = b1;
}

rational rational::operator-(rational& rat) {
	int a, b, a1, b1, w;
	a = this->m_nu * rat.m_de - m_de * rat.m_nu;
	b = this->m_nu * rat.m_de;
	w = gongyue(a, b);
	a1 = a / w;
	b1 = b / w;
	m_nu = a1;
	m_de = b1;
}

rational rational::operator*(rational& rat){
	int a, b, a1, b1, w;
	a = this->m_nu* rat.m_nu;
	b = this->m_de * rat.m_de;
	w = gongyue(a, b);
	a1 = a / w;
	b1 = b / w;
	m_nu = a1;
	m_de = b1;
}

rational rational::operator/(rational& rat){
	int a, b, a1, b1, w;
	a = this->m_nu * rat.m_de;
	b = this->m_de * rat.m_nu;
	w = gongyue(a, b);
	a1 = a / w;
	b1 = b / w;
	m_nu = a1;
	m_de = b1;
}

double rational::turn()const {
	double a, b,z;
	a = double(m_nu);
	b = double(m_de);
	z = a / b;
	return z;
}

std::ostream& operator<<(std::ostream& os, rational& rat) {
	os << rat.m_nu << "/" << rat.m_de;
	return os;
}

std::istream& operator>>(std::istream& in, rational& rat) {
	in >> rat.m_nu >> rat.m_de;
	return in;
}

int gongyue(int a, int b) {
	int z, i;
	z = a > b ? b : a;
	for (i = z;i > 1;i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			break;
		}
	}
	return i;
}
