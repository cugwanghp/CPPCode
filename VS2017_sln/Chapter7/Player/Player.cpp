#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, int age, double score) :
		Person(name, age), m_score(score)
{
}

void
Player::print() const
{
		std::cout << m_name << ", " << m_age << ", " << m_score;
}