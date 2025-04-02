#include <iostream>
#include <cmath>    //sqrt

constexpr double PI = 3.14159265358979323846;

int main()
{
	int     shapeType = 0;
	double  areaShape = 0.0;

	std::cin >> shapeType;
	switch (shapeType)
	{
	case 1: //Triangle
	{ //local variable
		double  a, b, c, s;
		do {
			std::cin >> a >> b >> c;
			if (a + b > c && a + c > b && b + c > a)
			{
				s = (a + b + c) / 2.;
				areaShape = sqrt(s*(s - a)*(s - b)*(s - c));
				std::cout << "Triangle Area:" << areaShape << std::endl;
			}
			else
			{
				std::cerr << "input correct length of triangle." << std::endl;
			}
		} while (a + b <= c || a + c <= b || b + c <= a);
	}
	break;

	case 2: //Circle
	{
		double  radius;
		std::cin >> radius;
		areaShape = PI * radius*radius;
		std::cout << "Circle Area: " << areaShape;
	}
	break;

	case 3: //Rectangle
	{
		double  width, height;
		std::cin >> width >> height;
		areaShape = width * height;
		std::cout << "Rectangle Area: " << areaShape;
	}
	break;

	case 4: //Square
	{
		double  lenEdge;
		std::cin >> lenEdge;
		areaShape = lenEdge * lenEdge;
		std::cout << "Square Area" << areaShape;
	}
	break;

	default://Others
	{
		std::cout << "Input valid shape type(1~4)." << std::endl;
	}
	break;
	}

	return 0;
}