#include <iostream>
using namespace std;

void printSpace(int);
void printStars(int);

int main()
{
	int		n = 10;
	for (int i = 0; i < n; ++i)
	{
		printSpace(i);
		printStars(i);
	}

	for (int i = n; i > 0; --i)
	{
		printSpace(i);
		printStars(i);
	}
}

void printSpace(int n)
{
	return;
}

void printStars(int n)
{
	for (int i = 0; i < n; ++i)
		cout << "*";
	cout << endl;
	return;
}