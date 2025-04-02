#include "Foo.h"
#include <iostream>

int main()
{
	Foo*	pf = new Foo;
	delete pf;

	cout << "-------------------\n";

	pf = new Foo[3];
	delete[] pf;
	cout << "-------------------\n";

	pf = ::new Foo;
	::delete pf;

	return 0;
}