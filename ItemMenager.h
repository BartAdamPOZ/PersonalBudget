#ifndef ITEMMENAGER_H
#define ITEMMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

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

    Item provideIncomeDetails();
    Item provideExpenseDetails();
    int getNewIncomeId();
    int getNewExpenseId();

public:

    ItemMenager(string nameFileWithIncomes,string nameFileWithExpenses, int logInUserId) : incomeFile(nameFileWithIncomes), expenseFile(nameFileWithExpenses), ID_LOGGED_USER(logInUserId)
    {
        incomes = incomeFile.getIncomesFromFile(ID_LOGGED_USER);
        expenses = expenseFile.getExpensesFromFile(ID_LOGGED_USER);
    }

    void addIncome();
    void addExpense();
    void displayBalanceForCurrentMonth();
};







#endif
