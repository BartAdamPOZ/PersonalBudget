#include "User.h"

void User::setId(int newId)
{
    if(newId >= 0)
        userId = newId;
}

void User::setLogin(string newLogin)
{
    login = newLogin;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

void User::setUserName(string newName)
{
    userName = newName;
}

void User::setUserSurname(string newSurname)
{
    userSurname = newSurname;
}

int User::getId()
{
    return userId;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}

string User::getUserName()
{
    return userName;
}

string User::getUserSurname()
{
    return userSurname;
}
