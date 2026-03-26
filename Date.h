#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getYear() const { return year; }

    void display() const { //ouputs the date
        cout << month << "/" << day << "/" << year;
    }

    bool operator<(const Date& other) const {
        return isOlderThan(other);
    }

    bool operator>(const Date& other) const {
        return isNewerThan(other);
    }

    bool isNewerThan(const Date& other) const { //checks if this date is newer than another. use with the database to determine the newest driver
        if (year != other.year) {
            return year > other.year;
        }
        if (month != other.month) {
            return month > other.month;
        }
        return day > other.day;
    }

    bool isOlderThan(const Date& other) const { //checks if this date is older than another. use with the database to determine the oldest driver
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

#endif
