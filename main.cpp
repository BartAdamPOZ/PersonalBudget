#include <iostream>

#include "PersonalBudget.h"
#include "SupportingMethods.h"


using namespace std;

int main()
{
    char choice;

    PersonalBudget personalBudget;


    while (true)
    {
        if (!personalBudget.isUserLoggedIn())
        {
            choice = SupportingMethods::chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                //personalBudget.userRegistration();
                break;
            case '2':
                //personalBudget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Error. Please try again. " << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = SupportingMethods::chooseOptionFromUserMenu();

            switch(choice)
            {
            case '1':
                //personalBudget.addIncome();
                break;
            case '2':
                //personalBudget.addExpense();
                break;
            case '3':
                //personalBudget.displayBalanceForCurrentMonth();
                break;
            case '4':
                //personalBudget.displayBalanceForPreviousMonth();
                break;
            case '5':
                //personalBudget.displayBalanceForSelectedPeriod();
                break;
            case '6':
                //personalBudget.changePasswordLogInUser();
                break;
            case '7':
                //personalBudget.logOut();
                break;
            }
        }
    }

    return 0;
}
