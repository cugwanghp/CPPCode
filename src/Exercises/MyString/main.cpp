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
    MyString    s1("I am a ");
    MyString    s2("CUGer");   
    s1.append(s2); 
    std::cout << s1.c_str() << std::endl;
    return 0;
}

