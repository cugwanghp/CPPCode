//2_2.cpp
#include <iostream>
using namespace std;

int main() {
	int year;
	bool isLeapYear;
	
	do{
		cout << "Enter the year(>0): ";
		cin >> year;
	} while (year <= 0);

	isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	
	if (isLeapYear)
		cout << year << " is a leap year" << endl;
	else
		cout << year << " is not a leap year" << endl;

	return 0;
}
