#pragma once
#include "Person.h"

class Student : virtual	public Person
{
public:
		Student(const std::string& name=std::string(), int age=0, int stuId=0, int grade=0);
		virtual ~Student() = default;
		void print() const;

protected:
		int			m_stuId;
		int			m_grade;
};

