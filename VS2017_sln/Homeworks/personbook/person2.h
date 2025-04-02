#pragma once
#include <string>
#include <iostream>
using namespace std;

struct person2
{
	string	m_strName = "";
	string	m_strAddress = "";

	person2() = default;
	explicit person2(istream& in);
};

istream& operator>>(istream& in, person2& p);
ostream& operator<<(ostream& out, const person2& p);