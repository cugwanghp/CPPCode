#include <iostream>
using namespace std;

int main()
{
	int		a;
	char	c;
	int*	pa = &a;
	char*	pc = &c;
	void*	pv = &a;

	cout << pa << "\t" << *pa << endl;
	cout << pc << "\t" << *pc << endl;
	cout << pv << *((char*)pv) << endl;
	return 0;
}