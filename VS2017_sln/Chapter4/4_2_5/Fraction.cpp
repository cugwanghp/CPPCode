#include "Fraction.h"
#include <cassert>
#include <cmath>

// Default constructor
Fraction::Fraction(int numerator, int denominator)
{
	assert(denominator != 0);

	m_numerator = numerator;
	m_denominator = denominator;
	normalize();
}

Fraction::Fraction(double value)
{
	int base = 1;
	while (value != static_cast<int>(value))
	{
		value *= 10;
		base *= 10;
	}

	m_numerator = static_cast<int>(value);
	m_denominator = base;

	normalize();
}

void	//simplify and reset fraction signed
Fraction::normalize()
{
	simplify();		//simplify fraction
	resetSign();   //reset signed fraction;
}

void  //normalize fraction signed
Fraction::resetSign()
{
	if (m_numerator*m_denominator >= 0)
	{
		m_numerator = abs(m_numerator);
		m_denominator = abs(m_denominator);
	}
	else
	{
		m_numerator = -abs(m_numerator);
		m_denominator = abs(m_denominator);
	}
}

void    //simplify fraction
Fraction::simplify()
{
	// max common fractor
	int     m = abs(m_numerator);
	int     n = abs(m_denominator);
	int     t;

	if (m == 0 || n == 0)	// 0/n ==> 0/1
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	else // simplify
	{
		// m is maximum, n is minimum
		if (m < n)
		{
			t = m;
			m = n;
			n = t;
		}
		
		while (m%n != 0)
		{
			t = n;
			n = m % n;
			m = t;
		}

		if (n > 1)
		{
			m_numerator /= n;
			m_denominator /= n;
		}
	}
}

Fraction
Fraction::operator+(const Fraction& frac2) const
{
	Fraction    frac{ m_numerator*frac2.m_denominator + frac2.m_numerator*m_denominator,
					  m_denominator*frac2.m_denominator };
	frac.normalize();
	return frac;
}

Fraction Fraction::operator-(const Fraction& frac2) const
{
	Fraction    frac{ m_numerator*frac2.m_denominator - frac2.m_numerator*m_denominator,
					  m_denominator*frac2.m_denominator };
	frac.normalize();
	return frac;
}

Fraction Fraction::operator*(const Fraction& frac2) const
{
	Fraction    frac{ m_numerator*frac2.m_numerator, m_denominator*frac2.m_denominator };
	frac.normalize();
	return frac;
}

Fraction Fraction::operator/(const Fraction& frac2) const
{
	assert(frac2.m_numerator != 0);

	Fraction    frac{ m_numerator*frac2.m_denominator, m_denominator*frac2.m_numerator };
	frac.normalize();
	return frac;
}

bool Fraction::operator==(const Fraction& frac2) const
{
	return (m_numerator*frac2.m_denominator == m_denominator * frac2.m_numerator);
}

bool Fraction::operator!=(const Fraction& frac2) const
{
	return !(*this == frac2);
}

bool Fraction::operator<(const Fraction& frac2) const
{
	return (m_numerator*frac2.m_denominator < m_denominator*frac2.m_numerator);
}

bool Fraction::operator>(const Fraction& frac2) const
{
	return (m_numerator*frac2.m_denominator > m_denominator*frac2.m_numerator);
}

bool Fraction::operator<=(const Fraction& frac2) const
{
	return (m_numerator*frac2.m_denominator <= m_denominator * frac2.m_numerator);
}

bool Fraction::operator>=(const Fraction& frac2) const
{
	return (m_numerator*frac2.m_denominator >= m_denominator * frac2.m_numerator);
}

ostream& operator<<(ostream& os, const Fraction& frac)
{
	os << frac.m_numerator << "/" << frac.m_denominator;
	return os;
}

istream& operator>>(istream& is, Fraction& frac)
{
	is >> frac.m_numerator >> frac.m_denominator;
	frac.normalize();
	return is;
}