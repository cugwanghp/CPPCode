#pragma once

template <typename T>
class Storage8
{
public:
		T& operator[](int index);
		const T& operator[](int index) const;
private:
		T		m_array[8];	//
};

template<typename T>
T& Storage8<T>::operator[](int index)
{
		if (index >= 0 && index < 8)
				return m_array[index];
		return m_array[0];
}

template<typename T>
const T& Storage8<T>::operator[](int index) const
{
		if (index >= 0 && index < 8)
				return m_array[index];
		return m_array[0];
}