#include <iostream>
#include "Shape.h"
#include <vector>		//动态数组，

int main()
{
		// 输入一个整数n，代表输入n个形状
		// 输入参数，创建形状对象
		// 统计所有形状的面积的方差
		// type: 0 exit, 1-triangle, 2-rectangle
		int			shape_count = 0;
		int			shape_type;
		int			a, b, c;		//边长
		double	maxArea = 0.0f;		//面积
		std::vector<Triangle>		vec_tr;	//三角形数组
		std::vector<Rectangle>	vec_rc;	//矩形数组
		std::vector<Circle>			vec_cr;	//圆形数组
		std::vector<Shape*>			vec_shp_ptr;		//Shape指针数组
		do {
				std::cout << "Input shape type(1-tri, 2-rect) : ";
				std::cin >> shape_type;
				switch (shape_type) {
				case 1:	//triangle
						std::cin >> a >> b >> c;
						vec_tr.push_back(Triangle(a, b, c));		//
						vec_shp_ptr.push_back(new Triangle(a, b, c));
						break;
				case 2:	//rectangle
						std::cin >> a >> b;
						vec_rc.push_back(Rectangle(a, b));
						vec_shp_ptr.push_back(new Rectangle(a, b));
						break;
				case 3:	//circle
						std::cin >> a;
						vec_cr.push_back(Circle(a));
						vec_shp_ptr.push_back(new Circle(a));
						break;
				default:		//
						std::cerr << "invalidate shape type." << std::endl;
						break;
				}
		} while (shape_type != 0);

		for (auto const& shp_ptr : vec_shp_ptr)
		{
				if (shp_ptr != nullptr)
				{
						if( maxArea < shp_ptr->area())
								maxArea = shp_ptr->area();
				}
		}

		for (auto const & shp : vec_tr) {
				if (maxArea < shp.area())
						maxArea = shp.area();
		}
		for (auto const & shp : vec_rc) {
				if (maxArea < shp.area())
						maxArea = shp.area();
		}
		for (auto& shp_ptr : vec_shp_ptr) {
				if (shp_ptr != nullptr)
						delete shp_ptr;
		}
		std::cout << "Max Area is " << maxArea << std::endl;;		
		return 0;
}