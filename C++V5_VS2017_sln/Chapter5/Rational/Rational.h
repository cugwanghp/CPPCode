#pragma once
#include <iostream>

class Rational
{
public:
		Rational(int numerator = 0, int denominator = 1);
		Rational(double value);
		Rational(double numerator, double denominator);
		Rational(const Rational& r) = default;
		Rational(Rational&& r) = default;
		~Rational() = default;

		Rational& operator=(const Rational& r) = default;
		Rational& operator=(Rational&& r) = default;

		Rational& operator+=(const Rational& r);
		Rational& operator-=(const Rational& r);
		Rational& operator*=(const Rational& r);
		Rational& operator/=(const Rational& r);

		Rational operator+(const Rational& r) const;
		Rational operator-(const Rational& r) const;
		Rational operator*(const Rational& r) const;
		Rational operator/(const Rational& r) const;

		operator double() const;

		friend std::istream& operator>>(std::istream& is, Rational& r);
		friend std::ostream& operator<<(std::ostream& os, const Rational& r);

protected:
		void reduce();

private:
		int  m_numerator;
		int  m_denominator;
};

std::istream& operator>>(std::istream& is, Rational& r);
std::ostream& operator<<(std::ostream& os, const Rational& r);

Rational operator+(double value, const Rational& r);
Rational operator+(const Rational& r, double value);
Rational operator+(int value, const Rational& r);
Rational operator+(const Rational& r, int value);
