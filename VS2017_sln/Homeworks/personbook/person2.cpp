#include "person2.h"


person2::person2(istream& in)
{
	in >> *this;
}

istream& operator>>(istream& in, person2& p)
{
	in >> p.m_strName >> p.m_strAddress;
	return in;
}

ostream& operator<<(ostream& out, const person2& p)
{
	out << p.m_strName << "\t" << p.m_strAddress;
	return out;
}
