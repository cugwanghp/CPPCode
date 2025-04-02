//3_2.cpp
#include <iostream>
using namespace std;

double arctan(double x)
{
	double sqr = -x * x;
	double val = 0.0;
	double z = x;
	long n = 1;
	while ((z / n) > 1.0e-15 || (z / n) < -1.0e-15);
	{
		z *= sqr;
		n += 2;
		val += z / n;
	}
	return val;
}


double arctan2(double x)
{
	double sqr = -(x * x);
	double val = 0;
	double z = x;
	int n = 1;
	do
	{
		val += z / n;
		z *= sqr;
		n += 2;
	} while ((z / n) > 1e-15 || (z / n) < -(1e-15));
	return val;
}


int main() {
	// your code goes here
	double	x = 0.0;
	cin >> x;
	while (x != 0.0)
	{
		cout << "arctan" << arctan(x) << endl;
		cout << "arctan 2" << arctan2(x) << endl;

		cin >> x;
	}

	return 0;
}
/*
#include "mymath.h"

int main() {
    int value = 0;

    cout << "Enter an 8 bit binary number: ";
    for (int i = 7; i >= 0; i--) {
        char ch;
        cin >> ch;
        if (ch == '1')
            value += static_cast<int>(power(2, i));
    }
    cout << "Decimal value is " << value << endl;
    return 0;
}
*/