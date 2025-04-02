#pragma once

#include "person2.h"

constexpr int MAX_PERSONS = 100;

class personbook2 {
public:
	bool add(const person2& p);
	bool del(int index);
	bool mod(int index, const person2& p);
	void clear();
	void list() const;
private:
	person2		m_vecPersons[MAX_PERSONS];
	int			m_nsize = 0;
};
