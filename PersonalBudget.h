#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "UserMenager.h"
#include "ItemMenager.h"

using namespace std;

class PersonalBudget
{
    UserMenager userMenager;
    ItemMenager *itemMenager;
    const string NAME_FILE_WITH_INCOMES;

public:
    PersonalBudget(string nameFileWithUsers, string nameFileWithIncomes)
    : userMenager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes)
    {
        itemMenager = NULL;
    };
    ~PersonalBudget()
    {
        delete itemMenager;

        itemMenager = NULL;
    }

    bool isUserLoggedIn();
    void userRegistration();
    void userLogIn();
    void logOut();
    void changePasswordLogInUser();
    void addIncome();

};


#endif
