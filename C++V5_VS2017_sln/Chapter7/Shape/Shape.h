#pragma once
class Shape
{
public:
		Shape() = default;
		~Shape() = default;

		virtual double area() { return 0.0; }
};

