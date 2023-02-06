#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>

using namespace std;

class User
{
    int userId;
    string login, password, userName, userSurname;

public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setUserName(string newName);
    void setUserSurname(string newSurname);

    int getId();
    string getLogin();
    string getPassword();
    string getUserName();
    string getUserSurname();

};

#endif
