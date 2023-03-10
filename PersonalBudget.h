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
    const string NAME_FILE_WITH_EXPENSES;

public:
    PersonalBudget(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses)
    : userMenager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses)
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
    void addExpense();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForSelectedPeriod();

};


#endif
