//Point.cpp
#include <iostream>
#include "Point.h"
#include <cmath>
using namespace std;
/*
Point::Point() {
    x = y = 0;
    cout << "Default Constructor called." << endl;
}
*/
Point::Point(int x, int y) : x(x), y(y) {
    cout << "Constructor called. " << endl;
}

Point::Point(const Point& pt) : x(pt.x), y(pt.y) {
		std::cout << "copy constructor called.\n";
}

Point::~Point() {
    cout << "Destructor called." << endl;
}

void Point::move(int newX,int newY) {
    cout << "Moving the point to (" << newX << ", " << newY << ")" << endl;
    x = newX;
    y = newY;
}

double distanceOfPoints(const Point& pt1, const Point& pt2) {
		double	dx = pt1.getX() - pt2.getX();
		double	dy = pt1.getY() - pt2.getY();
		return sqrt(dx*dx + dy * dy);
}
