/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 18:18:24
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 18:18:53
 */
#pragma once

/*
 编写一个 String 类来表示零个或多个字符的序列（即字符串）。任何字符都可以出现在字符串中，包括空
字符（即"\0"）。String 类满足以下要求：
(a). 提供一个默认构造函数来创建空字符串。
(b). 提供一个构造函数，它将指向空终止字符串的指针作为参数，以初始化要创建的对象。
(c). std::vector 类模板可用于存储底层字符串数据。
(d). 类的对象必须是可移动和可复制的。
(e). 运算符 += 和 + 应该执行字符串连接。
(f). 提供下标运算符 [] 访问字符串中的单个字符。
(g). 提供输出流操作符 ?，以便可以将字符串写入输出流（std::ostream）。
(h). 提供输入流操作符 ?，以便可以从输入流（std::istream）读取字符串。
(i). 成员函数 c_str 应该返回一个指向与 String 对象的当前值相对应的以 null 结尾的字符串的指针。更具
体地说，以 null 结尾的字符串应该相当于附加了 null 字符的 String 对象的内容。
(j). 成员函数 size 应返回字符串中的字符数
*/
#include <vector>
#include <iostream>

class String
{
public:
    String();
    String(const char* pstr);
    String(const String&);
    String(String&&);
    String& operator=(const String&);
    String& operator=(String&&);

    String& operator+=(const String& str);
    String operator+(const String& str) const;

    const char& operator[](int index) const;
    char& operator[](int index);

    const char* c_str() const;
    int size() const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
private:
    std::vector<char>   m_data;
};

std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);