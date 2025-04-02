#pragma once

#include <iostream>
using namespace std;

class rectangle
{
public:
	rectangle(float width = 0., float height = 0.);

	float area() const;
	float circumference() const;
private:
	float   m_width, m_height;
};

class circle
{
public:
	circle(float radius = 0.);

	float area() const;
	float circumference() const;
private:
	float m_radius;
	constexpr static float PI = 3.1415926;
};

class pool
{
public:
	pool(float width, float height, float rimwidth = 3.);
	float area() const;
	float circumference() const;
private:
	float m_width;
	float m_height;
	float m_rimWidth = 3.;
};