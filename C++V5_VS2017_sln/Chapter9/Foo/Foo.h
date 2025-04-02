#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Foo
{
public:
	int		m_id;
	long	m_data;
	string	m_str;

public:
	Foo(int id=0) : m_id(id) { cout << "default ctor. this=" << this << "id=" << m_id << endl; }
	virtual ~Foo() { cout << "dtor. this=" << this << "id=" << m_id << endl; }

	static void* operator new(size_t size);
	static void operator delete(void* pdead, size_t size);
	static void* operator new[](size_t size);
	static void operator delete[](void* pdead, size_t size);
};

