#pragma once

class Point {	//Point类定义
public:	//外部接口
		Point(int x = 0, int y = 0) : x(x), y(y) { }
		inline int getX() const { return x; }		//inline
		inline int getY() const { return y; }
		void move(int dx, int dy);	//
		friend float dist(Point& p1, Point& p2);//函数友元声明
private:	//私有数据成员
		int x, y;
};

