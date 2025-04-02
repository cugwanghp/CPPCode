#pragma once

#include<iostream>
#include<string>
using namespace std;

class date
{
private:
	int m_year, m_month, m_day;
	
public:
	date(int year=1, int month=1, int day=1);    //构造函数
	
	int dayofYear();    //年的天数
	int dayofMonth();    //月的天数
	inline bool isLeap(){ return ((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0);	}
    date operator+(int ndays);  //ndays天后的日期
    date operator-(int ndays);  //ndays天前的日期
    
    friend istream& operator>>(istream& in, date& dt);
    friend ostream& operator<<(ostream& out, const date& dt);
};

istream& operator>>(istream& in, date& dt);
ostream& operator<<(ostream& out, const date& dt);
