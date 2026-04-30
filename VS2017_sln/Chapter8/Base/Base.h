#pragma once

// Shape --> Triangle, Rectangle, Circle, Ellipse, 求面积
//1. 继承关系， base: Shape, Derived: Triangle, Rectangl, Ellipse...
class Shape {
public:
		virtual float area() const { return 0.0; }	//形状的面积
		virtual ~Shape() {}
};

class Circle : public Shape{
public:
		Circle(float r = 0.0) : Shape(), radius(r) {}
		virtual float area() const override;
private:
		float radius;
};

class Rectangle : public Shape {
public:
		Rectangle(float w, float h) : Shape(), width(w), height(h){}
		float area() const;
private:
		float width, height;
};