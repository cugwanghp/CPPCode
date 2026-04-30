#pragma once

#include <string>
class Person {
public:
		Person(const std::string& name, int age);
		const std::string& getName() const { return name; }
		int getAge() const { return age; }
		void print() const;
protected:
		std::string			name;
		int							age;
};

class Student : public Person {
public:
		Student(const std::string& name, int age, 
						int stuId, int grade);
		Student(const Student& other);
		int getStuId() const { return stuId; }
		int getGrade() const { return grade; }
		void print() const;
protected:
		int			stuId;
		int			grade;
};