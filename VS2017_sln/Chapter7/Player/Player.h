#pragma once
#include "Person.h"

class Player : public Person
{
public:
		Player(const std::string& name = "", int age = 0, double score = 0.0);
		~Player() = default;

		void print() const;
private:
		double	m_score;
};

