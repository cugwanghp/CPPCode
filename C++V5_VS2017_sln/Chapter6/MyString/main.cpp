/*
【输入形式】输入字符串1回车，输入字符串2回车，输入运算符(<,>,==,<=,>=等）

【输出形式】输出计算结果字符串
【样例输入】

"I am a "

"CUGer"

"+"
【样例输出】"I am a CUGer"
【样例说明】main 函数
*/
#include <iostream>
#include "mystring.h"

int main()
{
    char    sBuffer[256];

    std::cin.getline(sBuffer, 256);
    MyString    s1(sBuffer);

    std::cin.getline(sBuffer, 256);
    MyString    s2(sBuffer);

    char    oper[3];
    while(oper[0] != 'X')
    {
        std::cin.getline(oper, 3);
        switch(oper[0])
        {
            case '+': std::cout << (s1+s2) << std::endl; break;
            case '<': std::cout << (s1<s2) << std::endl; break;
            default: break;
        }
    }

    return 0;
}