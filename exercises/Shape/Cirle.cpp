#include "Circle.h"
#include <cmath>

const double PI = acos(-1.0);   //arcos

Circle::Circle(double r) : radius(r) {}

double Circle::getArea() const {
    return PI * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * PI * radius;
}