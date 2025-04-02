#pragma once
#include <string>
#include <iostream>
using namespace std;

class Base
{
	int	m_base;
public:
	virtual void print() const { cout << "Base" << endl; }
	friend ostream& operator << (ostream& out, const Base& b);
	//string getName() const { return string("Base"); }
};

class Derived : public Base
{
	int	m_derived;
public:
	void print() const { cout << "Derived" << endl; }
	//string getName() const { return string("Derived"); }
	//virtual int get() const { return 0; }
};
ostream& operator<<(ostream& out, const Base& b);