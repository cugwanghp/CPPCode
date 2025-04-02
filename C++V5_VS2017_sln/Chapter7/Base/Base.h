#pragma once
#include <string>
#include <iostream>

class Base
{
public:
	int getid() const { return m_id; }
	void print(std::ostream& out) const { out << m_id; }
private:
	int		m_id{ 1 };
	char	m_c{ 'y' };
};

class Dervied : public Base
{
public:
	double getvalue() const { return m_value; }
	int getid() const { return Base::getid() + 1; }
	void print(std::ostream& out) const { out << getid() << "\t" << m_value; }
private:
	double	m_value{ 10. };
};

class Base2
{};

class Derived2 : public Base2
{};

