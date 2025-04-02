// scope.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

int main()
{
	int		i{ 5 };	// i enters scope here
	double	d{ 4.0 };	// d enters scope here

	return 0;
}// d and i go out of scope here

int max(int x, int y)
{
		int max{ (x > y) ? x : y };
		
		return max;
}

/*
#include <iostream>

int main()
{
		// do not define y here

		{
				// y is only used inside this block, so define it here
				int y { 5 };
				std::cout << y << '\n';
		}

		// otherwise y could still be used here, where it's not needed

		return 0;
}
*/