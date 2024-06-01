#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
#include "../../MyLib/clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:

    // Method to print client information
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    // Method to read account number from user input
    static string _ReadAccountNumber(string Str)
    {
        string AccountNumber;
        cout << Str;
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    // Method to read transfer amount from user input, ensuring it's within the source client's balance
    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;
        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:

    // Method to display the transfer screen and handle transfer operations
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");
        
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter AccountNumber To Transfer From: "));

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter AccountNumber To Transfer To: "));

        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);
        
        cout << "\nAre you sure you want to perform this transaction? y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }

};