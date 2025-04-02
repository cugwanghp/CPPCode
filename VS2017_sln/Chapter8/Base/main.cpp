#include <iostream>
#include "Base.h"
using namespace std;

int main()
{
	Base	b, b1;
	Derived d;
	Base&	rb = d;
	Base*	pb = &d;
	Base&	rb2 = b;
	Base*	pb2 = &b;
	d.print();
	rb.print();
	int	choice;
	cin >> choice;	//1-Base, 2-Derived
	Base*	pb3 = nullptr;
	if (choice == 1)
	{
		pb3 = new Base;
	}
	else if (choice == 2)
	{
		pb3 = new Derived;
	}
	
	cout << *pb3;
	if (pb3) delete pb3;

//	b.print();
//	d.print();]]
	cout << b;	//operator<<(cout, b)
	cout << d;	//operator<<(cout, d), d is b, d-->b
	cout << rb;
	cout << rb2;
	/*
	Base	b1;

	std::cout << "Base size = " << sizeof(Base) << std::endl;
	std::cout << "Derived size = " << sizeof(Derived) << std::endl;
	std::cout << "rBase is a " << rBase.getName() << '\n';
	*/
	return 0;
}