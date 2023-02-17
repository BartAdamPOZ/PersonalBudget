#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "XMLFile.h"
#include "Item.h"
#include "SupportingMethods.h"
#include "Markup.h"

using namespace std;

class ExpenseFile : public XMLFile
{
    int lastItemId;
    int logInUserId;
    vector <Item> expenses;

public:
    ExpenseFile(string nameFileWithExpenses) : XMLFile(nameFileWithExpenses)
    {
        lastItemId = 0;
    };

    void addExpenseToFile (Item expense);
    vector <Item> getExpensesFromFile(int logInUserId);
};







#endif
