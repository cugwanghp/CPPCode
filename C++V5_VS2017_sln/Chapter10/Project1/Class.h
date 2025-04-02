#pragma once
class A
{
public:
	A(int m);

	int m_a;
};

class B1 : virtual public A
{
public:
	B1(int a, int b);

	int m_b;
};

class B2 : virtual public A
{
public:
	B2(int a, int b);
	int	m_b2;
};

class C : public B1, public B2
{
public:
	C(int a, int b, int b2, int c);
	int m_c;
};