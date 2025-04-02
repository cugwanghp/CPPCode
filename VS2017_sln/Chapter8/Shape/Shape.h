#pragma once
class Shape
{
public:
		Shape() = default;
		virtual ~Shape() {};

		virtual double area() const = 0;// { return 0.0; }
};

class Ellipse : public Shape
{
public:
		Ellipse(double a=0.0, double b=0.0) : Shape(), m_a(a), m_b(b) {}
		~Ellipse() = default;
		double area() const override { return 3.1415926*m_a*m_b; }
protected:
		double	m_a;
		double	m_b;
};

class Circle : public Ellipse
{
public:
		Circle(double radius = 0.0) : Ellipse(radius, radius) {}
		~Circle() = default;
};

class Rectangle : public Shape
{
public:
		Rectangle(double width = 0.0, double height = 0.0) : 
				Shape(), m_width(width), m_height(height) {}
		~Rectangle() = default;
		double area() const {return m_width*m_height; }

protected:
		double	m_width;
		double	m_height;
};

class Square : public Rectangle
{
public:
		Square(double len) : Rectangle(len, len) {}
		~Square() = default;		
};
