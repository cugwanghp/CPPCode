#include "SportsStudent.h"
#include <iostream>

SportsStudent::SportsStudent(const std::string& name,
		int age, enum SportsEvents sportsEvent,
		double score, int stuId, int grade)
		: Player(name, age, sportsEvent, score), 
		Student(name, age+1, stuId, grade), Person(name, age)
{

}

void SportsStudent::print() const
{
		Player::print();
		std::cout << ", ";
		Student::print();
}