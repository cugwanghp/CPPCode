#include "Student.h"
#include <iostream>

Student::Student(const std::string& name, int age,
		int stuId, int grade)
		: Person(name, age), m_stuId(stuId), m_grade(grade) {
}

void Student::print() const
{
		Person::print();
		std::cout << ", " << m_stuId;
		std::cout << ", " << m_grade;
}