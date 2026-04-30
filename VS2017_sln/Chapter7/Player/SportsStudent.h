#pragma once

#include "Student.h"
#include "Player.h"
#include <string>

class SportsStudent : public Student, public Player
{
public:
		SportsStudent(const std::string& name = std::string(),
				int age = 0, SportsEvents sportsEvent = SportsEvents::basketball,
				double score = 0.0, int stuId=0, int grade=0);
		virtual ~SportsStudent() = default;
		void print() const;
};

