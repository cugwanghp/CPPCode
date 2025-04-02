#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction frac{1,2}; // calls Fraction() default constructor
//	Fraction frac2;	// calls default constructor
	Fraction frac3(3,4);	//
//	Fraction frac4 = frac2;
//	Fraction frac5(frac2);
//	Fraction frac6{ frac2 };
//	Fraction frac7 = 5;
//	Fraction frac8 = Fraction{ 2,1 };
//	Fraction frac9(std::cin);
	Fraction frac9 = MultFraction(frac, frac3);
	Fraction	f2 = 0.4;
	Fraction	f3(0.5);

	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << frac << std::endl;
	std::cout << frac9 << std::endl;
	//std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';
	//std::cout << frac9.getNumerator() << '/' << frac9.getDenominator() << '\n';

	/*
	Fraction fiveThirds{ 5, 3 }; // List initialization, calls Fraction(int, int)
	Fraction threeQuarters(3, 4); // Direct initialization, also calls Fraction(int, int)

	Fraction six = Fraction{ 6 }; // Copy initialize a Fraction, will call Fraction(6, 1)
	Fraction seven = 7; // Copy initialize a Fraction.  The compiler will try to find a way to convert 7 to a Fraction, which will invoke the Fraction(7, 1) constructor.
	*/
	return 0;
}