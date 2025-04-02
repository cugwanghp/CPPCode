#include "personbook.h"

personbook::~personbook()
{
	clear();
}
	
bool personbook::add(const person& p)
{
	m_vecPersons.push_back(p);
	return true;
}

bool personbook::del(int index)
{
	if (index <= m_vecPersons.size())
	{
		m_vecPersons.erase(m_vecPersons.begin() + index - 1);
		return true;
	}
	return false;
}

bool personbook::mod(int index, const person& p)
{
	if (index <= m_vecPersons.size())
	{
		auto iter = m_vecPersons.begin() + index - 1;
		iter->set_name(p.get_name());
		iter->set_address(p.get_address());
		return true;
	}
	return false;
}

void personbook::clear()
{
	m_vecPersons.clear();
}

void personbook::list() const
{
	for (const auto& p : m_vecPersons)
	{
		cout << p << endl;
	}
}