#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double radius);
    double getArea() const override;
    double getPerimeter() const override;

private:
    double radius;
};