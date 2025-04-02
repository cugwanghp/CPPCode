#pragma once
#include <iostream>

class Point {	//Point类定义
public:	//外部接口
	Point(int x = 0, int y = 0); //构造函数
	Point(Point &p);	//复制构造函数
	~Point();
	inline int getX() const { return x; }
	inline int getY() const { return y; }
	void showCount();		//输出静态数据成员
private:	//私有数据成员
	int x, y;
	static int count{ 0 };	//静态数据成员声明，用于记录点的个数
	constexpr static int origin = 0; //常量静态成员类内初始化
};
