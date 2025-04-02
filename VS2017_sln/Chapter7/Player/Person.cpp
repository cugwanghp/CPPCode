#include "Person.h"
#include <iostream>

Person::Person(const std::string& name, int age) : m_name(name), m_age(age)
{
}

void Person::print() const
{
		std::cout << m_name << ", " << m_age;
}

