#ifndef ITEMMENAGER_H
#define ITEMMENAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "SupportingMethods.h"
#include "DateMenager.h"

using namespace std;

class ItemMenager : public Item
{
    IncomeFile incomeFile;
    ExpenseFile expenseFile;
    DateMenager dateMenager;
    const int ID_LOGGED_USER;
    vector <Item> incomes;
    vector <Item> expenses;

    Item provideDetails(int newItemId, string incomeOrExpense);
    int checkNewIncomeId();
    int checkNewExpenseId();
    bool isFloat(string s);

public:

    ItemMenager(string nameFileWithIncomes,string nameFileWithExpenses, int logInUserId) : incomeFile(nameFileWithIncomes), expenseFile(nameFileWithExpenses), ID_LOGGED_USER(logInUserId)
    {
        incomes = incomeFile.getIncomesFromFile(ID_LOGGED_USER);
        expenses = expenseFile.getExpensesFromFile(ID_LOGGED_USER);
    }

    void addIncome();
    void addExpense();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForSelectedPeriod();
    void showBalance(int startDate, int endDate);
};







#endif
