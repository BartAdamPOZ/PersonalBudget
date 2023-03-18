#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

#include "Date.h"
#include "SupportingMethods.h"

using namespace std;

class DateMenager
{
    time_t calculatedTime;
    struct tm * data;
    int year, month, day;

    bool isLeap(int year);

public:
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int getPreviousMonthStartDate();
    int getPreviousMonthEndDate();

    bool isDateCorrect(string date);
    bool isValidYear(int year);
    bool isValidMonth(int month);
    bool isValidDay(int dayConverted, int monthConverted, int yearConverted);
    bool isValidFormatDate(string date);
    bool isDateExist(string date);

};


#endif
