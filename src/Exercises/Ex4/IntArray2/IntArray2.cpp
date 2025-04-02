#include "IntArray2.h"

IntArray2::IntArray2() : m_row(0), m_col(0), m_ppData(nullptr)
{
}

IntArray2::IntArray2(int row, int col) : m_row(row), m_col(col)
{
	m_ppData = new int*[m_row];
	for (int i = 0; i < m_row; i++)
	{
		m_ppData[i] = new int[m_col];
	}
}

IntArray2::IntArray2(const IntArray2& arr) : m_row(arr.m_row), m_col(arr.m_col)
{
	m_ppData = new int*[m_row];
	for (int i = 0; i < m_row; i++)
	{
		m_ppData[i] = new int[m_col];
		for (int j = 0; j < m_col; j++)
		{
			m_ppData[i][j] = arr.m_ppData[i][j];
		}
	}
}

IntArray2::IntArray2(IntArray2&& arr) : m_row(arr.m_row), m_col(arr.m_col)
{
	m_ppData = arr.m_ppData;

	arr.m_ppData = nullptr;
	arr.m_row = arr.m_col = 0;
}

IntArray2& IntArray2::operator=(const IntArray2& arr)
{
	if (this == &arr)
		return *this;

	// release
	if (m_ppData != nullptr)
	{
		for (int i = 0; i < m_row; ++i)
			delete[] m_ppData[i];
		delete[] m_ppData;
	}
	
	// create new
	m_row = arr.m_row;
	m_col = arr.m_col;
	m_ppData = new int*[m_row];
	for (int i = 0; i < m_row; i++)
	{
		m_ppData[i] = new int[m_col];
		for (int j = 0; j < m_col; j++)
		{
			m_ppData[i][j] = arr.m_ppData[i][j];
		}
	}
}

IntArray2& IntArray2::operator=(IntArray2&& arr)
{
	if (this == &arr)
		return *this;

	// release
	if (m_ppData != nullptr)
	{
		for (int i = 0; i < m_row; ++i)
			delete[] m_ppData[i];
		delete[] m_ppData;
	}

	// move 
	m_row = arr.m_row;
	m_col = arr.m_col;
	m_ppData = arr.m_ppData;

	arr.m_ppData = nullptr;
	arr.m_row = arr.m_col = 0;
}

IntArray2::~IntArray2()
{
	if (m_ppData != nullptr)
	{
		for (int i = 0; i < m_row; ++i)
			delete[] m_ppData[i];
		delete[] m_ppData;
	}
	m_row = m_col = 0;
}

std::ostream& operator<<(std::ostream& os, const IntArray2& arr)
{
	for (int i = 0; i < arr.m_row; i++) {
		for (int j = 0; j < arr.m_col; j++) {
			os << arr.m_ppData[i][j] << "\t";
		}
		os << std::endl;
	}

	return os;
}

std::istream& operator>>(std::istream& is, IntArray2& arr)
{
	for (int i = 0; i < arr.m_row; i++) {
		for (int j = 0; j < arr.m_col; j++) {
			is >> arr.m_ppData[i][j];
		}
	}

	return is;
}
