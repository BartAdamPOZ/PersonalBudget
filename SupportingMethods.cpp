#include "SupportingMethods.h"

char SupportingMethods::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Logging" << endl;
    cout << "9. Close" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = getCharacter();

    return choice;
}

char SupportingMethods::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "---------------------------" << endl;
    cout << "3. Display balance from current month" << endl;
    cout << "4. Display balance from previous month" << endl;
    cout << "5. Display balance from selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = getCharacter();

    return choice;
}

string SupportingMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char SupportingMethods::getCharacter()
{
    string providedCharacter = "";
    char character  = {0};

    while (true)
    {
        getline(cin, providedCharacter);

        if (providedCharacter.length() == 1)
        {
            character = providedCharacter[0];
            break;
        }
        cout << "This is not one character. Please enter one more time." << endl;
    }
    return character;
}
