#include <iostream>
#include "Line.h"
/*
Severity	Code	Description	Project	File	Line	Suppression State
Error	C2248	'Point::x': cannot access private member declared in class 'Point'	Line	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter5\line\line.cpp	5
Error	C2248	'Point::y': cannot access private member declared in class 'Point'	Line	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter5\line\line.cpp	6
Severity	Code	Description	Project	File	Line	Suppression State
Error (active)	E1086	the object has type qualifiers that are not compatible with the member function "Line::length"	Line	D:\01.Education\00.Teaching\OOPCPP\CPPCode\VS2017_sln\Chapter5\Line\main.cpp	10
Error	C2662	'float Line::length(void)': cannot convert 'this' pointer from 'const Line' to 'Line &'	Line	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter5\line\main.cpp	10
*/
int main() {
		const Line		l1(Point(1, 1), Point(3, 5));
		std::cout << l1.length() << std::endl;
		return 0;
}