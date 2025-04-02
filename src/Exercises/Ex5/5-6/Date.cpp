#include "Date.h"
#include <iostream>
#include <stdexcept>

// Normalize the date when day goes beyond the last day of the month or below 1
void Date::normalize()
{
    while (day > getDaysInMonth(year, month))
    {
        day -= getDaysInMonth(year, month);
        if (++month > 12)
        {
            month = 1;
            ++year;
        }
    }

    while (day < 1)
    {
        if (--month < 1)
        {
            month = 12;
            --year;
        }
        day += getDaysInMonth(year, month);
    }
}

// Constructor with default parameters
Date::Date(int y, int m, int d) : year(y), month(m), day(d)
{
    // It would be a good idea to add validation here for correct dates
    normalize();
}

// Overload "+" operator to add days
Date Date::operator+(int days) const
{
    Date newDate = *this;
    newDate.day += days;
    newDate.normalize();
    return newDate;
}

// Overload "-" operator to subtract days
Date Date::operator-(int days) const
{
    Date newDate = *this;
    newDate.day -= days;
    newDate.normalize();
    return newDate;
}

// Overload "+=" operator
Date &Date::operator+=(int days)
{
    day += days;
    normalize();
    return *this;
}

// Overload "-=" operator
Date &Date::operator-=(int days)
{
    day -= days;
    normalize();
    return *this;
}

// Overload "<" operator
bool Date::operator<(const Date &other) const
{
    return (year*10000L+month*100+day) < (other.year*10000L+other.month*100+other.day);
}

// Overload ">" operator
bool Date::operator>(const Date &other) const
{
    return other < *this;
}

// Overload "==" operator
bool Date::operator==(const Date &other) const
{
    return year == other.year && month == other.month && day == other.day;
}

// Overload "!=" operator
bool Date::operator!=(const Date &other) const
{
    return !(*this == other);
}

// Overload "<=" operator
bool Date::operator<=(const Date &other) const
{
    return !(*this > other);
}

// Overload ">=" operator
bool Date::operator>=(const Date &other) const
{
    return !(*this < other);
}

// Overload "<<" operator for output streams
std::ostream &operator<<(std::ostream &os, const Date &date)
{
    os << date.year << '/' << date.month << '/' << date.day;
    return os;
}

// Overload ">>" operator for input streams
std::istream &operator>>(std::istream &is, Date &date)
{
    is >> date.year >> date.month >> date.day;
    date.normalize();
    return is;
}

int main()
{
    Date date1(2023, 3, 14); // Pi Day!
    std::cout << "Date1: " << date1 << std::endl;

    Date date2 = date1 + 10; // Add 10 days
    std::cout << "Date2: " << date2 << std::endl;

    date2 -= 5; // Subtract 5 days
    std::cout << "Date2 after -=5: " << date2 << std::endl;

    if (date1 < date2)
    {
        std::cout << "Date1 is before Date2" << std::endl;
    }

    if (date2 > date1)
    {
        std::cout << "Date2 is after Date1" << std::endl;
    }

    if (date1 != date2)
    {
        std::cout << "Date1 and Date2 are not the same" << std::endl;
    }

    // Example of using the >> operator
    Date dateInput;
    std::cout << "Enter a date in the format YYYY MM DD: ";
    std::cin >> dateInput;
    std::cout << "You entered: " << dateInput << std::endl;

    return 0;
}
