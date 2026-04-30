#include <iostream>
#include "Person.h"
#include "Player.h"
#include "SportsStudent.h"

int main(int argc, char* argv[])
{
		Player	p1("Jordan", 34, SportsEvents::basketball, 60.0);
		Person&	p{ p1 };
		SportsStudent		s1("Gao Ning", 20, SportsEvents::badminton, 80.0, 100001, 2);

		p1.print();
		std::cout << std::endl;

		p.print();
		std::cout << std::endl;

		s1.print();
		std::cout << std::endl;

		return 0;
}