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
}

void PersonalBudget::logOut()
{
    userMenager.logOut();
}

void PersonalBudget::changePasswordLogInUser()
{
    userMenager.changePasswordLogInUser();
}
