#include "Shape.h"
#include <cmath>

Triangle::Triangle(double a, double b, double c) :
		Shape(), m_TriLen{a,b,c}
{
}

double Triangle::area() const
{
		double	halfLens = (m_TriLen[0] + m_TriLen[1] + m_TriLen[2]) / 2.;
		return sqrt(halfLens*(halfLens - m_TriLen[0])*(halfLens - m_TriLen[0])*(halfLens - m_TriLen[0]));
}

Rectangle::Rectangle(double height, double width) :
		m_height(height), m_width(width) {
}

double Rectangle::area() const {
		return m_height * m_width;
}