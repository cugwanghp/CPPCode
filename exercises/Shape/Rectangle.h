#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double w, double h);
    double getArea() const override;
    double getPerimeter() const override;

private:
    double width, height;
};