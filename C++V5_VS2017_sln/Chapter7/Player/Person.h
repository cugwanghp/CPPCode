#pragma once

#include <string>

class Person
{
public:
		Person(const std::string& name=std::string(), int age=0);
		virtual ~Person() = default;

		void print() const;
protected:
		std::string	m_name;
		int	m_age;
};

