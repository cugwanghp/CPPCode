/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 18:18:38
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 19:34:44
 */
#include <iostream>
#include "String.h"

int main()
{
    const String hello("Hello");
    const String world("World");
    
    String s = hello + String(" ");
    s += world;
    std::cout << s << "\n";
}
