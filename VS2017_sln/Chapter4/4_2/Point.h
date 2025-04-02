#pragma once

class Point {	//Point 类的定义
public:		//外部接口
	Point(int xx = 0, int yy = 0);	//构造函数
	Point(const Point &p);			//复制构造函数
	Point(Point&& p);			//移动构造函数

	int getX() const { return x; }
	int getY() const { return y; }
private:	//私有数据
	int x, y;
};

double distance(const Point& p1, const Point& p2);	// p1-p2 distance
Point move(const Point& p1, const Point& p2);//返回值为Point类对象的函数
