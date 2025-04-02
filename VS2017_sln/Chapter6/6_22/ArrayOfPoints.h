#pragma once
class Point;

class ArrayOfPoints {
public:
	ArrayOfPoints(const ArrayOfPoints& v);
	ArrayOfPoints(int size) : size(size);
	ArrayOfPoints(ArrayOfPoints &aop);
	~ArrayOfPoints();

	Point &element(int index);//获得下标为index的数组元素

private:
	Point *points;	//指向动态数组首地址
	int size;		//数组大小
};
