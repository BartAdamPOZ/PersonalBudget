#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"
#include "SupportingMethods.h"

using namespace std;

class UserMenager
{
    int logInUserId = 0;
    vector <User> users;

    User provideDataOfNewUser();
    int getNewUserId();
    FileWithUsers fileWithUsers;
    bool isLoginExist(string login);

public:
    UserMenager(string nameFileWithUsers) : fileWithUsers(nameFileWithUsers) {};

    bool isUserLoggedIn();
    void userRegistration();
};


#endif
