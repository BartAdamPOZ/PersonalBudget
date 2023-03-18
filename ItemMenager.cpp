#include "ItemMenager.h"

void ItemMenager::addIncome()
{
    Item income = provideIncomeDetails();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income added to file" << endl << endl;
    system("pause");

}

int ItemMenager::checkNewIncomeId()
{
    if (incomes.empty())
        return 1;
    else
        return incomes.back().getItemId() + 1;
}

Item ItemMenager::provideIncomeDetails()
{
    Item item;

    string itemName, otherDate, currentStringDate, stringAmount;
    float amount;
    char choice;

    int itemId = checkNewIncomeId();
    item.setItemId(itemId);
    item.setUserId(ID_LOGGED_USER);

    cout << "Do you want to add income with current date?" << endl;
    cout << "If yes, please click 'y'. If you awnt to chose other date, please click 'n': " << endl;
    choice = SupportingMethods::getCharacter();

    if (choice == 'y')
    {
        int currentDate = dateMenager.getCurrentDate();
        currentStringDate = SupportingMethods::convertIntToString(currentDate);
        currentStringDate = SupportingMethods::addDashToDate(currentStringDate);
        item.setStringDate(currentStringDate);
    }
    else if (choice == 'n')
    {
        do{
            cout << "Provide past date in format YYYY-MM-DD: ";
            otherDate = SupportingMethods::loadLine();

            if (!dateMenager.isDateCorrect(otherDate) || !dateMenager.isDateExist(otherDate))
            cout << "Provided date is wrong. Try again! " << endl;
        } while (!dateMenager.isDateCorrect(otherDate) || !dateMenager.isDateExist(otherDate));

        SupportingMethods::removeDashFromDate(otherDate);
        item.setStringDate(otherDate);
    }
    cout << "Provide item desciption: ";
    itemName = SupportingMethods::loadLine();
    item.setItemName(itemName);

    cout << "Provide amount [PLN] : ";
    stringAmount = SupportingMethods::loadLine();
    stringAmount = SupportingMethods::changeComaToDot(stringAmount);
    while (!isFloat(stringAmount))
    {
        cout << "Wrong value! Try again." << endl;
        cout << "Provide amount [PLN] : ";
        stringAmount = SupportingMethods::loadLine();
        stringAmount = SupportingMethods::changeComaToDot(stringAmount);
    }

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

int ItemMenager::checkNewExpenseId()
{
    if (expenses.empty())
        return 1;
    else
        return expenses.back().getItemId() + 1;
}

Item ItemMenager::provideExpenseDetails()
{
    Item item;

    string itemName, otherDate, currentStringDate, stringAmount;
    float amount;
    char choice;

    int itemId = checkNewExpenseId();
    item.setItemId(itemId);
    item.setUserId(ID_LOGGED_USER);

    cout << "Do you want to add expense with current date?" << endl;
    cout << "If yes, please click 'y'. If you awnt to chose other date, please click 'n': " << endl;
    choice = SupportingMethods::getCharacter();

    if (choice == 'y')
    {
        int currentDate = dateMenager.getCurrentDate();
        currentStringDate = SupportingMethods::convertIntToString(currentDate);
        currentStringDate = SupportingMethods::addDashToDate(currentStringDate);
        item.setStringDate(currentStringDate);

    }
    else if (choice == 'n')
    {
        do{
            cout << "Provide past date in format YYYY-MM-DD: ";
            otherDate = SupportingMethods::loadLine();

            if (!dateMenager.isDateCorrect(otherDate) || !dateMenager.isDateExist(otherDate))
            cout << "Provided date is wrong. Try again! " << endl;
        } while (!dateMenager.isDateCorrect(otherDate) || !dateMenager.isDateExist(otherDate));
        SupportingMethods::removeDashFromDate(otherDate);
        item.setStringDate(otherDate);
    }
    cout << "Provide item desciption: ";
    itemName = SupportingMethods::loadLine();
    item.setItemName(itemName);

    cout << "Provide amount [PLN] : ";
    stringAmount = SupportingMethods::loadLine();
    stringAmount = SupportingMethods::changeComaToDot(stringAmount);
    while (!isFloat(stringAmount))
    {
        cout << "Wrong value! Try again." << endl;
        cout << "Provide amount [PLN] : ";
        stringAmount = SupportingMethods::loadLine();
        stringAmount = SupportingMethods::changeComaToDot(stringAmount);
    }

    amount = stof(stringAmount);

    item.setItemAmount(amount);

    return item;
}

void ItemMenager::displayBalanceForCurrentMonth()
{
    showBalance(dateMenager.getCurrentDate() - dateMenager.getCurrentDay() + 1, dateMenager.getCurrentDate());
}

void ItemMenager::displayBalanceForPreviousMonth()
{
    showBalance(dateMenager.getPreviousMonthStartDate(), dateMenager.getPreviousMonthEndDate());
}

void ItemMenager::displayBalanceForSelectedPeriod()
{
    string boarderDateStartString;
    int boarderDateStart = 0;
    string boarderDateEndString;
    int boarderDateEnd = 0;

    cout << "Provide start period date in format YYYY-MM-DD : ";
    boarderDateStartString = SupportingMethods::loadLine();
    while (!dateMenager.isDateCorrect(boarderDateStartString) || !dateMenager.isDateExist(boarderDateStartString))
    {
        cout << "Provided date is wrong. Try again! " << endl;
        cout << "Provide start period date in format YYYY-MM-DD : ";
    boarderDateStartString = SupportingMethods::loadLine();
    }

    boarderDateStart = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(boarderDateStartString));

    cout << "Provide start period date in format YYYY-MM-DD : ";
    boarderDateEndString = SupportingMethods::loadLine();
    while (!dateMenager.isDateCorrect(boarderDateEndString) || !dateMenager.isDateExist(boarderDateEndString))
    {
        cout << "Provided date is wrong. Try again! " << endl;
        cout << "Provide start period date in format YYYY-MM-DD : ";
    boarderDateEndString = SupportingMethods::loadLine();
    }

    boarderDateEnd = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(boarderDateEndString));

    showBalance(boarderDateStart, boarderDateEnd);
}

