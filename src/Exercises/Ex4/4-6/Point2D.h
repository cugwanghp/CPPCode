#pragma once

/*
 * @Description:
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 17:08:18
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 17:33:03
 */
#include <iostream>

class Point2D
{
public:
    // The coordinate type, in case we want to change it later.
    typedef double Real;
    
    // Create a new point with coordinates (0, 0).
    Point2D();
    // Create a new point with coordinates (x, y).
    Point2D(const Real & x, const Real & y);
    // Obtain a reference to the x-coordinate of the point.
    Real& x();
    const Real& x() const;
    // Obtain a reference to the y-coordinate of the point.
    Real& y();
    const Real& y() const;
    // Add/subtract displacement to/from point (i.e., translate point).
    Point2D& operator+=(const Point2D& p);
    Point2D& operator-=(const Point2D& p);

private:
    Real    m_x, m_y;
};

// Write a point to an output stream.
std::ostream& operator<<(std::ostream& out, const Point2D& p);
// Read a point from an input stream.
std::istream& operator>>(std::istream& in, Point2D& p);