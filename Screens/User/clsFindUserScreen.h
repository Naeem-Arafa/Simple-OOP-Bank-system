#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsPerson.h"
#include "../../Core/clsUser.h"
#include "../../MyLib/clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
{
private:

    // Method to print the details of a user
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

public:

    // Method to display the find user screen and find a user in the system
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
            cout << "\nUser Found :-)\n";
        else
            cout << "\nUser Was not Found :-(\n";

        _PrintUser(User1);
    }

};
