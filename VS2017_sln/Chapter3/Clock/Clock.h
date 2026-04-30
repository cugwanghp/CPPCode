#pragma once
class Clock
{
public:
		void showTime();
		Clock();
		Clock(int h, int m=0, int s=0);//构造函数，初始化成员变量
private:
		int	hour;		//
		int	minute;
		int second;
};

