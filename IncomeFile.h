#ifndef INCOMEFILE_H
#define INCOMEFILE_H

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

class IncomeFile : public XMLFile
{
    int lastItemId;
    int logInUserId;
    vector <Item> incomes;

public:
    IncomeFile(string nameFileWithIncomes) : XMLFile(nameFileWithIncomes)
    {
        lastItemId = 0;
    };

    void addIncomeToFile (Item income);
    vector <Item> getIncomesFromFile(int logInUserId);

};







#endif
