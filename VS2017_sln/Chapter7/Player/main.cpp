#include <iostream>
#include "Person.h"
#include "Player.h"

int main(int argc, char* argv[])
{
		Player	p1("Jordan", 34, 30.0);
		Person&	p{ p1 };

		p1.print();
		std::cout << std::endl;

		p.print();
		std::cout << std::endl;

		return 0;
}