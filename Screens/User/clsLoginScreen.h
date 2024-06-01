#pragma once
#include <iostream>
#include "Core/clsUser.h"
#include <iomanip>
#include "../clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{
private:

    // Method to handle the login process
    static bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                FaildLoginCount++;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "\nYou have " << (3 - FaildLoginCount) << " Trial(s) to login.\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\nYour are Locked after 3 faild trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    // Method to display the login screen and initiate the login process
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};
