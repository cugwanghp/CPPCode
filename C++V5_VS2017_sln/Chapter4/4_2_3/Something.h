#pragma once

class Something
{
public:
	// Default constructor
	Something(int n = 0, double d = 1.2) // allows us to construct a Something(int, double), Something(int), or Something()
	{
	}

	Something(double d) : Something(0, d)
	{
	}
};
