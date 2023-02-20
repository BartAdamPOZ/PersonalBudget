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
            cout << "Provide past date in format YYYY-MM-DD: ";
            otherDate = SupportingMethods::loadLine();
        } while (dateMenager.isDateCorrect(otherDate) == false || dateMenager.isDateExist(otherDate) == false);
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
    stringAmount = SupportingMethods::loadLine();
    stringAmount = SupportingMethods::changeComaToDot(stringAmount);
    amount = stof(stringAmount);
    item.setItemAmount(amount);

    return item;
}

void ItemMenager::addExpense()
{
    Item expense = provideExpenseDetails();
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);
    cout << endl << "Expense added to file" << endl << endl;
    system("pause");

}

int ItemMenager::getNewExpenseId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getItemId() + 1;
}

Item ItemMenager::provideExpenseDetails()
{
    Item item;

    string itemName, otherDate, stringDateWithoutDash, currentStringDate, stringAmount;
    int currentDate, intDateWithoutDash;
    float amount;
    char choice;

    int itemId = getNewExpenseId();
    item.setItemId(itemId);
    item.setUserId(ID_LOGGED_USER);

    cout << "Do you want to add expense with current date?" << endl;
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
            cout << "Provide past date in format YYYY-MM-DD: ";
            otherDate = SupportingMethods::loadLine();
        } while (dateMenager.isDateCorrect(otherDate) == false || dateMenager.isDateExist(otherDate) == false);
        stringDateWithoutDash = SupportingMethods::removeDashFromDate(otherDate);
        intDateWithoutDash = SupportingMethods::convertStringToInt(stringDateWithoutDash);
        item.setStringDate(otherDate);
    }
    cout << "Provide item desciption: ";
    itemName = SupportingMethods::loadLine();
    item.setItemName(itemName);
    cout << "Provide amount: ";
    stringAmount = SupportingMethods::loadLine();
    stringAmount = SupportingMethods::changeComaToDot(stringAmount);
    amount = stof(stringAmount);

    item.setItemAmount(amount);

    return item;
}

void ItemMenager::displayBalanceForCurrentMonth()
{
    Item income;
    Item expense;
    vector <Item> incomesToSort;
    vector <Item> expensesToSort;

    int boarderDatePast = dateMenager.getCurrentDate() - dateMenager.getCurrentDay(); // wyswietla 20230200

    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        int intDate = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(incomes[i].getItemDate()));

        if (intDate > boarderDatePast)
        {
            income.setStringDate(incomes[i].getItemDate());
            income.setUserId(incomes[i].getUserId());
            income.setItemId(incomes[i].getItemId());
            income.setItemName(incomes[i].getItemName());
            income.setItemAmount(incomes[i].getItemAmount());

            incomesToSort.push_back(income);
        }
    }
    sort(incomesToSort.begin( ), incomesToSort.end( ), [ ]( const auto& lhs, const auto& rhs )
{
   return lhs.getIntDate() < rhs.getIntDate();
});

}

/*bool ItemMenager::sortByIntDate (Item &a,Item &b)
{
    return a.getIntDate() < b.getIntDate();
}*/
