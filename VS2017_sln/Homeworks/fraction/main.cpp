/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2023-03-21 08:53:03
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2023-03-21 09:20:29
 */
#include <iostream>
#include <utility>
#include "fraction.h"
using namespace std;
int main()
{
    fraction f1{8, 12}; // calls Fraction() default constructor
	fraction f2(0.6);
	cout << f1 << endl;
	cout << f2 << endl;
	cout << double(f1) << endl;

	fraction f3 = f1 + f2;
	fraction&& rrf = std::move(f1 + f2);
	cout << f3 << endl;
	cout << rrf << endl;
	return 0;

	cout << f1 + f2 << endl;
	cout << f1 - f2 << endl;
	cout << f1 * f2 << endl;
	cout << f1 / f2 << endl;


	//<<(cout, endl);	//cout<<endl;
    return 0;
}

