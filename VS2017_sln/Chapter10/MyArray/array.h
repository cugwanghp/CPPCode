#pragma once

class array {
public:
		array(int n, int* pdata = nullptr);
		array(const array& other);
		array& operator=(const array& other);
//		array(array&& arr);
//		array& operator=(array&& arr);
		~array();

		int size() const { return m_size; }
		int& operator[](int index) { return m_pdata[index]; }
		const int& operator[](int index) const { return m_pdata[index]; }
		array operator*(int scale) const;
		int& operator()(int index);
		const int& operator()(int index) const;
private:
		int*    m_pdata;
		int     m_size;
};
array operator*(int scale, const array& arr);
