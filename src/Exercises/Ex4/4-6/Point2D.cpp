#include "Point2D.h"

// Create a new point with coordinates (0, 0).
Point2D::Point2D() : m_x(0.0), m_y(0.0)
{
}

// Create a new point with coordinates (x, y).
Point2D::Point2D(const Point2D::Real& x, const Point2D::Real& y) : m_x(x), m_y(y)
{
}

// Obtain a reference to the x-coordinate of the point.
Point2D::Real& Point2D::x()
{
    return m_x;
}

const Point2D::Real& Point2D::x() const
{
    return m_x;
}

// Obtain a reference to the y-coordinate of the point.
Point2D::Real& Point2D::y()
{
    return m_y;
}

const Point2D::Real& Point2D::y() const
{
    return m_y;
}

// Add/subtract displacement to/from point (i.e., translate point).
Point2D& Point2D::operator+=(const Point2D& p)
{
    m_x += p.m_x;
    m_y += p.m_y;

    return *this;
}

Point2D& Point2D::operator-=(const Point2D& p)
{
    m_x -= p.m_x;
    m_y -= p.m_y;

    return *this;
}

// Write a point to an output stream.
std::ostream& operator<<(std::ostream& out, const Point2D& p)
{
    out << "(" << p.x() << "," << p.y() << ")";
    return out;
}

// Read a point from an input stream.
std::istream& operator>>(std::istream& in, Point2D& p)
{
    in >> p.x() >> p.y();
    return in;
}
