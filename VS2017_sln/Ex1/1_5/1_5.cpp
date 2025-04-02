#include <iostream>

struct time {
	int     year;
	int     month;
	int     day;
	int     hour;
	int     minute;
	double  second;
};

int getMonthDays(int year, int month)
{
	int	days = 30;

	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		days = 31;
		break;
	case 2:
		days = ((year%4==0 && year%100!=0) || year%400==0) ? 29 : 28;
		break;
	default:
		days = 30;
		break;
	}

	return days;
}

int main()
{
	time    tm;

	do {
		std::cin >> tm.year;
	} while (tm.year < 1);

	do {
		std::cin >> tm.month;
	} while (tm.month < 1 || tm.month>12);

	do {
		std::cin >> tm.day;
	} while (tm.day < 1 || tm.day>getMonthDays(tm.year, tm.month));

	do {
		std::cin >> tm.hour;
	} while (tm.hour < 0 || tm.hour>23);

	do {
		std::cin >> tm.minute;
	} while (tm.minute < 0 || tm.minute>59);

	do {
		std::cin >> tm.second;
	} while (tm.second < 0 || tm.second>59);

	std::cout << tm.year << "-" << tm.month << "-" << tm.day << " ";
	std::cout << tm.hour << ":" << tm.minute << ":" << tm.second << std::endl;
}