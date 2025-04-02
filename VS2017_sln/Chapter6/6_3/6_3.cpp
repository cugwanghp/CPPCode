//6-3.cpp
#include "Point.h"
#include "Line.h"
#include <iostream>
using namespace std;

int main() {
		Point		pt(1,2);		//调用Point(int, int)
		Point		pt2 = Point(1, 2);
		Point		pt3{1,2 };
		Point		pt4 = Point{ 1,2 };
		Point		pt5{ Point(1,2) };
		Point		pt6 = { Point(1,2) };
		Point		pt7[2] = { Point(1,2), Point(3,4) };
    cout << "Entering main..." << endl;
		Point a[2];	// 2个Point的数组
		for (int i = 0; i < 2; i++) {
				a[i].move(i + 10, i + 20);
				//Debug,Release 不需要
#if _DEBUG
				std::cout << a[i].getX() << "," << a[i].getY() << std::endl;
#endif
		}
    cout << "Exiting main..." << endl;
		
		Line		line;		//line()
		std::cout << line.distance() << std::endl;
		return 0;
}
