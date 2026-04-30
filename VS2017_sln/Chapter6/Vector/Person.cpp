#include "Person.h"
#include <iostream>

Person::Person(const std::string& name, int age) {
		this->name = name;
		this->age = age;
}

void Person::print() const {
		std::cout << name << "\t" << age << std::endl;
}

Student::Student(const std::string& name, int age,
								int stuId, int grade) : Person(name, age){
		this->stuId = stuId;
		this->grade = grade;
}

void Student::print() const {
		//std::cout << name << "\t" << age << "\t";
		Person::print();		//Person.print()
		std::cout << stuId << "\t" << grade << std::endl;
}

Student::Student(const Student& other) : Person(other){
		this->stuId = other.stuId;
		this->grade = other.grade;
}