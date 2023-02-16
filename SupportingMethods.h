#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class SupportingMethods
{
    public:
        static char chooseOptionFromMainMenu();
        static char chooseOptionFromUserMenu();
        static string loadLine();
        static char getCharacter();
        static float loadFloat();
        static string addDashToDate(string date);
        static string convertIntToString(int number);
        static string removeDashFromDate(string date);
        static int convertStringToInt(string number);
        static string switchFirstLetterToBiggerOthersToSmaller (string text);
        static string convertFloatToString (float amount);

};

#endif
