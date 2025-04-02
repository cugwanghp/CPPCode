#include <iostream>

bool isPrimer(int n);
double power(double, int);

int fab(int n);	//函数的声明
int fab2(int n);

double power(double x, int n)
{
	double	val = 1.0;
	//x^1 = 1.0*x;
	//x^2 = 1.0*x*x
	for (int i = 0; i < n; i++)
		val *= x;
	//n,n-1,n-2,1(n次循环),0(结束）
	while (n!=0)	//when n>0, n-ture, n=0,n-false
	{
		val *= x;
		n--;
	}
	return val;
}

bool isPrimer(int n)
{
	if (n <= 1)	return false;
	int		i;
	for (i = 2; i < n; i++)
		if (n%i == 0)
			break;
	return i == n;
}

int main()
{
	//Win + Left,right arrow
	int		n, i;
	for (n = 4; n <= 100; n += 2)
	{
		for (i = 2; i < n; i++)
		{
			if (isPrimer(i) && isPrimer(n - i))
			{
				std::cout << n << "=" << i << "+" << n - i << std::endl;
				break;
			}
		}
	}
	return 0;
}

int fab(int n)
{
	if (n<=1) return n;
	return fab(n - 1) + fab(n - 2);
}

int fab2(int n)
{
	//a0=0, a1=1, a2=a0+a1, a2=a1+a2
	if (n <= 1) return n;

	int	a0=0, a1=1;
	for (int i = 1; i < n; i++)
	{
		//ai, ai-1, ai-2
		//a2 = a0+a1;
		//a3 = a1+a2;//a0+a1==>a1, a1==>a0
		a1 = a0 + a1;
		a0 = a1 - a0;
	}
	return a1;
}
	//a0=0, a1=1, a2=1, a3=2, a4=3
	//a0=0, a1=1, a2=a0+a1, a3=a2+a1, a4=a2+a3

	/*	int		val = 0;
	char	ch;

	for (int i = 7; i >= 0; --i)
	{
		std::cin >> ch;	//0 or 1
		val += (ch - '0') * power(2, i);
		val = val * 2 + (ch - '0');
	}
	std::cout << val << std::endl;

	//控制台输入0，1，直到输入的字符非0 和 1时，结束，计算二进制的值
	val = 0;
	std::cin >> ch;
	while (ch == '0' || ch == '1') {
		val = 2 * val + ch - '0';
		std::cin >> ch;
	} 
	std::cout << val << std::endl;
	return 0;

	double	x;
	int		n;
	std::cin >> x >> n;
	std::cout << power(x, n) << std::endl;
	return 0;

	for (int n = 4; n <= 100; n += 2)
	{
		for (int m = 2; m < n; ++m)
		{
			if(isPrimer(m) && isPrimer(n - m))
			{
			std::cout << n << "=" << m << "+" << n - m << std::endl;
			}
		}
	}
	return 0;
}

bool isPrimers(int m, int n)
{
	return isPrimer(m) && isPrimer(n);
}
bool isPrimer(int n)
{
	int	i;
	for (i = 2; i < n; ++i)
	{
		if (n%i == 0)
			break;
	}
	return i == n;
}

int fab(int n)
{
	//a0 = 0, a1=1, a2=a0+a1, a3=a2+a1
	//fab(0), fab(1), fab(2), fab(3)
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fab(n - 1) + fab(n - 2);
}

double power(double x, int n)
{
	double	val = 1.0;

	x = n > 0 ? x : 1. / x;

	for (int i = 0; i < (n>0?n:-n); i++)
		val *= x;

	return val;
}

double power2(double x, int n)
{
	if (n == 0)
		return 1.0;

	return power2(x, n - 1)*x;
}
*/