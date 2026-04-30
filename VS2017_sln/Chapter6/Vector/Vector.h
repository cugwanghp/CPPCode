#pragma once
#include <initializer_list>

class Vector
{
public:
		//constructor & deconstructor
		Vector();
		Vector(size_t size, int val = 0);
		Vector(std::initializer_list<int> lst);
		Vector(const Vector& vec);
		Vector(Vector&& vec);
		Vector operator=(const Vector& vec);
		Vector operator=(Vector&& vec);
		~Vector();

		// element access
		int& operator[](size_t index);
		const int& operator[](size_t index) const;
		void push_back(int val);
		void pop_back();

		// get methods
		size_t size() const { return m_size; }
		size_t capacity() const { return m_len; }
		int* data() { return m_pData; }
		const int* data() const { return m_pData; }
		bool empty() const { return size() == 0; }
private:
		int*		m_pData;		//数组首地址
		size_t	m_size;			//数组元素的个数
		size_t	m_len;			//数组的容积		
};

/*
class Vector
{
public:
		typedef int* iterator;

		Vector();
		Vector(size_t size, int elem=0);
		Vector(const int* pData, int n);
		Vector(std::initializer_list<int> lst);
		Vector(const Vector& vec);
		Vector(Vector&& vec);
		Vector operator=(const Vector& vec);
		~Vector();

		// Element access
		const int& operator[](size_t index) const;
		int& operator[](size_t index);
		const int* data() const;
		int* data();
		int* begin();
		const int* begin() const;
		int* end();
		const int* end() const;

		// Capacity
		bool empty() const;
		size_t size() const;
		size_t capacity() const;

		// Modifies
		void clear();
		int* insert(int*, int);
		void erase(int* pos);
		void erase(int* beg, int* end);
		void push_back(int val);
		void pop_back();
private:
		int*		m_pData;		//数组首地址
		size_t	m_size;			//数组元素的个数
		size_t	m_len;			//数组的容积		
};
*/
class Array {
public:
		Array(int n);
		Array(const Array& other);
		Array(Array&& other);
		~Array();
private:
		int*		pData;
		int			len;
};
