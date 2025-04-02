#pragma once
#include <iostream>
using namespace std;

struct score
{
	double m_score;
	int m_index;

	bool operator<(const score& s2) const { return m_score < s2.m_score; }
};

class Scorebook
{
public:
	bool add(const score& x);
	bool del(int index);
	void list();
	void help();
	struct score min();
	struct score max();
	double averageScore();		//¾ùÖµ
	double StadScore();			//·½²î
private:
	static constexpr int scoreMaxNum = 100;
	score	m_scorebook[scoreMaxNum] = {};
	int		m_size;
};