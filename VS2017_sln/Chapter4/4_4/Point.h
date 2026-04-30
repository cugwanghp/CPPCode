#pragma once

class Point {	//Point类定义
public:
    Point(int xx = 0, int yy = 0);  //构造函数的声明
    Point(const Point &p);          //复制构造函数的声明
    int getX() { return x; }        //成员函数的声明
    int getY() { return y; }        //成员函数的声明
private:
    int x, y;                       //数据成员的声明
};