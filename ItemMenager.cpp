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

    string itemName, otherDate, currentStringDate, stringAmount;
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
        } while (dateMenager.isDateCorrect(otherDate) == false || dateMenager.isDateExist(otherDate) == false);
        SupportingMethods::removeDashFromDate(otherDate);
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

    string itemName, otherDate, currentStringDate, stringAmount;
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
        } while (dateMenager.isDateCorrect(otherDate) == false || dateMenager.isDateExist(otherDate) == false);
        SupportingMethods::removeDashFromDate(otherDate);
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

    float sumOfIncomes = 0;
    float sumOfExpenses = 0;
    int boarderDateStart = dateMenager.getCurrentDate() - dateMenager.getCurrentDay();

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

        if (intDate > boarderDateStart)
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
        cout << "AMOUNT : " << incomesToSort[i].getItemAmount() << endl << endl;
        sumOfIncomes += incomesToSort[i].getItemAmount();
    }
    cout << "SUM OF INCOMES : " << sumOfIncomes << "[PLN]" << endl << endl;


    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        int intDate = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(expenses[i].getItemDate()));

        if (intDate > boarderDateStart)
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
        cout << "AMOUNT : " << expensesToSort[i].getItemAmount() << endl << endl;
        sumOfExpenses += expensesToSort[i].getItemAmount();
    }
    cout << "SUM OF EXPENSES : " << sumOfExpenses << "[PLN]" << endl << endl;

    if (sumOfIncomes >= sumOfExpenses)
        cout << "You generate : " << sumOfIncomes - sumOfExpenses << " [PLN] savings this month." << endl;
    else
        cout << "You generate : " << sumOfExpenses - sumOfIncomes << " [PLN] debt this month." << endl;

    incomesToSort.clear();
    expensesToSort.clear();
    system("pause");
}

void ItemMenager::displayBalanceForPreviousMonth()
{
    Item income;
    Item expense;
    vector <Item> incomesToSort;
    vector <Item> expensesToSort;

    float sumOfIncomes = 0;
    float sumOfExpenses = 0;
    int boarderDateStart = 0;
    int boarderDateEnd = 0;

    struct sortByIntDate
    {
        inline bool operator() (Item& struct1, Item& struct2)
        {
            return(struct1.getItemDate() < struct2.getItemDate());
        }
    };

    if ((dateMenager.getCurrentMonth() - 1) == 0)
        boarderDateStart += (dateMenager.getCurrentYear() - 1)*1000 + (12*100);
    else
        boarderDateStart += (dateMenager.getCurrentYear() * 10000) + ((dateMenager.getCurrentMonth() - 1)*100);

    boarderDateEnd = dateMenager.getCurrentDate() - dateMenager.getCurrentDay();

     for (unsigned int i = 0; i < incomes.size(); i++)
    {
        int intDate = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(incomes[i].getItemDate()));

        if (intDate > boarderDateStart && intDate < boarderDateEnd)
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
        cout << "AMOUNT : " << incomesToSort[i].getItemAmount() << endl << endl;
        sumOfIncomes += incomesToSort[i].getItemAmount();
    }
    cout << "SUM OF INCOMES : " << sumOfIncomes << "[PLN]" << endl << endl;

    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        int intDate = SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(expenses[i].getItemDate()));

        if (intDate > boarderDateStart && intDate < boarderDateEnd)
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
        cout << "AMOUNT : " << expensesToSort[i].getItemAmount() << endl << endl;
        sumOfExpenses += expensesToSort[i].getItemAmount();
    }
    cout << "SUM OF EXPENSES : " << sumOfExpenses << "[PLN]" << endl << endl;

    if (sumOfIncomes >= sumOfExpenses)
        cout << "You generate : " << sumOfIncomes - sumOfExpenses << " [PLN] savings last month." << endl;
    else
        cout << "You generate : " << sumOfExpenses - sumOfIncomes << " [PLN] debt last month." << endl;

    incomesToSort.clear();
    expensesToSort.clear();
    system("pause");

}
