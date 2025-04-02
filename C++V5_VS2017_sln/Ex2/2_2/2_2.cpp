#include <iostream>

struct clock {
	int	year, month, day;
	int	hour, minute, second;

//	clock operator++(int);
};

std::ostream& operator<<(std::ostream& os, const clock& c)
{
	os << c.year << "-" << c.month << "-" << c.day << " ";
	os << c.hour << ":" << c.minute << ":" << c.second;
	return os;
}

int power(int x, int n)
{
	int	val = 1;
	x = n < 0 ? 1 / x : x;
	n = n < 0 ? -n : n;
	while (n--)
	{
		val *= x;
	}
	return val;
}

double power(double x, int n)
{
	double	val = 1;
	x = n < 0 ? 1 / x : x;
	n = n < 0 ? -n : n;
	while (n--)
	{
		val *= x;
	}
	return val;
}

int main()
{
	clock	c;
//	std::cin >> c.year >> c.month >> c.day;
//	std::cin >> c.hour >> c.minute >> c.second;

	//c = c + 10; operator+(c,10)
//	std::cout << c.year << c.month << c.day << std::endl;
//	std::cout << c << std::endl;

	int	a;
	double	b;
	int		n;

	std::cin >> a >> b >> n;

	std::cout << power(a, n) << std::endl;
	std::cout << power(b, n) << std::endl;
	//std::cout << power(c, n) << std::endl;

	return 0;
}