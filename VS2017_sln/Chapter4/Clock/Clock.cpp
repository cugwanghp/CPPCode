#include "Clock.h"

Clock::Clock() : Clock(0){
}

Clock::Clock(int h, int m, int s) : hour(h), minute(m), second(s) {
}

Clock::Clock(const Clock& c) : hour(c.hour), minute(c.minute), second(c.second){
}
/*
Severity	Code	Description	Project	File	Line	Suppression State
Error (active)	E0408	copy constructor for class "Clock" may not have a parameter of type "Clock"	Clock	D:\01.Education\00.Teaching\OOPCPP\CPPCode\VS2017_sln\Chapter4\Clock\Clock.cpp	9
Error (active)	E0408	copy constructor for class "Clock" may not have a parameter of type "Clock"	Clock	D:\01.Education\00.Teaching\OOPCPP\CPPCode\VS2017_sln\Chapter4\Clock\Clock.h	7
Error	C2652	'Clock': illegal copy constructor: first parameter must not be a 'Clock'	Clock	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter4\clock\clock.h	7
Error	C2652	'Clock': illegal copy constructor: first parameter must not be a 'Clock'	Clock	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter4\clock\clock.h	7
Error	C2440	'initializing': cannot convert from 'Clock' to 'Clock'	Clock	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter4\clock\maincpp.cpp	9
Error	C2064	term does not evaluate to a function taking 1 arguments	Clock	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter4\clock\maincpp.cpp	10
Error	C2146	syntax error: missing ';' before identifier 'c5'	Clock	d:\01.education\00.teaching\oopcpp\cppcode\vs2017_sln\chapter4\clock\maincpp.cpp	13

*/