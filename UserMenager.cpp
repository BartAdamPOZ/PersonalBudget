#include "UserMenager.h"

bool UserMenager::isUserLoggedIn()
{
    return logInUserId > 0;
}

void UserMenager::userRegistration()
{
    User user = provideDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account created." << endl << endl;
    system("pause");
}

User UserMenager::provideDataOfNewUser()
{
    User user;

    user.setId(getNewUserId());

    do
    {
        cout << "Set login: ";
        user.setLogin(SupportingMethods::loadLine());
    }
    while (isLoginExist(user.getLogin()) == true);

    cout << "Set password: ";
    user.setPassword(SupportingMethods::loadLine());

    cout << "Set Name: ";
    user.setUserName(SupportingMethods::loadLine());

    cout << "Set Surname: ";
    user.setUserSurname(SupportingMethods::loadLine());

    return user;
}

bool UserMenager::isLoginExist(string login)
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Sorry, this login already exist. Please, try again." << endl;
            return true;
        }
    }
    return false;
}

int UserMenager::getNewUserId()
{
     if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void UserMenager::userLogIn()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = SupportingMethods::loadLine();

    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfTrial = 3; numberOfTrial > 0; numberOfTrial--)
            {
                cout << "Enter password. You have " << numberOfTrial << " left: ";
                password = SupportingMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Logged in." << endl << endl;
                    system("pause");
                    logInUserId = users[i].getId();
                    return;
                }
            }
            cout << "You have provided 3 times incorrect password." << endl;
            system("pause");
            return;
        }
    }
    cout << endl << "Wrong login, try again. " << endl << endl;
    system("pause");
    return;

}

int UserMenager::logOut()
{
    return logInUserId = 0;
}
