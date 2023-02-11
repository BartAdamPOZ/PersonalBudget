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
    int logInUserId;
    vector <User> users;

    User provideDataOfNewUser();
    int getNewUserId();
    FileWithUsers fileWithUsers;
    bool isLoginExist(string login);

public:
    UserMenager(string nameFileWithUsers) : fileWithUsers(nameFileWithUsers)
    {
        logInUserId = 0;
        users = fileWithUsers.loadUserFromFile();
    };

    bool isUserLoggedIn();
    void userRegistration();
    void userLogIn();
    int logOut();
};


#endif
