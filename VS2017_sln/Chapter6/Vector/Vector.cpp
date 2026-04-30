#include "Vector.h"

//constructor & deconstructor
Vector::Vector() : m_size(0), m_len(1)
{
		m_pData = new int[m_len];
}

Vector::Vector(size_t size, int val) : m_size(size)
{
		// size 是2的幂次数
		if (m_size & (m_size - 1) == 0)
				m_len = m_size;
		else
		{
				m_len = 1;	// 初始化1
				while (m_len < m_size)	//大于m_size的最小的2幂次数
				{
						m_len <<= 1;
				}
		}

		// 初始化数组
		m_pData = new int[m_len];
		for (int i = 0; i < m_size; ++i)
				m_pData[i] = val;
}

Vector::Vector(std::initializer_list<int> lst) : m_size(lst.size())
{
		// size 是2的幂次数
		if (m_size & (m_size - 1) == 0)
				m_len = m_size;
		else
		{
				m_len = 1;	// 初始化1
				while (m_len < m_size)	//大于m_size的最小的2幂次数
				{
						m_len <<= 1;
				}
		}

		m_pData = new int[m_len];
		for (auto& elem : lst)
		{
				*m_pData++ = elem;
		}
		m_pData -= m_size;
}

Vector::Vector(const Vector& vec) : m_len(vec.m_len), m_size(vec.m_size)
{
		m_pData = new int[m_len];
		for (int i = 0; i < m_len; ++i)
				m_pData[i] = vec.m_pData[i];
}

Vector::Vector(Vector&& vec) : m_len(vec.m_len), m_size(vec.m_size)
{
		m_pData = vec.m_pData;
		vec.m_pData = nullptr;
}

Vector Vector::operator=(const Vector& vec)
{
		if (this != &vec)
		{
				int*		pData = new int[vec.m_len];
				for (int i = 0; i < vec.m_size; ++i)
				{
						pData[i] = vec.m_pData[i];
				}

				if (m_pData)
						delete[] m_pData;

				m_pData = pData;
				m_len = vec.m_len;
				m_size = vec.m_size;
		}
		return *this;
}

Vector Vector::operator=(Vector&& vec)
{
		if (this != &vec)
		{
				if (m_pData)
						delete[] m_pData;

				m_pData = vec.m_pData;
				m_len = vec.m_len;
				m_size = vec.m_size;

				vec.m_pData = nullptr;
				vec.m_len = 0;
				vec.m_size = 0;
		}

		return *this;
}

Vector::~Vector()
{
		if (m_pData)
				delete[] m_pData;
		
		m_pData = nullptr;
		m_len = 0;
		m_size = 0;
}

// element access
int& Vector::operator[](size_t index)
{
		return m_pData[index];
}

const int& Vector::operator[](size_t index) const
{
		return m_pData[index];
}

void Vector::push_back(int val)
{
		if (m_size == m_len)
		{
				m_len *= 2;
				int* pData = new int[m_len];
				for (int i = 0; i < m_size; ++i)
				{
						pData[i] = m_pData[i];
				}

				if (m_pData)
						delete[] m_pData;
				m_pData = pData;
		}

		m_pData[m_size++] = val;
}

void Vector::pop_back()
{
		if (!empty())
				m_pData[--m_size];
}
// 构造函数
Array::Array(int n) {
		len = n;
		pData = new int[len];
}

Array::Array(const Array& other) {
		this->len = other.len;	//
		this->pData = new int[len];
		for (int i = 0; i < len; i++)
				pData[i] = other.pData[i];
}

Array::Array(Array&& other) {
		this->len = other.len;
		this->pData = other.pData;
		other.pData = nullptr;
		other.len = 0;
}


Array::~Array() {
		if (pData) delete[] pData;
		pData = nullptr;
		len = 0;
}