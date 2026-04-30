#pragma once
#include "Shape.h"

class Triangle : public Shape{
public:
    Triangle(double aa, double bb, double cc);
    double getArea() const override;
    double getPerimeter() const override;
private:
    double a, b, c;
};