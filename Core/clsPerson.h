#pragma once
#include <iostream>
#include <string>
#include "../ExternalForMe/InterfaceCommunication.h"
using namespace std;

class clsPerson : public InterfaceCommunication
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    // Constructor for clsPerson class
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Sets the first name
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    // Gets the first name
    string GetFirstName()
    {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    // Sets the last name
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    // Gets the last name
    string GetLastName()
    {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    // Sets the email
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    // Gets the email
    string GetEmail()
    {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    // Sets the phone number
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    // Gets the phone number
    string GetPhone()
    {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    // Returns the full name (first name and last name)
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    // Sends an email with the given title and body
    void SendEmail(string Title, string Body)
    {
        // Email sending logic goes here
    }

    // Sends a fax with the given title and body
    void SendFax(string Title, string Body)
    {
        // Fax sending logic goes here
    }

    // Sends an SMS with the given title and body
    void SendSMS(string Title, string Body)
    {
        // SMS sending logic goes here
    }
};
