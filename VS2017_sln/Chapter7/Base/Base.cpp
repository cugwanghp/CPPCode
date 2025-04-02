#include "Base.h"

#include <iostream>

int main()
{
	Base	b;
	Dervied	d;

	std::cout << sizeof(b) << "\t" << sizeof(d) << std::endl;
	std::cout << sizeof(Base2) << "\t";
	std::cout << sizeof(Derived2) << std::endl;

	std::cout << b.getid() << std::endl;
	std::cout << b.Base::getid() << "\t"
		<< d.getid() << "\t"
		<< d.getvalue() << std::endl;
	
	std::cout << (static_cast<Base>(d)).getid() << std::endl;

	Base&	rb = d;
	Base*	pb = &d;

	b.print(std::cout);
	std::cout << std::endl;

	rb.print(std::cout);	//d.print
	std::cout << std::endl;

	pb->print(std::cout);	//d.print
	std::cout << std::endl;
	
	return 0;
}
