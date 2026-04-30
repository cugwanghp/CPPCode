#pragma once
class Point
{
public:
		Point(int i=0, int j=0) { x = i; y = j; }
		int getX() const { return x; }
		int getY() const { return y; }
private:
		friend class Line;	//Line --> Point private/protected
		int	x, y;
};
