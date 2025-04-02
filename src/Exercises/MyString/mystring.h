#pragma once

#include <iostream>

class MyString
{
public:
    MyString(const char* pstr);    //构造函数
    MyString(const MyString& str);    //拷贝构造函数
    ~MyString();    //析构函数

    int size() const;                //返回字符串长度
    const char* c_str() const;    //返回字符串首地址

    MyString& append(const MyString& str);    //合并字符串str

private:
    char*   m_pstr;
};
