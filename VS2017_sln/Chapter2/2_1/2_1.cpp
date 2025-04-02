//2_1.cpp
#include <iostream>
using namespace std;

int main() {
	int		n;
	do
	{
		cin >> n;
		switch (n)
		{
		case 1:
			Ex1();
			break;
		case 2:
			Ex2();
			break;
		case 3:
			Ex3();
			break;
		default:
			break;
		}

	} while (n != 0);
	return 0;
}

void Ex1()
{
	cout << "Hello! " << endl;
	cout << "Welcome to C++! " << endl;
}

void Ex2()
{

}

void Ex3()
{

}