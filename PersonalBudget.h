#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "UserMenager.h"

using namespace std;

class PersonalBudget
{
    UserMenager userMenager;
public:
    PersonalBudget(string nameFileWithUsers) : userMenager(nameFileWithUsers){};

    bool isUserLoggedIn();
    void userRegistration();
    void userLogIn();

};


#endif
