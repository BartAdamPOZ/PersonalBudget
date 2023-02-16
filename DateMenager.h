#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <windows.h>

#include "Date.h"

using namespace std;

class DateMenager
{
    time_t calculatedTime;
    struct tm * data;
    int year, month, day;

    const int MIN_VALID_YEAR = 2000;

    bool isLeap(int year);

public:
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();

    bool isDateCorrect(string date);
    bool isValidYear(int year);
    bool isValidMonth(int month);
    bool isValidDay(int dayConverted, int monthConverted, int yearConverted);
    bool isValidFormatDate(string date);

    //void showDate(Date dateOb);

};


#endif
