#include "IntArray2.h"


IntArray2::IntArray2() : m_row(0), m_col(0)
{
}

IntArray2::IntArray2(int m, int n) : m_row(m), m_col(n), m_data(m, std::vector<int>(n, 0))
{
}

IntArray2::IntArray2(const IntArray2 &arr) : m_row(arr.m_row), m_col(arr.m_col), m_data(arr.m_data)
{
}

IntArray2& IntArray2::operator=(const IntArray2& arr)
{
    if (this != &arr)
    {
        m_row = arr.m_row;
        m_col = arr.m_col;
        m_data = arr.m_data;
    }

    return *this;
}

IntArray2::IntArray2(IntArray2 &&arr) : m_row(arr.m_row), m_col(arr.m_col), m_data(arr.m_data)
{
}

IntArray2& IntArray2::operator=(IntArray2&& arr)
{
    if (this != &arr)
    {
        m_row = arr.m_row;
        m_col = arr.m_col;
        m_data = arr.m_data;
    }

    return *this;
}

IntArray2::~IntArray2()
{
}

int& IntArray2::get(int x, int y)
{
    return m_data[x][y];
}

const int & IntArray2::get(int x, int y) const
{
    return m_data[x][y];
}

std::ostream & operator<<(std::ostream &os, const IntArray2& arr)
{
    for (int i=0; i<arr.m_row; ++i)
    {
        for (int j=0; j<arr.m_col; ++j)
        {
            os << arr.m_data[i][j] << "\t";
        }
        os << std::endl;
    }

    return os;
}

std::istream& operator>> (std::istream &is, IntArray2& arr)
{
 for (int i=0; i<arr.m_row; ++i)
    {
        for (int j=0; j<arr.m_col; ++j)
        {
            is >> arr.m_data[i][j];
        }    
    }

    return is;
}
