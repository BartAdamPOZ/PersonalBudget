#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item
{
    int itemId, userId, intDate;
    string itemDate, itemName;
    float itemAmount;

public:
    Item(int itemId = 0, int userId = 0, string itemDate = "", string itemName = "", float itemAmount = 0.0)
    {
        this->itemId = itemId;
        this->userId = userId;
        this->itemDate = itemDate;
        this->itemName = itemName;
        this->itemAmount = itemAmount;
    };

    /*void setDate(int newDate);*/
    void setStringDate(string newStringDate);
    void setUserId(int newUserId);
    void setItemId(int newItemId);
    void setItemName(string newItemName);
    void setItemAmount(float newItemAmount);

    int getItemId();
    int getUserId();
    string getItemName();
    float getItemAmount();
    string getItemDate();
    int getIntDate();



};

#endif
