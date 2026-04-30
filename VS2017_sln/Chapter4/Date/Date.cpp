#include "Date.h"
#include <iostream>

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::print() const
{
    std::cout << day << "/" << month << "/" << year;
}

int Date::getWeekOfYear() const
{
    // This is a placeholder implementation. The actual calculation would depend on the specific calendar rules.
    return (month - 1) * 4 + (day - 1) / 7 + 1;
}

int Date::getDaysInMonth() const
{
    // This is a placeholder implementation. The actual calculation would depend on the specific calendar rules.
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        }
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int Date::getWeekOfMonth() const
{
    // This is a placeholder implementation. The actual calculation would depend on the specific calendar rules.
    return (day - 1) / 7 + 1;
}

void Date::printMonthCalendar() const
{
    // This is a placeholder implementation. The actual calendar would depend on the specific calendar rules.
    std::cout << "Calendar for " << month << "/" << year << ":\n";
    std::cout << "Sun Mon Tue Wed Thu Fri Sat\n";
    int daysInMonth = getDaysInMonth();
    for (int i = 1; i <= daysInMonth; ++i) {
        std::cout << (i < 10 ? "  " : " ") << i;
        if ((i + (getWeekOfYear() - 1) * 7) % 7 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}