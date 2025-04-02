/*
1. 实现具有整数计数器的类Counter。该类应满足以下要求：
    \begin{enumerate}
        \item 提供一个构造函数，该构造函数接收一个用于初始化计数器值的 int 参数值。
        该参数的默认值应为零。
        \item 提供前缀递增和后缀递增操作符重载函数。
        \item 提供一个成员函数 getValue，用于返回当前的计数器值。
    \end{enumerate}
    此外，该类必须跟踪当前存在多少个计数器对象。应提供查询计数的方法。
    代码不得使用任何全局变量。（提示：使用静态成员）。
*/
#include <iostream>
#include "Counter.h"
#include <iomanip>

int main()
{
    Counter c1, c2(5);
    Counter c3[5];

    std::cout << c1.getObjCount() << std::endl;
    std::cout << c2.getValue() << std::endl;

    return 0;
}