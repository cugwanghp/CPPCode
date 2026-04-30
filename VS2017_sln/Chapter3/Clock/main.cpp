#include "Clock.h"
#include <iostream>
//Severity	Code	Description	Project	File	Line	Suppression State
//Error	C2512	'Clock': no appropriate default constructor available	Clock	d : \01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter3\clock\main.cpp	6

int main()
{
		Clock		c2;	//ok?
		Clock		c1(0,0,0);	//实例化Clock对象，一定会调用构造函数
		c1.showTime();
		return 0;
}