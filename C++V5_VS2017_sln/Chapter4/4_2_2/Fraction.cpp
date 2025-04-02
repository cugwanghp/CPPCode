#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	assert(denominator != 0);
	m_numerator = numerator;
	m_denominator = denominator;
	std::cout << "Fraction constructed.\n";
}

int gcd(int a, int b)
{
	int	t;
	while (a%b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return b;
}

Fraction::Fraction(double val) : m_denominator(1)
{
	while (val != int(val))
	{
		val *= 10;
		m_denominator *= 10;
	}
	m_numerator = static_cast<int>(val);

	// great common 
	int		common = gcd(m_numerator, m_denominator);
	m_numerator /= common;
	m_denominator /= common;
	std::cout << "Fraction constructed.\n";
}

Fraction MultFraction(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.getNumerator()*frac2.getNumerator(),
		frac1.getDenominator()*frac2.getDenominator());
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << f.getNumerator() << "/" << f.getDenominator();
	return os;
}