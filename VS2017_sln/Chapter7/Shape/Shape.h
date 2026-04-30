#pragma once
class Shape
{
public:
		Shape() = default;
		virtual ~Shape() = default;

		virtual double area() const = 0;
};

class Triangle : public Shape {
public:
		Triangle(double a, double b, double c);
		~Triangle() = default;

		double area() const override;
protected:
		double	m_TriLen[3];
};

class Rectangle : public Shape
{
public:
		Rectangle(double height, double width);
		~Rectangle() = default;
		double area() const;
protected:
		double	m_height, m_width;
};

class Circle : public Shape
{
public:
		Circle(double radius) : m_radius(radius) {}
		~Circle() = default;
		double area() const { return 3.14159*m_radius*m_radius; }
protected:
		double	m_radius;
};