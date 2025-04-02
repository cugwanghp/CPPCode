int g_x{ 2 }; // non-constant globals are external by default

extern const int g_y{ 3 }; // const globals can be defined as extern, making them external
extern constexpr int g_z{ 3 }; // constexpr globals can be defined as extern, making them external (but this is pretty useless, see the warning in the next section)

int main()
{
		return 0;
}

// a.cpp
// global variable definitions
int g_x{ 2 }; // non-constant globals have external linkage by default
extern const int g_y{ 3 }; // this extern gives g_y external linkage

// main.cpp
#include <iostream>

extern int g_x; // this extern is a forward declaration of a variable named g_x that is defined somewhere else
extern const int g_y; // this extern is a forward declaration of a const variable named g_y that is defined somewhere else

int main()
{
		std::cout << g_x << ' ' << g_y << '\n'; // prints 2 3

		return 0;
}

// Why(non - const) global variables are evil?
#include <iostream>

int g_mode; // declare global variable (will be zero-initialized by default)

void doSomething()
{
		g_mode = 2; // set the global g_mode variable to 2
}

int main()
{
		g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

		doSomething();

		// Programmer still expects g_mode to be 1
		// But doSomething changed it to 2!

		if (g_mode == 1)
		{
				std::cout << "No threat detected.\n";
		}
		else
		{
				std::cout << "Launching nuclear missiles...\n";
		}

		return 0;
}