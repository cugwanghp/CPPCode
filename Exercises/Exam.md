<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-05-08 08:43:47
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-05-08 11:48:42
-->
# OOPCPP Exam

1. 实现复数（分数）类，操作符+-*/输入输出流的重载，下列测试代码能正确运行。
- Complex.h
```c++
#pragma once
#include <iostream>

class Complex
{
public:
    Complex(double real=0.0, double image=0.0);
    
    Complex operator-() const;
    Complex operator+(const Complex& c2) const;
    Complex operator-(const Complex& c2) const;
    Complex operator*(const Complex& c2) const;
    Complex operator/(const Complex& c2) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

private:
    double      m_real;
    double      m_image;
};

std::ostream& operator<<(std::ostream& os, const Complex& c);
std::istream& operator>>(std::istream& is, Complex& c);
```
- Complex.cpp
```c++
#include "Complex.h"

Complex::Complex(double real, double image) : m_real(real), m_image(image)
{
}
    
Complex Complex::operator-() const
{
    return Complex(-m_real, -m_image);
}

Complex Complex::operator+(const Complex& c2) const
{
    return Complex(m_real+c2.m_real, m_image+c2.m_image);
}

Complex Complex::operator-(const Complex& c2) const
{
    return Complex(m_real-c2.m_real, m_image-c2.m_image);
}

Complex Complex::operator*(const Complex& c2) const
{
    return Complex(m_real*c2.m_real-m_image*c2.m_image, m_real*c2.m_image+m_image*c2.m_real);
}

Complex Complex::operator/(const Complex& c2) const
{
    double  norm = c2.m_real*c2.m_real + c2.m_image*c2.m_image;
    return Complex((m_real*c2.m_real+m_image*c2.m_image)/norm, (m_image*c2.m_real-m_real*c2.m_image)/norm);
}
    
std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c.m_real << "," << c.m_image;
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
    is >> c.m_real >> c.m_image;
    return is;
}
```
- main.cpp
```c++
#include <iostream>
#include "Complex.h"

int main()
{
    Complex     c1(1,2), c2(4,3);
    
    std::cout << -c1*c2+c1/c2-c1 << std::endl;
    return 0;
}
```

1. 封装指针的数组类，实现[],T*()，拷贝构造，移动构造，赋值操作符。（备选：设计一个shared_ptr类）
```c++
#include <iostream>
#include <initializer_list>

template<typename T>
class Array{
public:
    Array(int n)
    {
        m_pdata = new int[n]{0};
        m_size = n;
    }
    
    Array(const std::initializer_list<T>& lst)
    {
        m_pdata = new int[lst.size()];
        m_size = lst.size();
        int i = 0;
        for (const auto& elem : lst)
            m_pdata[i++] = elem;
    }
    
    Array(const Array<T>& arr)
    {
        m_pdata = new int[arr.size()];
        m_size = arr.size();
        for (int i=0; i<m_size; ++i)
        {
            m_pdata[i] = arr.m_pdata[i];
        }
    }
    
    Array(Array<T>&& arr)
    {
        m_pdata = arr.m_pdata;
        m_size = arr.m_size;
        
        arr.m_pdata = nullptr;
        arr.m_size = 0;
    }
    
    Array& operator=(const Array<T>& arr)
    {
        if (this == &arr)
            return *this;
        
        T*  pdata = new int[arr.size()];
        for (int i=0; i<arr.size(); ++i)
            pdata[i] = arr.m_pdata[i];
        
        delete[] m_pdata;
        m_pdata = pdata;
        m_size = arr.m_size;
    }
    
    Array& operator=(Array<T>&& arr)
    {
        if (this == &arr)
            return *this;
        
        delete[] m_pdata;
        
        m_pdata = arr.m_pdata;
        m_size = arr.m_size;
        
        arr.m_pdata = nullptr;
        arr.m_size = 0;
    }
    
    
    ~Array()
    {
        delete[] m_pdata;
        m_size = 0;
    }
    
    const T& operator[](int index) const { return m_pdata[index];}
    T& operator[](int index) { return m_pdata[index];}
    int size() const {return m_size;}
    
    T sum() const
    {
        T   total{0};
        for (int i=0; i<m_size; ++i)
            total += m_pdata[i];
        return total;        
    }
    
private:
    T*  m_pdata;
    int m_size;
};

int main()
{
    Array   arr{1,2,3,4,5};

    std::cout << arr.sum() << std::endl;
    return 0;
}
```

3. 实现表达式+-*/^的运算（不包括括号），考虑运算符的优先级。（提示：使用栈）

4. Animals 类的继承，或者是Shape类。
