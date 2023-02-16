#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Item income)
{
    string amount = SupportingMethods::convertFloatToString(income.getItemAmount());
    CMarkup xml;
    string nameFileWithIncomes = XMLFile::getFileName();
    bool fileExist = xml.Load(nameFileWithIncomes);

    if (!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getItemId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getItemDate()); // nalezy przesledzic jak tutaj zostaje zapisana data
    xml.AddElem("Item", income.getItemName());
    xml.AddElem("Amount", amount);

    xml.Save(nameFileWithIncomes);
}

vector <Item> IncomeFile::getIncomesFromFile(int logInUserId)
{
    Item item;
    vector <Item> incomes;
    CMarkup xml;
    string nameFileWithIncomes = XMLFile::getFileName();
    bool fileExist = xml.Load(nameFileWithIncomes);

    if (fileExist)
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income") == true)
        {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            int incomeId = atoi(xml.GetData().c_str());
            item.setItemId(incomeId);
            xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());
            item.setUserId(userId);
            xml.FindElem("Date");
            string itemDate = xml.GetData();
            item.setStringDate(itemDate);
            xml.FindElem("Item");
            string itemName = xml.GetData();
            item.setItemName(itemName);
            xml.FindElem("Amount");
            float itemAmount = atoi(xml.GetData().c_str());
            item.setItemAmount(itemAmount);

            if (userId == logInUserId)
            {
                incomes.push_back(item);
                cout << "Dodano przychod, a jego id to: " << incomeId << endl;
                Sleep (2000);
            }

            xml.OutOfElem();
        }
    }
    return incomes;
}
