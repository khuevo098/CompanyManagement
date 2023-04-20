#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <assert.h>
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(/* args */);
    ~Date();
    friend std::istream& operator>> (std::istream& is, Date& src);
    friend std::ostream& operator<< (std::ostream& os, const Date& src);
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    int getYear() {
        return year;
    }
    bool checkdate();
    int days_in_month();
    int days_since_epoch();
    int days_between(Date& other);
    void randDate();
};

