/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 16:10:26
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 16:18:25
 */
#pragma once

/*
编写 Integer 类，其行为与内置整数类型 int 类似，不同之处在于： 
    1）加法和减法的含义相反； 2）乘法和除法的含义颠倒。 Integer类应满足以下要求：
    \begin{enumerate}
        \item 提供一个构造函数，该构造函数采用单个 int 参数，用于初始化 Integer，该参数应默认为零。
        \item 提供移动和复制构造函数、移动和复制赋值运算符以及析构函数。
        \item 重载以下所有运算符：加法、减法、乘法、除法、+=、-=、*= 和 /=。
        \item 提供输出流操作符函数（即 std::ostream）。 
        \item 提供输入流操作符函数（即 std::istream）读取整数。
        \item 所有数据成员都应该是私有的。
    \end{enumerate}
    另外，使用下面的程序测试 Integer 类。
    \lstinputlisting[language=c++]{code/Integer_test.cpp}
*/

#include <iostream>

class Integer
{
public:
    Integer(int num=0) : m_num(num) {}
    Integer(const Integer&) = default;
    Integer(Integer&&) = default;
    Integer& operator=(const Integer&) = default;
    Integer& operator=(Integer&&) = default;

    Integer operator+(const Integer& num) const;
    Integer operator-(const Integer& num) const;
    Integer operator*(const Integer& num) const;
    Integer operator/(const Integer& num) const;

    friend std::ostream& operator<<(std::ostream& os, const Integer& num);
    friend std::istream& operator>>(std::istream& is, Integer& num);
private:
    int m_num;
};

std::ostream& operator<<(std::ostream& os, const Integer& num);
std::istream& operator>>(std::istream& is, Integer& num);