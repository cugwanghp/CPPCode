#include <iostream>
#include <cmath>

void testEx3();
void testEx7();
void testEx8();

int main()
{
//	testEx3();
//	testEx7();
	testEx8();

	return 0;
}

// calculate the area of shapes
void testEx3()
{
	int	typeGraphic;	//1-Triangle，2-Circle，3-Rectangle，4-Square
	double	area;
	constexpr double PI = 3.1415926;

	do {
		std::cin >> typeGraphic;
		switch (typeGraphic)
		{
		case 1:
		{
			//计算三角形面积
			double	a, b, c;
			double	s;
			std::cout << "输入三角形三边长：";
			do {
				std::cin >> a >> b >> c;
			} while (a <= 0 || b <= 0 || c <= 0 || (a + b) <= c || (a + c) <= b || (b + c) <= a);
			s = (a + b + c) / 2;
			area = sqrt(s*(s - a)*(s - b)*(s - c));
			std::cout << "三角形面积：" << area << std::endl;
		}
		break;

		case 2:
		{
			//计算圆面积
			double	radius;
			std::cout << "输入圆半径：";
			std::cin >> radius;
			area = PI * radius*radius;
			std::cout << "圆面积：" << area << std::endl;
		}
		break;

		case 3:
		{
			//计算长方形面积
			double	width, height;
			std::cout << "输入长方形长和宽：";
			std::cin >> width >> height;
			area = width * height;
			std::cout << "长方形面积：" << area << std::endl;
		}
		break;

		case 4:
		{
			//计算正方形面积
			double	sideLen;
			std::cout << "输入正方形边长：";
			std::cin >> sideLen;
			area = sideLen * sideLen;
			std::cout << "正方形面积: " << area << std::endl;
		}
		break;

		default:
			//错误的图形类型，输入1-Triangle，2-Circle，3-Rectangle，4-Square
			std::cout << "Input valid shape type: 1-Triangle，2-Circle，3-Rectangle，4-Square" << std::endl;
			break;
		}
	} while (typeGraphic < 1 || typeGraphic>4);
}

//菲波拉契数列
void testEx7()
{
	int		n = 20;
	int		a0 = 0, a1 = 1;
	std::cout << a0 << "," << a1;
	for (int i = 2; i <= n; ++i)
	{
		a1 = a0 + a1;	//a0+a1 ==> a1
		a0 = a1 - a0;	//a1 ==> a0
		std::cout << "," << a1;
	}
	std::cout << std::endl;
}

//哥德巴赫猜想（任何充分大的偶数都可由两个素数之和表示）。将 4 - 100 中的所有偶数分别用两个素数之和表示。
void testEx8()
{
	for (int n = 4; n <= 100; n += 2)
	{
		int		i, j;
		for (i = 2; i < n; i++)
		{
			if (n%i == 0)
				break;
		}

		if (i == n)	//n is primer
		{
			for (j = 2; j < n - i; j++)
			{
				if ((n - i) % j == 0)
					break;
			}
			if (j == n - i)	//j is primer
			{
				std::cout << n << "=" << i << "+" << j << std::endl;
			}
		}
	}
}