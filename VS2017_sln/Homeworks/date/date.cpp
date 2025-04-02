
#include "date.h"
#include <iomanip>

date::date(int year, int month, int day)
: m_year(year), m_month(month), m_day(day)
{
}

int date::dayofYear()
{
	if (isLeap())
		return 366;
	
	return 365;
}

int date::dayofMonth()
{
    int     days = 0;
    switch(m_month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        days = 31;
        break;
        
        case 2:
        days = (isLeap() ? 29 : 28);
        break;
        
        case 4: case 6: case 9: case 11:
        days = 30;
        break;
        
        default:
        days = 0;
        break;
    }
    
    return days;
}


date date::operator+(int ndays)  //ndays天后的日期
{
    date        newDate = *this;
    //year month day 数字 + ndays
    //year month day+ndays
    //day+ndays > dayofMonth --> month+1 --> 12+1 --> year+1
	if (ndays < 0)
		return operator-(-ndays);
	
    newDate.m_day += ndays;
    while (newDate.m_day > newDate.dayofMonth())
    {
        newDate.m_day -= newDate.dayofMonth();
        
        newDate.m_month++;
        if (newDate.m_month > 12)
        {
            newDate.m_year++;
            newDate.m_month = 1;
        }
    }
    
    return newDate;
}

date date::operator-(int ndays)
{
	if (ndays < 0)
		return operator+(-ndays);
	
    date newDate = *this;
    newDate.m_day -= ndays;
    while(newDate.m_day<1)
    {
        newDate.m_month--;
        if(newDate.m_month < 1)
        {
            newDate.m_year--;
            newDate.m_month = 12;
        }
       newDate.m_day += newDate.dayofMonth();
    }
    return newDate;
}


istream& operator>>(istream& in, date& dt)
{
    int     n;
    in >> n;
    
    dt.m_day = n % 100;
    dt.m_month = ((n-dt.m_day)/100)%100;
    dt.m_year = n / 10000;
    
    return in;
}

ostream& operator<<(ostream& out, const date& dt)
{
    out << setfill('0') << setw(4) << dt.m_year;
    out << setfill('0') << setw(2) << dt.m_month;
    out << setfill('0') << setw(2) << dt.m_day;
    return out;
}