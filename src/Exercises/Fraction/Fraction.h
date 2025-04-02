#pragma once

#include <iostream>

class Fraction{
public:
    Fraction(int numerator=0, int denominator=1);
    explicit Fraction(double val);
    ~Fraction() = default;

    Fraction operator+(Fraction f2);

    friend std::ostream& operator<<(std::ostream& os, Fraction f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
protected:
    void reduce();
private:
    int m_numerator;
    int m_denominator;
};

std::ostream& operator<<(std::ostream& os, Fraction f);
std::istream& operator>>(std::istream& is, Fraction& f);