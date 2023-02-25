#include "PersonalBudget.h"

bool PersonalBudget::isUserLoggedIn()
{
    return userMenager.isUserLoggedIn();
}

void PersonalBudget::userRegistration()
{
    userMenager.userRegistration();
}

void PersonalBudget::userLogIn()
{
    userMenager.userLogIn();
    if (userMenager.isUserLoggedIn())
    {
        itemMenager = new ItemMenager(NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES, userMenager.getLoggedUserId());
    }
}

void PersonalBudget::logOut()
{
    userMenager.logOut();
    delete itemMenager;
    itemMenager = NULL;
}

void PersonalBudget::changePasswordLogInUser()
{
    userMenager.changePasswordLogInUser();
}

void PersonalBudget::addIncome()
{
    itemMenager->addIncome();
}

void PersonalBudget::addExpense()
{
    itemMenager->addExpense();
}

void PersonalBudget::displayBalanceForCurrentMonth()
{
    itemMenager->displayBalanceForCurrentMonth();
}

void PersonalBudget::displayBalanceForPreviousMonth()
{
    itemMenager->displayBalanceForPreviousMonth();
}

void PersonalBudget::displayBalanceForSelectedPeriod()
{
    itemMenager->displayBalanceForSelectedPeriod();
}
