#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	// Default constructor
	Fraction(int numerator = 0, int denominator = 1);
	Fraction(double value);
	Fraction(const Fraction&) = default;

	void normalize();   //simplify and reset fraction signed

	int getNumerator() const { return m_numerator; }
	int getDenominator() const { return m_denominator; }
	double getValue() const { return static_cast<double>(m_numerator) / m_denominator; }

	Fraction operator+(const Fraction& frac2) const;
	Fraction operator-(const Fraction& frac2) const;
	Fraction operator*(const Fraction& frac2) const;
	Fraction operator/(const Fraction& frac2) const;
	bool operator==(const Fraction& frac2) const;
	bool operator!=(const Fraction& frac2) const;
	bool operator<(const Fraction& frac2) const;
	bool operator>(const Fraction& frac2) const;
	bool operator<=(const Fraction& frac2) const;
	bool operator>=(const Fraction& frac2) const;

	friend ostream& operator<<(ostream& os, const Fraction& frac);
	friend istream& operator>>(istream& is, Fraction& frac);

private:
	void resetSign();   //reset signed fraction
	void simplify();   //simplify fraction
};

ostream& operator<<(ostream& os, const Fraction& frac);
istream& operator>>(istream& is, Fraction& frac);