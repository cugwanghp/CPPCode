//5_6.cpp
#include <iostream>
#include <cmath>
#include <fstream>	//file stream
using namespace std;

#include "Point.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {	//主函数
		ofstream		ofs("D:\\test.dat");
		for (int j = 0; j < 10; j++) {
				for (int i = 0; i < 1000; i++) {
						ofs << "name_" << i << " " << sqrt(i+j) << std::endl;
				}
		}
		ofs.close();
		return 0;

    Point myp1(1, 1), myp2(4, 5);	//定义Point类的对象
		const Point	p3(2, 3);		//p3.x, p3.y 不能被改变
		//p3.move(1, 1);	//move 间接地改变了x,y的值， p3 - const
		cout << p3.getX() << "\t" << p3.getY() << endl;	//p3.x,p3.y
		cout << myp1.getX();

    cout << "The distance is: ";
    cout << dist(myp1, myp2) << endl;	//计算两点间的距离
    return 0;
}
