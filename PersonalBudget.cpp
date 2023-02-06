#include "PersonalBudget.h"

bool PersonalBudget::isUserLoggedIn()
{
    return userMenager.isUserLoggedIn();
}

void PersonalBudget::userRegistration()
{
    userMenager.userRegistration();
}
