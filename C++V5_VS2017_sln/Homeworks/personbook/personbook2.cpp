#include "personbook2.h"

bool personbook2::add(const person2& p)
{
	if (m_nsize < MAX_PERSONS - 1)
	{
		m_vecPersons[m_nsize++] = p;
		return true;
	}
	return false;
}

bool personbook2::del(int index)
{
	if (index <= m_nsize && index>0)
	{
		for (int i=index; i<m_nsize; ++i)
			m_vecPersons[i-1] = m_vecPersons[i];
		
		--m_nsize;
		return true;
	}
	return false;
}

bool personbook2::mod(int index, const person2& p)
{
	if (index <= m_nsize && index>0)
	{
		m_vecPersons[index - 1] = p;
		return true;
	}
	return false;
}

void personbook2::list() const
{
	for (int i=0; i<m_nsize; ++i)
	{
		cout << m_vecPersons[i] << endl;
	}
}

void personbook2::clear()
{
	m_nsize = 0;
}