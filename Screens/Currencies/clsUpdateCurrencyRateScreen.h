#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"
#include "../../MyLib/clsInputValidate.h"

class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:

    // Method to read and return the new currency rate
    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    // Method to print the details of a currency
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

public:

    // Method to display the update currency rate screen and update the rate of a currency
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
        }
    }
};
