//2_4.cpp
#include <iostream>
using namespace std;

int main() {
	int day;
	
	cin >> day;
	//1. day ÕûÊı/char/int/short/long/long long
	switch (day)
	{
	case 0:	cout << "Sunday" << endl;	break;
	default: cout << "Invalidate day." << endl; break;
	}


	switch (day) {	
	case 0:
		cout << "Sunday" << endl;
		break;
	case 1:
		cout << "Monday" << endl;
		break;
	case 2:
		cout << "Tuesday" << endl;
		break;
	case 3:
		cout << "Wednesday" << endl;
		break;
	case 4:
		cout << "Thursday" << endl;
		break;
	case 5:
		cout << "Friday" << endl;
		break;
	case 6:
		cout << "Saturday" << endl;
		break;
	default:
		cout << "Day out of range Sunday .. Saturday" << endl;
		break;
	}

	return 0;
}
