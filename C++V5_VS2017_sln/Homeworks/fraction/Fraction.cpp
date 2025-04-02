#include "Fraction.h"
#include <cmath>

fraction::fraction(long numerator, long denominator)
 : m_numerator(numerator), m_denominator(denominator)
{
    reduce();
}

fraction::fraction(double value)
{
    //
    long    scale = 1;
    while(value*scale != (long)(value*scale))
    {
        scale *= 10;
    }
    m_numerator = (long)(value*scale);
    m_denominator = scale;
    
    reduce();
    
}

fraction::fraction(const fraction& f)
: m_numerator(f.m_numerator), m_denominator(f.m_denominator)
{

}

ostream& operator<<(ostream& os, const fraction& f) //num/denom
{
    os << f.m_numerator << "/" << f.m_denominator;
	return os;
}

fraction::operator double()
{
    return double(m_numerator)/m_denominator;
}

void fraction::reduce()
{
    auto    m = abs(m_numerator);
    auto    n = abs(m_denominator);
    long    t;
	
    while(m%n != 0)
    {
        t = m % n;
        m = n;
        n = t;
    }
	
    m_numerator /= n;
    m_denominator /= n;   
}

//------------------------ caculation operator ---------------------//
fraction fraction::operator+(const fraction& f2)
{
	return fraction(m_numerator*f2.m_denominator + m_denominator * f2.m_numerator,
		m_denominator*f2.m_denominator);
}

fraction fraction::operator-(const fraction& f2)
{
	return fraction(m_numerator*f2.m_denominator - m_denominator * f2.m_numerator,
		m_denominator*f2.m_denominator);
}

fraction fraction::operator*(const fraction& f2)
{
	return fraction(m_numerator*f2.m_numerator,
		m_denominator*f2.m_denominator);
}

fraction fraction::operator/(const fraction& f2)
{
	return fraction(m_numerator*f2.m_denominator,
		m_denominator*f2.m_numerator);
}

istream& operator>>(istream& in, fraction& f)
{
	in >> f.m_numerator >> f.m_denominator;	//·Ö×Ó£¬·ÖÄ¸
	f.reduce();
	return in;
}