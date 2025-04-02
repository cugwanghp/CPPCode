#include "pool.h"
rectangle::rectangle(float width, float height) : m_width(width), m_height(height)
{
}

float rectangle::area() const
{
	return m_width * m_height;
}

float rectangle::circumference() const
{
	return 2 * (m_width + m_height);
}

circle::circle(float radius) : m_radius(radius)
{
}

float circle::area() const
{
	return PI * m_radius*m_radius;
}

float circle::circumference() const
{
	return 2 * PI*m_radius;
}

pool::pool(float width, float height, float rimwidth) :
	m_width(width), m_height(height), m_rimWidth(rimwidth)
{
}

float pool::area() const
{
	rectangle   innerRect(m_width, m_height);
	rectangle   outerRect(m_width + m_rimWidth, m_height);
	circle      innerCircle(m_width);
	circle      outerCircle(m_width + m_rimWidth);

	return outerCircle.area() + outerRect.area() - innerCircle.area() - innerRect.area();
}

float pool::circumference() const
{
	rectangle   outerRect(m_width + m_rimWidth, m_height);
	circle      outerCircle(m_width + m_rimWidth);
	return outerCircle.circumference() + outerRect.circumference() - 2 * (m_width + m_rimWidth);
}