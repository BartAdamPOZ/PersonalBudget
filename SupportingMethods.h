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
};

#endif