bool ItemMenager::isFloat(string s)
{
    try
    {
        stof(s);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

void ItemMenager::showBalance(int startDate, int endDate)
{
    Item income;
    Item expense;
    vector <Item> incomesToSort;
    vector <Item> expensesToSort;

    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    struct sortByIntDate
    {
        inline bool operator() (Item& struct1, Item& struct2)
        {
            return(struct1.getItemDate() < struct2.getItemDate());
        }
    };

    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        int intDate = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(incomes[i].getItemDate()));

        if (intDate >= startDate && intDate <= endDate)
        {
            income.setStringDate(incomes[i].getItemDate());
            income.setUserId(incomes[i].getUserId());
            income.setItemId(incomes[i].getItemId());
            income.setItemName(incomes[i].getItemName());
            income.setItemAmount(incomes[i].getItemAmount());

            incomesToSort.push_back(income);
        }
    }

    sort(incomesToSort.begin( ), incomesToSort.end( ), sortByIntDate());

    cout << endl << "          <<< INCOMES >>> " << endl << endl;

    for (unsigned int i = 0; i < incomesToSort.size(); i++)
    {
        cout << "DATE : " << incomesToSort[i].getItemDate() << endl;
        cout << "NAME : " << incomesToSort[i].getItemName() << endl;
        cout << "AMOUNT : " << fixed << setprecision(2) << incomesToSort[i].getItemAmount() << endl << endl;
        sumOfIncomes += incomesToSort[i].getItemAmount();
    }

    cout << "SUM OF INCOMES : " << fixed << setprecision(2) << sumOfIncomes << " [PLN]" << endl << endl;


    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        int intDate = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(expenses[i].getItemDate()));

        if (intDate >= startDate && intDate <= endDate)
        {
            expense.setStringDate(expenses[i].getItemDate());
            expense.setUserId(expenses[i].getUserId());
            expense.setItemId(expenses[i].getItemId());
            expense.setItemName(expenses[i].getItemName());
            expense.setItemAmount(expenses[i].getItemAmount());

            expensesToSort.push_back(expense);
        }
    }

    sort(expensesToSort.begin( ), expensesToSort.end( ), sortByIntDate());

    cout << endl << "          <<< EXPENSES >>> " << endl << endl;

    for (unsigned int i = 0; i < expensesToSort.size(); i++)
    {
        cout << "DATE : " << expensesToSort[i].getItemDate() << endl;
        cout << "NAME : " << expensesToSort[i].getItemName() << endl;
        cout << "AMOUNT : " << fixed << setprecision(2) << expensesToSort[i].getItemAmount() << endl << endl;
        sumOfExpenses += expensesToSort[i].getItemAmount();
    }

    cout << "SUM OF EXPENSES : " << fixed << setprecision(2) << sumOfExpenses << " [PLN]" << endl << endl;

    if (sumOfIncomes >= sumOfExpenses)
        cout << "You generate : " << fixed << setprecision(2) << sumOfIncomes - sumOfExpenses << " [PLN] savings from: " << SupportingMethods::addDashToDate(SupportingMethods::convertIntToString(startDate)) << " to: " << SupportingMethods::addDashToDate(SupportingMethods::convertIntToString(endDate)) << endl;
    else
        cout << "You generate : " << fixed << setprecision(2) << sumOfExpenses - sumOfIncomes << " [PLN] debt from: " << SupportingMethods::addDashToDate(SupportingMethods::convertIntToString(startDate)) << " to: " << SupportingMethods::addDashToDate(SupportingMethods::convertIntToString(endDate)) << endl;
    incomesToSort.clear();
    expensesToSort.clear();
    system("pause");
}

