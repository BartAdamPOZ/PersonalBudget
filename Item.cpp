#include "Item.h"

void Item::setDate(int newDate)
{
    if (newDate >= 0)
        itemDate = newDate;
}

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

int Item::getIntDate()
{
    return intDate;
}
