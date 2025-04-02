#include "Class.h"
#include <iostream>
#include <iomanip>
using namespace std;

A::A(int m) : m_a(m) 
{
}

B1::B1(int a, int b) : A(a), m_b(b) 
{
}


B2::B2(int a, int b) : A(a), m_b2(b)
{
}

C::C(int a, int b, int b2, int c) : A(a), B1(a, b), B2(a, b2), m_c(c) 
{
}

int main()
{
	C	c(1, 2, 3, 4);
	double	 a = 3.1415926;
	cout << setw(5) << setprecision(13) << a << endl;
	cout << setw(5) << setprecision(13) << (a - 3) << endl;
	return 0;
}
