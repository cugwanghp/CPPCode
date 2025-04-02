#include <iostream>
#include "Shape.h"
#include <vector>

/*
文件存了若干个 几何形状坐标（）
统计形状的面积的总和
*/

int main()
{
		double	areaTotal = 0.0;
		int			shapeType;
		std::vector<Shape*>	vecShapePtrs;		//shape* 数组 ok
		double	a, b;

		do
		{
				std::cout << "1-Ellipse, 2-Circle, 3-Rectangle, 4-Square, 0-Exit\n";
				std::cin >> shapeType;
				switch (shapeType)
				{
				case 1:	//1-Ellipse
						std::cin >> a >> b;
						vecShapePtrs.push_back(new Ellipse(a, b));
						break;
				case 2:	//2-Circle
						std::cin >> a;
						vecShapePtrs.push_back(new Circle(a));
						break;
				case 3:	//3-Rectangle
						std::cin >> a >> b;
						vecShapePtrs.push_back(new Rectangle(a, b));
						break;
				case 4:	//4-Square
						std::cin >> a;
						vecShapePtrs.push_back(new Square(a));
						break;
				default:
						break;
				}
		} while(shapeType != 0);

		// 统计总面积
		for (const auto& shape : vecShapePtrs)
		{
				areaTotal += shape->area();
		}
		std::cout << "toatal area : " << areaTotal << std::endl;

		// 释放空间
		for (auto& elem : vecShapePtrs)
				delete elem;
		vecShapePtrs.clear();

		return 0;
}