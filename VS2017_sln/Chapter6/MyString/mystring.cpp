#include "mystring.h"
#include <memory.h>

MyString::MyString()       //构造函数
{
    m_pstr = nullptr;
}

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

MyString::MyString(MyString&& str) : m_pstr(str.m_pstr) {
		str.m_pstr = nullptr;
}

MyString::~MyString()    //析构函数
{
    if (m_pstr) delete[] m_pstr;
    m_pstr = nullptr;
}

//赋值函数
MyString& MyString::operator=(const MyString& str)
{
    if (str.m_pstr != m_pstr){
        int len = 0;
        const char* p = str.m_pstr;
        while(p && *p){
            len++;
            p++;
        }
        char* pNewStr = new char[len + 1];        //分配内存
        memcpy(pNewStr, str.m_pstr, len+1);
        if (m_pstr) delete[] m_pstr;
        m_pstr = pNewStr;
    }
    return *this;
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

// 比较大小
bool MyString::operator<(const MyString& str) const
{
    const char* pstr1 = m_pstr;
    const char* pstr2 = str.m_pstr;
    while(*pstr1 && *pstr2){
        if (*pstr1 < *pstr2) return true;
        if (*pstr1 > *pstr2) return false;
        pstr1++;
        pstr2++;
    }
    if (*pstr1) return false;
    if (*pstr2) return true;
    return false;
}

bool MyString::operator==(const MyString& str) const
{
    const char* pstr1 = m_pstr;
    const char* pstr2 = str.m_pstr;
    while(*pstr1 && *pstr2){
        if (*pstr1 != *pstr2) return false;
        pstr1++;
        pstr2++;
    }
    if (*pstr1 || *pstr2) return false;
    return true;
}

bool MyString::operator>(const MyString& str) const
{
    const char* pstr1 = m_pstr;
    const char* pstr2 = str.m_pstr;
    while(*pstr1 && *pstr2){
        if (*pstr1 > *pstr2) return true;
        if (*pstr1 < *pstr2) return false;
        pstr1++;
        pstr2++;
    }
    if (*pstr1) return true;
    if (*pstr2) return false;
    return false;
}

bool MyString::operator<=(const MyString& str) const
{
    return (*this < str || *this == str);
}

bool MyString::operator>=(const MyString& str) const
{
    return (*this > str || *this == str);
}

bool MyString::operator!=(const MyString& str) const
{
    return !(*this==str);
}

//合并字符串
MyString MyString::operator+(const MyString& str) const
{
    char*   pNewStr = new char[size()+str.size()+1];
    memcpy(pNewStr, m_pstr, size());
    memcpy(pNewStr+size(), str.m_pstr, str.size());
    pNewStr[size()+str.size()] = '\0';        //加上结束符
    MyString    newStr(pNewStr);
    delete[] pNewStr;
    return newStr;
}

MyString& MyString::operator+=(const MyString& str)
{
    char*   pNewStr = new char[size()+str.size()+1];
    memcpy(pNewStr, m_pstr, size());
    memcpy(pNewStr+size(), str.m_pstr, str.size());
    pNewStr[size()+str.size()] = '\0';        //加上结束符
    if (m_pstr) delete[] m_pstr;        //释放原有内存
    m_pstr = pNewStr;        //指向新内存
    return *this;
}

//返回某个字符，从0开始
char MyString::operator[](int index) const
{
    return m_pstr[index];
}

char& MyString::operator[](int index)
{
    return m_pstr[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& str)    //输出字符串
{
    os << str.m_pstr;
    return os;
}
