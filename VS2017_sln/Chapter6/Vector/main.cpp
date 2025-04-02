// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
		Vector	vec{ 1,2,3,4,5,6,7 };

		vec.pop_back();
		vec.push_back(10);
		vec.push_back(12);
		
		for (int i = 0; i < vec.size(); ++i)
				std::cout << vec[i] << "\t";
		std::cout << std::endl;		
		
		return 0;
}
