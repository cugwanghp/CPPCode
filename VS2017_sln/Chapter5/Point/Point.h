//#pragma once
#ifndef _POINT_
#define _POINT_

class Point
{
public:
		Point(int x=0, int y = 0);
		Point(const Point&) = default;
		~Point() = default;

		inline int getX() const { return _x; }		// inline
		inline int getY() const { return _y; }
private:
		int	_x, _y;
		//friend double dist(const Point& a, const Point& b);
		//friend class Line;	//
};

//double dist(const Point& a, const Point& b);

class Line
{
public:
		Line(int x1=0, int y1=0, int x2=0, int y2=0);
		Line(const Line&) = default;
		~Line() = default;

		double dist();
private:
		Point			_pt1, _pt2;
};

#endif