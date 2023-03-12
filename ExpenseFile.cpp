#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile(Item expense)
{
    string amount = SupportingMethods::convertFloatToString(expense.getItemAmount());
    CMarkup xml;
    string nameFileWithExpenses = XMLFile::getFileName();
    bool fileExist = xml.Load(nameFileWithExpenses);

    if (!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getItemId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getItemDate());
    xml.AddElem("Item", expense.getItemName());
    xml.AddElem("Amount", amount);

    xml.Save(nameFileWithExpenses);
}

vector <Item> ExpenseFile::getExpensesFromFile(int logInUserId)
{
    Item item;
    vector <Item> expenses;
    CMarkup xml;
    string nameFileWithExpenses = XMLFile::getFileName();
    bool fileExist = xml.Load(nameFileWithExpenses);

    if (fileExist)
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense") == true)
        {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            int expenseId = atoi(xml.GetData().c_str());
            item.setItemId(expenseId);
            xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());
            item.setUserId(userId);
            xml.FindElem("Date");
            string itemDate = xml.GetData();
            item.setStringDate(itemDate);
            item.setIntDate(SupportingMethods::convertStringToInt(SupportingMethods::removeDashFromDate(itemDate)));
            xml.FindElem("Item");
            string itemName = xml.GetData();
            item.setItemName(itemName);
            xml.FindElem("Amount");
            float itemAmount = atof(xml.GetData().c_str());
            item.setItemAmount(itemAmount);

            if (userId == logInUserId)
                expenses.push_back(item);


            xml.OutOfElem();
        }
    }
    return expenses;
}
