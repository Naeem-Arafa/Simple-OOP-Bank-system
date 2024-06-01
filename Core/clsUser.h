#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "../MyLib/clsString.h"
#include "../MyLib/clsDate.h"
#include "../MyLib/clsUtil.h"
#include <vector>
#include <fstream>

using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    // Converts a login register line to a record
    struct stLoginRegisterRecord;
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;
    }

    // Prepares the login record string for logging
    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;
        //here we encypt store the encrypted Password not the real one.
        LoginRecord += clsUtil::EncryptText(Password) + Seperator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }

    // Converts a line from the file to a clsUser object
    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
    }

    // Converts a clsUser object to a line to store in the file
    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        //here we encypt store the encrypted Password not the real one.
        UserRecord += clsUtil::EncryptText(User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;
    }

    // Loads user data from file into a vector of clsUser objects
    static  vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                vUsers.push_back(User);
            }

            MyFile.close();
        }
        return vUsers;
    }

    // Saves user data to file from a vector of clsUser objects
    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    // Updates the user data in the file
    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);
    }

    // Adds a new user to the file
    void _AddNew()
    {
        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    // Adds a data line to the file
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    // Returns an empty user object
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    enum enPermissions 
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,
        pListLoginRegister = 128
    };

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    };

    // Constructor for clsUser class
    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    // Checks if the user object is empty
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    // Checks if the user is marked for deletion
    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    // Gets the username
    string GetUserName()
    {
        return _UserName;
    }

    // Sets the username
    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    // Sets the password
    void SetPassword(string Password)
    {
        _Password = Password;
    }

    // Gets the password
    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    // Sets the permissions
    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    // Gets the permissions
    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    // Finds a user by username
    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    // Finds a user by username and password
    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    // Saves the user object to the file
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
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

    // Checks if a user exists by username
    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    // Deletes the user object
    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    // Gets an object for adding a new user
    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    // Gets the list of users
    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    // Checks access permission for a user
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;

    }

    // Registers the login event for a user
    void RegisterLogIn()
    {
        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    // Gets the login register list
    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {
                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);
            }
            MyFile.close();
        }
        return vLoginRegisterRecord;
    }

};
