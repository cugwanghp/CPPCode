//Point.h
#ifndef _POINT_H
#define _POINT_H
class Point {	//类的定义
public:	//外部接口
    Point() = default;
    Point(int x, int y);		//Point(int,int), Point(int), Point()
		Point(const Point& pt);
    ~Point();
    void move(int newX,int newY);
    int getX() const { return x; }
    int getY() const { return y; }
    static void showCount();	//静态函数成员
private:	//私有数据成员
    int x, y;
};

//double distanceOfPoints(const Point& pt1, const Point& pt2);

#endif	//_POINT_H
