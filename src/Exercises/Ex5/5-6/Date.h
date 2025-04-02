/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-30 19:49:26
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-30 19:55:42
 */
#pragma once

#include <iostream>
#include <stdexcept>

class Date {
private:
    int year;
    int month;
    int day;

    // Helper function to check if a given year is a leap year
    static inline bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Helper function to get the number of days in a month
    static inline int getDaysInMonth(int year, int month) {
        const int daysInMonth[] = { 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return daysInMonth[month - 1];
    }

    // Normalize the date when day goes beyond the last day of the month or below 1
    void normalize();

public:
    // Constructor with default parameters
    Date(int y = 1970, int m = 1, int d = 1);

    // Overload "+" operator to add days
    Date operator+(int days) const;

    // Overload "-" operator to subtract days
    Date operator-(int days) const;

    // Overload "+=" operator
    Date& operator+=(int days);

    // Overload "-=" operator
    Date& operator-=(int days);

    // Overload "<" operator
    bool operator<(const Date& other) const;

    // Overload ">" operator
    bool operator>(const Date& other) const;

    // Overload "==" operator
    bool operator==(const Date& other) const;

    // Overload "!=" operator
    bool operator!=(const Date& other) const;

    // Overload "<=" operator
    bool operator<=(const Date& other) const;

    // Overload ">=" operator
    bool operator>=(const Date& other) const;

    // Overload "<<" operator for output streams
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    // Overload ">>" operator for input streams
    friend std::istream& operator>>(std::istream& is, Date& date);
};

// Overload "<<" operator for output streams
std::ostream &operator<<(std::ostream &os, const Date &date);

// Overload ">>" operator for input streams
std::istream &operator>>(std::istream &is, Date &date);