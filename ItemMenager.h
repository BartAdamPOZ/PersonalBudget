#ifndef ITEMMENAGER_H
#define ITEMMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "IncomeFile.h"
#include "SupportingMethods.h"
//#include "Item.h"
#include "DateMenager.h"

using namespace std;

class ItemMenager : public Item
{
    IncomeFile incomeFile;
    DateMenager dateMenager;
    const int ID_LOGGED_USER;
    vector <Item> incomes;

    Item provideIncomeDetails();
    int getNewIncomeId();

public:

    ItemMenager(string nameFileWithIncomes, int logInUserId) : incomeFile(nameFileWithIncomes), ID_LOGGED_USER(logInUserId)
    {
        incomes = incomeFile.getIncomesFromFile(ID_LOGGED_USER);
    }

    void addIncome();

};







#endif
