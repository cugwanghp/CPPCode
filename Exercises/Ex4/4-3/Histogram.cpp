/*
 * @Description:
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 15:51:45
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 16:06:49
 */
#include "Histogram.h"
#include <utility>
#include <iostream>
#include <iomanip>

//  [0, 3.14), [3.14, 20) ºÍ [20, 42.42)£¬
Histogram::Histogram(std::vector<double> &range) : m_range(range), m_hist(range.size() - 1, 0)
{
}

Histogram::Histogram(const Histogram &hr) : m_range(hr.m_range), m_hist(hr.m_hist)
{
}

Histogram Histogram::operator=(const Histogram &hr)
{
	if (this != &hr)
	{
		m_range = hr.m_range;
		m_hist = hr.m_hist;
	}

	return *this;
}

Histogram::Histogram(Histogram &&hrr)
	: m_range(std::move(hrr.m_range)), m_hist(std::move(hrr.m_hist))
{
}

Histogram Histogram::operator=(const Histogram &&hrr)
{
	if (this != &hrr)
	{
		m_range = std::move(hrr.m_range);
		m_hist = std::move(hrr.m_hist);
	}
	return *this;
}

Histogram::~Histogram()
{
}

void Histogram::clear() //
{
	// m_hist --> 0
	for (auto &elem : m_hist)
	{
		elem = 0;
	}
}

void Histogram::update(double data[], int n) //
{
	int j;

	for (int i = 0; i < n; ++i)
	{
		for (j = 0; j < m_range.size() - 1; ++j)
		{
			if (data[i] >= m_range[j] && data[i] < m_range[j + 1])
			{
				m_hist[j]++;
				break; // Ìø³ö
			}
		}
		if (j == m_range.size() - 1) // not found
		{
			std::cerr << "Input value is not in range." << std::endl;
		}
	}
}

void Histogram::display() const
{
	std::cout << "\tRange |\tHistogram\n";
	for (int i = 0; i < m_range.size() - 1; ++i)
	{
		std::cout << std::setw(2) << m_range[i] << "~" << std::setw(3) << m_range[i + 1] << ":\t";
		std::cout << m_hist[i] << std::endl;
	}
}
