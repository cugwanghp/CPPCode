#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	double  d;

//	cin >> d;
	Fraction    f1(55.0);

	Fraction    f2{0,-10};
//	cin >> f2;

	cout << f1 / f2 << endl;

//	cout << (f2 - f1)*(f1 + f2)/f2 << endl;

	return 0;
}