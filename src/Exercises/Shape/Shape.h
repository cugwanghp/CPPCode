#pragma once

class Shape
{
public:
    Shape() = default;
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Triangle : public Shape
{
public:
    Triangle(double a, double b, double c);
    ~Triangle() = default;
    double area() const override;
private:
    double  m_edgesLen[3];
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h);
    ~Rectangle() = default;
    double area() const override;
private:
    double  m_width;
    double  m_height;
};

class Circle : public Shape
{
public:
    Circle(double radius);
    ~Circle() = default;
    double area() const override;
private:
    double  m_radius;
};