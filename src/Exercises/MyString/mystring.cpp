#include "mystring.h"
#include <memory.h>

MyString::MyString(const char* pstr)    //构造函数
{
    int len = 0;
    const char* p = pstr;
    while(p && *p){
        len++;
        p++;
    }
    m_pstr = new char[len + 1];        //分配内存    
    memcpy(m_pstr, pstr, len+1);
}

//拷贝构造函数
MyString::MyString(const MyString& str) : MyString(str.m_pstr)
{
}

MyString::~MyString()    //析构函数
{
    if (m_pstr) delete[] m_pstr;
    m_pstr = nullptr;
}

int MyString::size() const                //返回字符串长度
{
    int len = 0;
    const char* p = m_pstr;
    while(p && *p){
        len++;
        p++;
    }
    return len;
}

const char* MyString::c_str() const    //返回字符串首地址
{
    return m_pstr;
}

MyString& MyString::append(const MyString& str)    //合并字符串str
{
    int len = size() + str.size();
    char* p = new char[len + 1];
    memcpy(p, m_pstr, size());
    memcpy(p + size(), str.m_pstr, str.size() + 1);
    delete[] m_pstr;
    m_pstr = p;
    return *this;
}
