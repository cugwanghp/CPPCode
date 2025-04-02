//2_10.cpp
#include <iostream>
using namespace std;

int main() {
	int i = 0, j = 0, n;

	do {
		cout << "Enter some integers please (enter 0 to quit):" << endl;
		cin >> n;
		if (n > 0) i += 1;
		if (n < 0) j += 1;
	} while (n != 0);

	cout << "Count of positive integers: " << i << endl;
	cout << "Count of negative integers: " << j << endl;
	return 0;
}
