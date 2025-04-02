#include "Counter.h"

int Counter::m_countObj = 0;

Counter::Counter(int val) : m_val(val)
{
    ++m_countObj;
}
Counter& Counter::operator++()       // 前置
{
    ++m_val;
    return *this;
}

Counter Counter::operator++(int)   // 后置
{
    Counter old = *this;

    m_val ++;

    return old;
}

Counter& Counter::operator--()  // 前置--
{
    m_val--;
    return *this;
}

Counter Counter::operator--(int)   // 后置--
{
    Counter old = *this;

    m_val--;
    
    return old;
}