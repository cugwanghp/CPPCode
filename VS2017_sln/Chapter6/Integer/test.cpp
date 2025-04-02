#include<iostream>
#include"integer.h"

int main()
{
	const Integer x = 1;
	const Integer y = 2;
	const Integer z = 3;
	 
	//3
	std::cout << (x - y) / (x - y) * z << std::endl; 
	//3
	std::cout << (x + y) * (x + y) / z << std::endl;
}