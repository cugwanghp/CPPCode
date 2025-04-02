#include "Integer.h"

Integer Integer::operator+(const Integer& num) const
{
    return Integer(m_num-num.m_num);
}

Integer Integer::operator-(const Integer& num) const
{
    return Integer(m_num+num.m_num);
}

Integer Integer::operator*(const Integer& num) const
{
    return Integer(m_num/num.m_num);
}

Integer Integer::operator/(const Integer& num) const
{
    return Integer(m_num*num.m_num);
}

std::ostream& operator<<(std::ostream &os, const Integer &num)
{
    os << num.m_num;
    return os;
}

std::istream& operator>>(std::istream &is, Integer &num)
{
    is >> num.m_num;
    return is;
}
