#pragma once
#include <iostream>
#include <cassert>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};
public:
	// Constructor with two parameters, one parameter having a default value
	Fraction(int numerator = 0, int denominator = 1);
	Fraction(double val);	//double --> fraction
	~Fraction()
	{
		std::cout << "Fraction deconstructed.\n";
	}
	//Fraction f = cin;  f(cin)
	explicit Fraction(std::istream& is)
	{
		is >> m_numerator >> m_denominator;
	}

	Fraction(const Fraction& frac) : 
		m_numerator{frac.m_numerator},
		m_denominator{frac.m_denominator}
	{
		std::cout << "Fraction copy constructed.\n";
	}

//	Fraction(const Fraction&) = delete;

//	Fraction() = default;
	/*
	Fraction() // default constructor
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	
	*/
	int getNumerator() const { return m_numerator; }
	int getDenominator() const { return m_denominator; }
	double getValue() const { return static_cast<double>(m_numerator) / m_denominator; }
};

int gcd(int, int);	//greatest common devisor
std::ostream& operator<<(std::ostream& os, const Fraction& f);
Fraction MultFraction(const Fraction& frac1, const Fraction& frac2);