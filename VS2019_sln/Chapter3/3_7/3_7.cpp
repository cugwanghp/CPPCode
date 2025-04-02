//3_7.cpp
#include <iostream>
using namespace std;

double power(double x, int n)
{
	double	val = 1.0;
	x = n > 0 ? x : 1. / x;
	n = n > 0 ? n : -n;
	
	while (n--)	val *= x;

	return val;
}

int power(int x, int n)
{
	int	val = 1;
	
	while (n--) val *= x;

	return val;
}

int fun2(int m) {
    return m * m;
}

int fun1(int x,int y) {
    return fun2(x) + fun2(y);
}

int main() {
    int a, b;
    cout << "Please enter two integers(a and b): ";
    cin >> a >> b;
    cout << "The sum of square of a and b: " << fun1(a, b) << endl;
    return 0;
}
