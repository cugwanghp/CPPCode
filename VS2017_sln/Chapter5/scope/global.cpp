#include <iostream>

//namespace Foo		// Foo is defined in the global scope
//{
		// Variables declared outside of a function are global variables
		int g_x{}; // global variable g_x
//}

void doSomething()
{
		// global variables can be seen and used everywhere in the file
		g_x = 3;
		std::cout << g_x << '\n';
}

int main()
{
		doSomething();
		std::cout << g_x << '\n';

		// global variables can be seen and used everywhere in the file
		g_x = 5;
		std::cout << g_x << '\n';

		return 0;
}
// g_x goes out of scope here


/*
// Non-constant global variables
int g_x;                 // defines non-initialized global variable (zero initialized by default)
int g_x {};              // defines explicitly value-initialized global variable
int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global const

// Constexpr global variables
constexpr int g_y;       // error: constexpr variables must be initialized
constexpr int g_y { 3 }; // defines initialized global constexpr
*/

/*
#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
		inline constexpr double pi { 3.14159 }; // note: now inline constexpr
		inline constexpr double avogadro { 6.0221413e23 };
		inline constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
		// ... other related constants
}
#endif
*/