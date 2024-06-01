#pragma once
#include<iostream>
#include<string>
#include "../MyLib/clsString.h"
#include <vector>
#include <fstream>
class clsCurrency
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;
    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    // Converts a line of text into a clsCurrency object
    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
            stod(vCurrencyData[3]));
    }

    // Converts a clsCurrency object into a line of text
    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {
        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;
    }

    // Loads all currencies data from file into a vector
    static vector <clsCurrency> _LoadCurrencysDataFromFile()
    {
        vector <clsCurrency> vCurrencys;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                vCurrencys.push_back(Currency);
            }
            MyFile.close();
        }
        return vCurrencys;
    }

    // Saves all currencies data from a vector to a file
    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
    {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsCurrency C : vCurrencys)
            {
                DataLine = _ConverCurrencyObjectToLine(C);
                MyFile << DataLine << endl;
            }
            MyFile.close();
        }
    }

    // Updates the currency data in the file
    void _Update()
    {
        vector <clsCurrency> _vCurrencys;
        _vCurrencys = _LoadCurrencysDataFromFile();

        for (clsCurrency& C : _vCurrencys)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(_vCurrencys);
    }

    // Returns an empty currency object
    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:

    // Constructor for clsCurrency class
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    // Gets all currency rates with respect to USD
    static vector <clsCurrency> GetAllUSDRates()
    {
        return _LoadCurrencysDataFromFile();
    }

    // Checks if the currency object is empty
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    // Returns the country of the currency
    string Country()
    {
        return _Country;
    }

    // Returns the currency code
    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    // Returns the currency name
    string CurrencyName()
    {
        return _CurrencyName;
    }

    // Updates the rate of the currency and saves it to the file
    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    // Returns the rate of the currency
    float Rate()
    {
        return _Rate;
    }

    // Finds a currency by its code
    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    // Finds a currency by its country
    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    // Checks if a currency exists by its code
    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());
    }

    // Gets a list of all currencies
    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencysDataFromFile();
    }

    // Converts an amount to USD
    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / Rate());
    }

    // Converts an amount to another currency
    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }
        return (float)(AmountInUSD * Currency2.Rate());
    }

};


