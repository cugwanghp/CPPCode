#include <iostream>
using namespace std;

double circleArea(double);	//
double getPI();
double arctan(double);

int main()
{
	double	radius;
	
	cout << "Input a circle radius (0-exit): ";
	cin >> radius;

	while (radius > 0.)
	{
		cout << "cirle area = " << circleArea(radius) << endl;

		cout << "Input a circle radius (0-exit): ";
		cin >> radius;
	}

	return 0;
}

double circleArea(double radius)
{
	return getPI() * radius*radius;
}

double getPI()
{
	return 16.*arctan(0.2) - 4 * arctan(1. / 239.);
}

double arctan(double x)
{
	//x-x^3/3
	double		val = 0.0;
	double		v1 = x;
	long		n = 1;
	while (v1 / n >= 1.0e-15 || v1 / n <= -1.0e-15)
	{
		val += v1 / n;
		v1 *= -x*x;
		n += 2;
	}
	return val;
}