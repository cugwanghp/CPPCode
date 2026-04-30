#include "Player.h"
#include <iostream>

// 体育运动名称
const char* SportsName[] = { "basketball",
														 "football",
														 "volleyball",
														 "table tennis",
														 "badminton",
														 "tennis",
														 "baseball",
														 "softball",
														 "handball" };

Player::Player(const std::string& name, int age, 
		SportsEvents event, double score) :
		Person(name, age), m_sportsEvents(event), m_score(score)
{
}

void
Player::print() const
{
		Person::print();
		std::cout << ", " << SportsName[(int)m_sportsEvents];
		std::cout << ", " << m_score;
}