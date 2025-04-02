#include "mymath.h"

double power(double x, int n) {
	double val = 1.0;
	while (n--)
		val *= x;
	return val;
}