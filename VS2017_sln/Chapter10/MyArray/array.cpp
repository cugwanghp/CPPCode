#include "array.h"
#include <iostream>

array::array(int n, int* pdata) : m_size(n) {
		m_pdata = new int[m_size];
		if (pdata) {
				for (int i = 0; i < n; ++i)
						m_pdata[i] = pdata[i];
		}
		std::cout << "array constructor.\n";
}

array::~array() {
		delete[] m_pdata;
		m_size = 0;
		std::cout << "array deconstructor.\n";
}

array::array(const array& other) : m_size(other.m_size) {
		m_pdata = new int[m_size];
		for (int i = 0; i < m_size; ++i)
				m_pdata[i] = other.m_pdata[i];
		std::cout << "array copy constructor.\n";
}

array& array::operator=(const array& other) {
		if (this == &other)
				return *this;
		int*    pdata = new int[other.m_size];
		for (int i = 0; i < other.m_size; ++i)
				pdata[i] = other.m_pdata[i];

		delete[] m_pdata;
		m_size = other.m_size;
		m_pdata = pdata;

		std::cout << "array copy assignment.\n";
		return *this;
}
/*
array::array(array&& arr) : m_size(arr.m_size), m_pdata(arr.m_pdata)
{
		arr.m_pdata = nullptr;
		arr.m_size = 0;
		std::cout << "array move constructor.\n";
}

array& array::operator=(array&& arr){
		if (this == &arr)
				return *this;
		delete[] m_pdata;
		m_size = arr.m_size;
		m_pdata = arr.m_pdata;

		arr.m_pdata = nullptr;
		arr.m_size = 0;

		std::cout << "array move assignment.\n";
		return *this;
}
*/
array array::operator*(int scale) const {
		array   arr{ *this };
		for (int i = 0; i < m_size; ++i)
				arr[i] *= scale;
		return arr;
}

int& array::operator()(int index)
{
		return m_pdata[index];
}

const int& array::operator()(int index) const
{
		return m_pdata[index];
}

array operator*(int scale, const array& arr) {
		return arr * scale;
}