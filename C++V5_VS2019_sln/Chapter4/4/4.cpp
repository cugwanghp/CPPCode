// 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct clock {
		int	hour;
		int	min;
		int	sec;

		void set()		//hour 形参，值传递，地址传递
		{
				std::cin >> hour >> min >> sec;
		}

		void print()		//clock 代表 hour,min,sec
		{
				std::cout << hour << ":" << min << ":" << sec << std::endl;
		}
};

// 
class Point {
		// 默认构造函数
		Point() {}
		Point(const Point&) {}
		Point operator=(const Point&) { return *this; }
};

int main() {
		clock		clk;		//clock结构体，包括：hour,min,sec 封装

		clk.set();	//set(clk)
		clk.print();		//print(clk) this pointer

		return 0;
}

/*
struct clock {
		int	hour;
		int	min;
		int sec;

void print(int formatType=0) {
		float		result;
		switch (formatType)
		{
		case 1:
				result = hour + min / 60. + sec / 3600.;
				std::cout << result;
				break;
		case 2:
				result = min + sec / 60.0;
				std::cout << hour << ":" << result;
				break;
		default:
				std::cout << hour << ":" << min << ":" << sec;
				break;
		}
}
};

void print(clock clk, int formatType = 0) {
		float		hour, min;
		switch (formatType)
		{
		case 1:
				hour = clk.hour + clk.min / 60. + clk.sec / 3600.;
				std::cout << hour;
				break;
		case 2:
				min = clk.min + clk.sec / 60.0;
				std::cout << clk.hour << ":" << min;
				break;
		default:
				std::cout << clk.hour << ":" << clk.min << ":" << clk.sec;
				break;
		}
}

// 输入hour，min,sec ，输出::
int main()
{
		clock		clk;		//代表hour, min,sec
		clock		c2;	//
		clock		c3;

		std::cin >> clk.hour >> clk.min >> clk.sec;
		//hour:min:sec, 10:20:00, 10.33333h, 10:20.00 
		print(clk);
		std::cout << std::endl;
		print(clk, 1);
		std::cout << std::endl;
		print(clk, 2);
		std::cout << std::endl;

		clk.print(0);		//
		c2.print(0);		//
		std::cout << std::endl;
		clk.print(1);
		std::cout << std::endl;
		clk.print(2);
		std::cout << std::endl;

		return 0;
}
*/
