#include "Item.h"

void Item::setStringDate(string newStringDate)
{
    itemDate = newStringDate;
}

void Item::setUserId(int newUserId)
{
    userId = newUserId;
}

void Item::setItemId(int newItemId)
{
    itemId = newItemId;
}

void Item::setItemName(string newItemName)
{
    itemName = newItemName;
}

void Item::setItemAmount(float newItemAmount)
{
    itemAmount = newItemAmount;
}

void Item::setIntDate(int newIntDate)
{
    if (newIntDate >= 0)
        intDate = newIntDate;
}

int Item::getItemId()
{
    return itemId;
}

int Item::getUserId()
{
    return userId;
}

string Item::getItemName()
{
    return itemName;
}

float Item::getItemAmount()
{
    return itemAmount;
}

string Item::getItemDate()
{
    return itemDate;
}

int Item::getIntDate()
{
    return intDate;
}
