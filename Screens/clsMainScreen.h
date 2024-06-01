#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../MyLib/clsInputValidate.h"
#include "Client/clsClientListScreen.h"
#include "Client/clsAddNewClientScreen.h"
#include "Client/clsDeleteClientScreen.h"
#include "Client/clsUpdateClientScreen.h"
#include "Client/clsFindClientScreen.h"
#include "Client/clsTransactionsScreen.h"
#include "User/clsManageUsersScreen.h"
#include "User/clsLoginRegisterScreen.h"
#include "Currencies/clsCurrencyExchangeScreen.h"
#include "Global.h"
#include <iomanip>

class clsMainScreen :protected clsScreen
{
private:

    // Enumeration of main menu options
    enum enMainMenueOptions 
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eListLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    // Method to read main menu option from user input
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    // Method to go back to the main menu after an action
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    // Methods to show different screens
    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowAllLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        //then it will go back to main function.
    }

    // Method to perform the selected main menu option
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eListLoginRegister:
        {
            system("cls");
            _ShowAllLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eCurrencyExchange:
        {
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }
    }

public:

    // Method to display the main menu
    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};
