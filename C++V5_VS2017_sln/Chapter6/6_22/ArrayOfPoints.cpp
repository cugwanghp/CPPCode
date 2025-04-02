#include "ArrayOfPoints.h"
#include "Point.h"
#include <cassert>

ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints& v) {
	size = v.size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
		points[i] = v.points[i];
}

ArrayOfPoints::ArrayOfPoints(int size) : size(size) {
	points = new Point[size];
}

ArrayOfPoints::ArrayOfPoints(ArrayOfPoints &aop)
{
	size = aop.size;
	points = new Point[size];
	for (int i = 0; i < size; ++i)
		points[i] = aop.element(i);
}


ArrayOfPoints::~ArrayOfPoints() {
	cout << "Deleting..." << endl;
	delete[] points;
}

//获得下标为index的数组元素
ArrayOfPoints::Point &element(int index) {
	assert(index >= 0 && index < size);	//如果数组下标越界，程序中止
	return points[index];
}