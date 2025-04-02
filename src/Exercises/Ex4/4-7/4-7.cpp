/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 17:06:17
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 17:54:10
 */
// IntArray2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IntArray2.h"

int main()
{
    int     m, n;
    std::cin >> m >> n;

    IntArray2   arr(m, n);

    std::cin >> arr;

    std::cout << arr << std::endl;

    return 0;
}
