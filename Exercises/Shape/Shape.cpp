#include "Shape.h"
#include <cmath>

Triangle::Triangle(double a, double b, double c)
{
    m_edgesLen[0] = a;
    m_edgesLen[1] = b;
    m_edgesLen[2] = c;
}

double Triangle::area() const
{
    if (m_edgesLen[0]+m_edgesLen[1]>m_edgesLen[2] &&
        m_edgesLen[1]+m_edgesLen[2]>m_edgesLen[0] &&
        m_edgesLen[0]+m_edgesLen[2]>m_edgesLen[1])
    {
        double  d = (m_edgesLen[0]+m_edgesLen[1]+m_edgesLen[2]) / 2.;

        return sqrt(d*(d-m_edgesLen[0])*(d-m_edgesLen[1])*(d-m_edgesLen[2]));
    }

    return 0.0f;
}

Rectangle::Rectangle(double w, double h) : m_width(w), m_height(h)
{
}

double Rectangle::area() const
{
    return m_width*m_height;
}

Circle::Circle(double radius) : m_radius(radius)
{
}

double Circle::area() const
{
    return 3.1415926*m_radius*m_radius;
}