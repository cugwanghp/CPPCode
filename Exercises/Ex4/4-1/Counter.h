#pragma once

class Counter{
public:
    Counter(int val = 0);
    Counter& operator++();       // 前置
    Counter operator++(int);    // 后置
    Counter& operator--();      // 前置--
    Counter operator--(int);    // 后置--

    int getValue() const { return m_val; }
    static int getObjCount() { return m_countObj; }
private:
    int m_val;
    static int m_countObj;
};