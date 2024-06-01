#pragma once
#include <iostream>
#include "Global.h"
#include "../MyLib/clsDate.h"
using namespace std;

class clsScreen
{
protected:

    // Method to draw the header of a screen with title and optional subtitle
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate::GetSystemDate()) << "\n\n";
    }

    // Method to check if the current user has access rights for a specific permission
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
            return true;
    }

   
};