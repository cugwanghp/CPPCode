#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double aa, double bb, double cc) 
    :a(aa), b(bb), c(cc) {}

double Triangle::getArea() const {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::getPerimeter() const {
    return a + b + c;
}