//9_9.cpp
#include "Calculator.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	Calculator c;
//	c.run();

	Calculator2	c2;
	string	strexp;
	double	value;
	getline(cin, strexp);
	c2.run(strexp.c_str(), value);
	cout << value << endl;

	return 0;
}
