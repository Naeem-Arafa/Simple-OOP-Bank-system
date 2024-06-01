#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "../MyLib/clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    // Converts a line of text into a clsBankClient object
    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    // Converts a clsBankClient object into a line of text
    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    // Loads all clients data from file into a vector
    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    // Saves all clients data from a vector to a file
    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    // Updates the client data in the file
    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
    }

    // Adds a new client to the file
    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    // Adds a line of client data to the file
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    // Returns an empty client object
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    struct stTrnsferLogRecord;

    // Converts a line of transfer log data into a stTrnsferLogRecord object
    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];
        return TrnsferLogRecord;
    }

    // Prepares a transfer log record in string format
    string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
        string UserName, string Seperator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }

    // Registers a transfer log in the TransferLog file
    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

public:
    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;
    };

    // Constructor for clsBankClient class
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    // Checks if the client object is empty
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    // Checks if the client is marked for deletion
    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    // Returns the account number of the client
    string AccountNumber()
    {
        return _AccountNumber;
    }

    // Sets the pin code of the client
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    // Gets the pin code of the client
    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    // Sets the account balance of the client
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    // Gets the account balance of the client
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    // Prints the client details
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }

    // Finds a client by account number 
    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    // Finds a client by account number and pin code
    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    // Saves the client data to the file
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResults::svFaildEmptyObject;
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            //this will add new record to file or database.
            if (clsBankClient::IsClientExist(_AccountNumber))
                return enSaveResults::svFaildAccountNumberExists;
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
        }
    }

    // Checks if a client exists by account number
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    // Returns a new client object for adding a new client
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    // Deletes a client
    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;
    }

    // Gets a list of all clients
    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    // Gets the total balance of all clients
    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {
            TotalBalances += Client.AccountBalance;
        }
        return TotalBalances;
    }

    // Deposits an amount into the client's account
    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    // Withdraws an amount from the client's account
    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
            return false;
        else
        {
            _AccountBalance -= Amount;
            Save();
        }   
    }

    // Transfers an amount from the client to a destination client
    bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }

    // Gets a list of all transfer logs
    static vector <stTrnsferLogRecord> GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vTransferLogRecord;
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {
                TransferRecord = _ConvertTransferLogLineToRecord(Line);
                vTransferLogRecord.push_back(TransferRecord);
            }
            MyFile.close();
        }
        return vTransferLogRecord;
    }


};
