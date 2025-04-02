#include <iostream>
using namespace std;

double arctan(double x)
{
	double	val = 0.;	//result
	double	e = x;	//分子
	double	r = 1;	//分母
	double	ai = e / r;	//初始化为 x
	const double q = -x * x;

	while (ai >= 1.e-15 || ai <= -1.e-15)
	{
		val += ai;

		// update ai
		e *= q;	//-x*x
		r += 2;
		ai = e / r;
	}

	return val;
}
/*
double arctan(double x) {
    double sqr = x * x;
    double e = x;
    double r = 0;
    int i = 1;
    while (e / i > 1e-15) {
        double f = e / i;
        r = (i % 4 == 1) ? r + f : r - f;
        e = e * sqr;
        i += 2;
    }
    return r;
}
*/

#include <cstdlib>
void guessNum()
{
	int	randNum = rand()%100+1;	//1-100
	int	number;
	do {
		std::cin >> number;
		if (number < randNum)
		{
			std::cout << "The number you input is less." << std::endl;
		}
		else if (number > randNum)
		{
			std::cout << "The number you input is more." << std::endl;
		}
		else
		{
			std::cout << "your guess is right." << std::endl;
		}
	} while (number!=randNum);
}

int main() {
	guessNum();
	return 0;

	char	strNumber[128] = { "" };
	int		number = 0;
	int		i = 0;

	std::cin >> number;
	std::cin.getline(strNumber, 127);
	while (strNumber[i])
	{
		number = 10 * number + strNumber[i]-'0';
		++i;
	}
	std::cout << number << std::endl;
	return 0;

    double a = 16.0 * arctan(1 / 5.0);
    double b = 4.0 * arctan(1 / 239.0);
    //注意：因为整数相除结果取整，如果参数写1/5，1/239，结果就都是0
    cout << "PI = " << a - b << endl;
    return 0;
}
