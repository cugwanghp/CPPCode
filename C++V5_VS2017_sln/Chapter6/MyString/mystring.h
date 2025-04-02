#pragma once

#include <iostream>

class MyString
{
public:
    MyString();        //构造函数
    MyString(const char* pstr);    //构造函数
    MyString(const MyString& str);    //拷贝构造函数
		MyString(MyString&& str);		//移动构造函数
    ~MyString();    //析构函数

    //赋值函数
    MyString& operator=(const MyString& str);
		MyString& operator=(MyString&& str);

    int size() const;                //返回字符串长度
    const char* c_str() const;    //返回字符串首地址

    // 比较大小
    bool operator<(const MyString& str) const;
    bool operator==(const MyString& str) const;
    bool operator>(const MyString& str) const;
    bool operator<=(const MyString& str) const;
    bool operator>=(const MyString& str) const;
    bool operator!=(const MyString& str) const;

    //合并字符串
    MyString operator+(const MyString& str) const;
    MyString& operator+=(const MyString& str);

    //返回某个字符，从0开始
    char operator[](int index) const;
    char& operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);    //输出字符串

private:
    char*   m_pstr;
};

std::ostream& operator<<(std::ostream& os, const MyString& str);