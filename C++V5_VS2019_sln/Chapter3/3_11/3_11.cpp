//3_11.cpp
#include <iostream>
#include <cmath>

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 5, y = 10;
    std::cout << "x = " << x << "    y = " << y << std::endl;
    swap(x, y);	//x,y Êµ²Î
    std::cout << "x = " << x << "    y = " << y << std::endl;
    return 0;
}
