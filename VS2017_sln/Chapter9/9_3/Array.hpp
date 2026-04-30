#pragma once

template<typename T>
class Array
{
public:
		Array(int size);
		Array(const Array<T>& ary);
		Array(Array<T>&& ary);
		~Array();
		Array& operator=(const Array<T>& ary);
		Array& operator=(Array<T>&& ary);	//

		T& operator[](int index);
		const T& operator[](int index) const;
		operator T * () { return m_pdata; }		//重载到T*类型的转换
		operator const T * () const { return m_pdata; }
		inline int getSize() const { return m_nsize; }		//取数组的大小

private:
		T*		m_pdata;		//
		int			m_nsize;		//
};

template<typename T>
Array<T>::Array<T>(int size) : m_nsize(size)
{
		if (m_nsize < 0)	m_nsize = 0;
		m_pdata = new T[m_nsize];
}

template<typename T>
Array<T>::Array<T>(const Array<T>& ary) : m_nsize(ary.m_nsize)
{
		m_pdata = new T[m_nsize];
		for (int i = 0; i < m_nsize; ++i)
				m_pdata[i] = ary.m_pdata[i];
}

template<typename T>
Array<T>::Array<T>(Array<T>&& ary) : m_nsize(ary.m_nsize)
{
		m_pdata = ary.m_pdata;
		ary.m_pdata = nullptr;
		ary.m_nsize = 0;
}

template<typename T>
Array<T>::~Array()
{
		if (m_pdata)
		{
				delete[] m_pdata;
				m_pdata = nullptr;
		}
		m_nsize = 0;
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& ary)
{
		if (this != &ary)
		{
				//this->m_pdata
				int*		pdata = new T[ary.m_nsize];
				for (int i = 0; i < ary.m_nsize; ++i)
						pdata[i] = ary.m_pdata[i];
				if (m_pdata)
				{
						delete[] m_pdata;
				}
				m_pdata = pdata;
				m_nsize = ary.m_nsize;
		}
		return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& ary)
{
		if (this != &ary)
		{
				if (m_pdata) delete[] m_pdata;
				m_pdata = ary.m_pdata;
				m_nsize = ary.m_nsize;
				ary.m_pdata = nullptr;
				ary.m_nsize = 0;
		}
		return *this;
}

template<typename T>
T& Array<T>::operator[](int index)
{
		return m_pdata[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
		return m_pdata[index];
}

