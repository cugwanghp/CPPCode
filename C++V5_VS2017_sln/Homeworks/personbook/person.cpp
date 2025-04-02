#include "person.h"
#include <iomanip>

person::person(const string& name, const string& address) :
    m_strName(name), m_strAddress(address)
{
}

person::person(const person& p) :
	m_strName(p.m_strName), m_strAddress(p.m_strAddress)
{
}

//read, write
istream& person::read(istream& in)
{
    in >> m_strName >> m_strAddress;
    return in;
}

ostream& person::write(ostream& out) const
{
	cout << m_strName << "\t" << m_strAddress;
    return out;
}

istream& operator>>(istream& in, person& p)
{
	return p.read(in);
}

ostream& operator<<(ostream& out, const person& p)
{
	return p.write(out);
}