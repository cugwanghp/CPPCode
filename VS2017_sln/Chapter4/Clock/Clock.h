#pragma once
class Clock
{
public:
		Clock();
		Clock(int h, int m=0, int s=0);		//12:00:00
		Clock(const Clock& c);	//copy constructor
public:
		int	hour, minute, second;
};

