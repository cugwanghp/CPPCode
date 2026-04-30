#pragma once
class Shape{
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual ~Shape() = default;
};

enum class ShapeType {
    TRIANGLE,
    RECTANGLE,
    CIRCLE
};