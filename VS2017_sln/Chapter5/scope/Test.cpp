#include "Test.h"

constexpr int g_x{ 2 }; // this internal g_x is only accessible within test.cpp

// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
static int add(int x, int y)
{
		return x + y;
}