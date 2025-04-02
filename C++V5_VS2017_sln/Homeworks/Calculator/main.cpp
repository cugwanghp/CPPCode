#include <iostream>
#include <string>
#include "calculator.h"
using namespace std;

int main()
{
	calculator  calc;

	string      strExpr;
	getline(cin, strExpr);	// 输入表达式

	cout << calc.run(strExpr) << endl;

	return 0;
}