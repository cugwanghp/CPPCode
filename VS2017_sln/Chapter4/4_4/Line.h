#pragma once
#include "Point.h"

//类的组合
class Line {	//Line类的定义
public:	//外部接口
    Line(const Point& xp1, const Point& xp2);
    Line(const Line &l);
		Line(Line&& l);
    inline double getLen() const { return len; }
private:	//私有数据成员
    Point p1, p2;	//Point类的对象p1,p2
    double len;
};

Line getLine();