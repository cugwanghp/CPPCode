#pragma once

class Array
{
public:
		Array(int n);	//构造函数
		Array(const Array& arr);//拷贝构造
		Array(Array&& arr);			//移动构造
		~Array();		//析构函数

		Array& operator=(const Array& arr);

		int& operator[](int idx);	//重载操作符[]
		const int& operator[](int idx) const;	//重载操作符[]
private:
		int*	m_pData;	//数组首地址
		int		m_nSize;	//数组长度
};

