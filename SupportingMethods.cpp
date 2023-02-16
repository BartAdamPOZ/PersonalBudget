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

float SupportingMethods::loadFloat()
{
    string providedData = "";
    float number;

    while (true)
    {
        cin.clear();
        getline(cin, providedData);

        stringstream myStream(providedData);
        if (myStream >> number)
            break;
        cout << "This is not the amount. Please add again. " << endl;
    }
    return number;
}

string SupportingMethods::addDashToDate(string date)
{
    string stringDateWithDash;
    stringDateWithDash = date.insert(4,1,'-');
    stringDateWithDash = stringDateWithDash.insert(7,1,'-');

    return stringDateWithDash;
}

string SupportingMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

string SupportingMethods::removeDashFromDate(string date)
{
    string stringDateWithoutDash;

    for (unsigned int i = 0; i < date.length(); i++)
    {
        if (date[i] != '-')
        {
            stringDateWithoutDash += date[i];
        }
    }
    return stringDateWithoutDash;
}

int SupportingMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string SupportingMethods::switchFirstLetterToBiggerOthersToSmaller(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string SupportingMethods::convertFloatToString(float amount)
{
    stringstream FloatToStr;
    string str;

    FloatToStr << amount;
    FloatToStr >> str;
    FloatToStr.clear();

    return str;
}
