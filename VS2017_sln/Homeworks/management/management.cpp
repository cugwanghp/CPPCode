#include"management.h"
#include <algorithm>
#include <cmath>

//*min_element

bool Scorebook::add(const score& x)
{
	if (m_size < scoreMaxNum)
	{
		m_scorebook[m_size++] = x;
		return true;
	}return false;
}

bool Scorebook::del(int index)
{
	if (index < 0 || index > m_size)
	{
		return false;
	}
	for(int i = index;i< m_size + 1;i++)
	{
		m_scorebook[i - 1] = m_scorebook[i];
	}
	m_size--;
	return true;
}
void Scorebook::list()
{
	for (int i = 0; i < m_size; i++)
	{
		cout << m_scorebook[i].m_index << endl;
		cout << m_scorebook[i].m_score << endl;
	}
}
void Scorebook::help()
{
	cout << "A - Add a score" << endl;
	cout << "D - Del a score" << endl;
	cout << "L - List All scores and count" << endl;
	cout << "M - Minimum of scores " << endl;
	cout << "N - Average of scores" << endl;
	cout << "P - Maximum of scores" << endl;
	cout << "T - Standard derivation of scores " << endl;
	cout << "X - Exit " << endl;
}
struct score Scorebook::min()
{
	return *min_element(m_scorebook, m_scorebook + m_size);
	//m_scorebook->m_index = min_element(m_scorebook, m_scorebook + 100000000) - m_scorebook;
	cout << min_element(m_scorebook, m_scorebook + m_size) - m_scorebook;
}
struct score Scorebook::max()
{
	return *max_element(m_scorebook, m_scorebook + m_size);
	m_scorebook->m_index = max_element(m_scorebook, m_scorebook + m_size) - m_scorebook;
	cout << max_element(m_scorebook, m_scorebook + m_size) - m_scorebook;
}
double Scorebook::averageScore()
{
	double sum1 = 0;
	long len = sizeof(m_scorebook) / sizeof(m_scorebook[0]);
	for (int i = 0; i < len; i++)
	{
		sum1 += m_scorebook[i].m_score;
	}
	return sum1;
}
double Scorebook::StadScore()
{
	double sum2 = 0;
	long len = sizeof(m_scorebook) / sizeof(m_scorebook[0]);
	for (int i = 0; i < len; i++)
	{
		sum2 += pow((averageScore() - m_scorebook[i].m_score), 2);
	}
	double value = sum2 / len;
	return value;
}