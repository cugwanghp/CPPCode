#pragma once
#include "Person.h"

// 体育项目
enum class SportsEvents{ basketball , football, volleyball,
		tabletennis, badminton, tennis, baseball, softball, handball};

class Player : virtual public Person
{
public:
		Player(const std::string& name = std::string(), 
				int age = 0, enum SportsEvents event=SportsEvents::basketball,
				double score = 0.0);
		~Player() = default;

		void print() const;
private:
		SportsEvents		m_sportsEvents;
		double	m_score;
};

