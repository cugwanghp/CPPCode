#include "String.h"

String::String()
{
}

String::String(const char *pstr)
{
    while (*pstr){
        m_data.push_back(*pstr++);
    }
}

String::String(const String& str) : m_data(str.m_data)
{
}

String::String(String&& str) : m_data(std::move(str.m_data))
{
}

String& String::operator=(const String& str)
{
    if (this == &str)
        return *this;

    m_data = str.m_data;
    return *this;
}

String& String::operator=(String&& str)
{
    m_data = std::move(str.m_data);

    return *this;
}

String& String::operator+=(const String &str)
{
    m_data.insert(m_data.end(), str.m_data.begin(), str.m_data.end());
    return *this;
}

String String::operator+(const String &str) const
{
    String  resStr = *this;
    resStr += str;

    return resStr;
}

const char & String::operator[](int index) const
{
    return m_data[index];
}

char &String::operator[](int index)
{
    return m_data[index];
}

const char *String::c_str() const
{
    static std::vector<char>    cstr;
    cstr = m_data;
    cstr.push_back('\0');

    return cstr.data();
}

int String::size() const
{
    return m_data.size();
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    for (const auto& c : str.m_data)
        os << c;
    return os;
}

std::istream &operator>>(std::istream &is, String &str)
{
    char    ch;
    while(is.get(ch) && ch!='\n')
    {
        str.m_data.push_back(ch);
    }
    return is;
}