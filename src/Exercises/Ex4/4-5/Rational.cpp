/*
 * @Description:
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 16:33:56
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 16:57:47
 */
#include "Rational.h"

Rational::Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
{
    reduce();
}

Rational::Rational(double value) : m_denominator(1)
{
    while (value != static_cast<int>(value))
    {
        value *= 10;
        m_denominator *= 10;
    }
    m_numerator = static_cast<int>(value);

    reduce();
}

Rational::Rational(double numerator, double denominator) : Rational(numerator / denominator)
{
}

Rational &Rational::operator+=(const Rational &r)
{
    m_numerator = m_numerator * r.m_denominator + m_denominator * r.m_numerator;
    m_denominator = m_denominator * r.m_denominator;
    reduce();

    return *this;
}

Rational &Rational::operator-=(const Rational &r)
{
    m_numerator = m_numerator * r.m_denominator - m_denominator * r.m_numerator;
    m_denominator = m_denominator * r.m_denominator;
    reduce();

    return *this;
}

Rational &Rational::operator*=(const Rational &r)
{
    m_numerator = m_numerator * r.m_numerator;
    m_denominator = m_denominator * r.m_denominator;
    reduce();

    return *this;
}

Rational &Rational::operator/=(const Rational &r)
{
    m_numerator = m_numerator * r.m_denominator;
    m_denominator = m_denominator * r.m_numerator;
    reduce();

    return *this;
}

Rational Rational::operator+(const Rational &r) const
{
    return Rational(m_numerator * r.m_denominator + m_denominator * r.m_numerator, m_denominator * r.m_denominator);
}

Rational Rational::operator-(const Rational &r) const
{
    return Rational(m_numerator * r.m_denominator - m_denominator * r.m_numerator, m_denominator * r.m_denominator);
}

Rational Rational::operator*(const Rational &r) const
{
    return Rational(m_numerator * r.m_numerator, m_denominator * r.m_denominator);
}

Rational Rational::operator/(const Rational &r) const
{
    return Rational(m_numerator * r.m_denominator, m_denominator * r.m_numerator);
}

Rational operator+(double value, const Rational &r)
{
    return Rational(value) + r;
}

Rational operator+(const Rational &r, double value)
{
    return operator+(value, r);
}

Rational operator+(int value, const Rational &r)
{
    return Rational(value) + r;
}

Rational operator+(const Rational &r, int value)
{
    return Rational(value) + r;
}

Rational::operator double() const
{
    return static_cast<double>(m_numerator) / m_denominator;
}

void Rational::reduce()
{
    int t, m, n;

    m = m_numerator;
    n = m_denominator;
    
    while (m % n != 0)
    {
        t = m;
        m = n;
        n = t % n;
    }

    if (n > 1)
    {
        m_numerator /= n;
        m_denominator /= n;
    }
}

std::istream &operator>>(std::istream &is, Rational &r)
{
    is >> r.m_numerator >> r.m_denominator;
    r.reduce();

    return is;
}

std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    os << r.m_numerator << "/" << r.m_denominator;
    return os;
}
