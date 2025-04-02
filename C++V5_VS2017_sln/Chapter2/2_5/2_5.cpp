//2_5.cpp
#include<iostream>
using namespace std;

int main() {
	int i = 1, sum = 0;
/*	while (i<=10) {
		sum += i;
		i++;
	}

	do {
		sum += i;
		i++;
	} while (i <= 10);
*/
	i = 1;
	for (;;)
	{
		sum += i;
		i++;
		if (i > 10) continue;
		if (i > 100) break;
	}
	cout << "sum = " << sum << endl;
	return 0;
}
