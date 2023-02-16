#include "ItemMenager.h"

void ItemMenager::addIncome()
{
    Item income = provideIncomeDetails();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income added to file" << endl << endl;
    system("pause");

}

int ItemMenager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getItemId() + 1;
}

Item ItemMenager::provideIncomeDetails()
{
    Item item;

    string itemName, otherDate, stringDateWithoutDash, currentStringDate, stringAmount;
    int currentDate, intDateWithoutDash;
    float amount;
    char choice;

    int itemId = getNewIncomeId();
    item.setItemId(itemId);
    item.setUserId(ID_LOGGED_USER);

    cout << "Do you want to add income with current date?" << endl;
    cout << "If yes, please click 'y'. If you awnt to chose other date, please click 'n': " << endl;
    choice = SupportingMethods::getCharacter();

    if (choice == 'y')
    {
        currentDate = dateMenager.getCurrentDate();
        currentStringDate = SupportingMethods::convertIntToString(currentDate);
        currentStringDate = SupportingMethods::addDashToDate(currentStringDate);
        item.setStringDate(currentStringDate);

    }
    else if (choice == 'n')
    {
        do{
            cout << "Provide date in format YYYY-MM-DD: ";
            otherDate = SupportingMethods::loadLine();
        } while (dateMenager.isDateCorrect(otherDate) == false);
        stringDateWithoutDash = SupportingMethods::removeDashFromDate(otherDate);
        intDateWithoutDash = SupportingMethods::convertStringToInt(stringDateWithoutDash);
        item.setStringDate(otherDate);
        cout << otherDate << endl;
        Sleep (3000);
    }
    cout << "Provide item desciption: ";
    itemName = SupportingMethods::loadLine();
    item.setItemName(itemName);
    cout << "Provide amount: ";
    amount = SupportingMethods::loadFloat();
    item.setItemAmount(amount);

    return item;
}
