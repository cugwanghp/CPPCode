//3_2.cpp
#include <iostream>
using namespace std;

#include "mymath.h"

int add(int a, int b);

int main() {
    int value = 0;

		// 函数的调用
		std::cout << add(2, 4) << std::endl;

    cout << "Enter an 8 bit binary number: ";
    for (int i = 7; i >= 0; i--) {
        char ch;
        cin >> ch;
        if (ch == '1')
            value += static_cast<int>(power(2, i));
    }
    cout << "Decimal value is " << value << endl;
    return 0;
}

// 函数的定义
int add(int a, int b) //函数的声明
{
		return a + b;
}