// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "Person.h"

int main()
{
		Student	s1;	//
		s1.name, s1.age, s1.stuId, s1.grade;
		int			n;
		std::cin >> n;
		Array		ary(n);	//int[n]
		Array		ary2 = ary;	//copy constructor
		Array		ary3 = Array(n);		//
		//ary2.pData = ary.pData;
		//ary2.len = ary.len;

		Vector	vec{ 1,2,3,4,5,6,7 };

		vec.pop_back();
		vec.push_back(10);
		vec.push_back(12);
		
		for (int i = 0; i < vec.size(); ++i)
				std::cout << vec[i] << "\t";
		std::cout << std::endl;		
		
		return 0;
}
