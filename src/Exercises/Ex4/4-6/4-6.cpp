#include <iostream>
#include "Point2D.h"

int main()
{
    while(!std::cin.eof())
    {
        Point2D pt1;
        std::cin >> pt1;

        pt1 += Point2D(1.0, 1.0);
        std::cout << pt1;

        pt1 -= Point2D(2.0, 2.0);
        std::cout << pt1;
    }

    return 0;
}