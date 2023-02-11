#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <windows.h>

#include "Markup.h"
#include "XMLFile.h"
#include "User.h"


using namespace std;

class FileWithUsers : public XMLFile
{
    string nameFileWithUsers;

public:
    FileWithUsers(string nameFileWithUsers) : XMLFile(nameFileWithUsers){};
    void addUserToFile(User user);
    vector <User> loadUserFromFile();
    void changePasswordInFile(User user);

};







#endif
