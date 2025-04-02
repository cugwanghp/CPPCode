#include "Array.h"
#include <cassert>
#include <iostream>

Array::Array(int n) : m_nSize(n)	//构造函数
{
		std::cout << "constructor.\n";
		m_pData = new int[m_nSize];
		if (m_pData)
		{
				for (int i = 0; i < m_nSize; ++i)
						m_pData[i] = i + 1;
		}
}

Array::Array(const Array& arr)//拷贝构造
{
		std::cout << "copy constructor.\n";
		this->m_nSize = arr.m_nSize;
		this->m_pData = new int[m_nSize];
		if (m_pData)
		{
				for (int i = 0; i < m_nSize; ++i)
				{
						m_pData[i] = arr.m_pData[i];
				}
		}
}

Array::Array(Array&& arr)
{
		std::cout << "move constructor.\n";

		m_pData = arr.m_pData;
		m_nSize = arr.m_nSize;

		arr.m_pData = nullptr;
		arr.m_nSize = 0;
}

Array& Array::operator=(const Array& arr)
{
		std::cout << "assignment.\n";
		int*	pnewData = new int[arr.m_nSize];
		if (pnewData)
		{
				for (int i = 0; i < arr.m_nSize; ++i)
				{
						pnewData[i] = arr.m_pData[i];
				}
				if (m_pData)
				{
						delete[] m_pData;
						m_pData = nullptr;
				}

				m_nSize = arr.m_nSize;
				m_pData = pnewData;
		}

		return *this;
}

Array::~Array()	//析构函数
{
		std::cout << "deconstructor.\n";
		if (m_pData)
		{
				delete[] m_pData;
				m_pData = nullptr;
		}

		m_nSize = 0;
}

int& Array::operator[](int idx)//重载操作符[]
{
		assert(m_pData && idx >= 0 && idx <= m_nSize);
		return m_pData[idx];
}

const int& Array::operator[](int idx) const//重载操作符[]
{
		assert(m_pData && idx >= 0 && idx <= m_nSize);
		return m_pData[idx];
}

Array make_array(int n)
{
//		Array		arr(n);
		return Array(n);
}