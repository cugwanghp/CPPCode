#include "Clock.h"
#include <iostream>

Clock::Clock() : Clock(0,0,0){
}

//构造函数，初始化成员变量
Clock::Clock(int h, int m, int s) : hour(h), minute(m), second(s)
{
}

void Clock::showTime() {
		std::cout << hour << minute << second << std::endl;
}