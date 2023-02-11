#include "FileWithUsers.h"
#include "Markup.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    string nameFileWithUsers = XMLFile::getFileName();
    bool fileExists = xml.Load(nameFileWithUsers);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getUserName());
    xml.AddElem("Surname", user.getUserSurname());

    xml.Save(nameFileWithUsers);

}

vector <User> FileWithUsers::loadUserFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;
    string nameFileWithUsers = XMLFile::getFileName();
    bool fileExists = xml.Load(nameFileWithUsers);

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User") == true)
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());
            user.setId(userId);
            xml.FindElem("Login");
            string login = xml.GetData();
            user.setLogin(login);
            xml.FindElem("Password");
            string password = xml.GetData();
            user.setPassword(password);
            xml.FindElem("Name");
            string userName = xml.GetData();
            user.setUserName(userName);
            xml.FindElem("Surname");
            string userSurname = xml.GetData();
            user.setUserSurname(userSurname);

            users.push_back(user);

            xml.OutOfElem();
        }

    }
    return users;
}

void FileWithUsers::changePasswordInFile(User user)
{
    CMarkup xml;
    string nameFileWithUsers = XMLFile::getFileName();
    bool fileExists = xml.Load(nameFileWithUsers);

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User") == true)
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());
            if (userId == user.getId())
            {
                xml.FindElem("Password");
                xml.SetData(user.getPassword());
                xml.Save(nameFileWithUsers);
            }
            xml.OutOfElem();
        }
    }
}
