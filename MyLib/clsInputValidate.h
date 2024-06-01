#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	// Checks if a number is between the specified range
	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	// Overloaded version for integer numbers
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	// Overloaded version for floating-point numbers
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	// Checks if a date is between the specified range
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	// Reads a short number from input, handling invalid inputs
	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	// Reads a short number from input within the specified range, handling invalid inputs
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	// Reads an integer number from input, handling invalid inputs
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	// Reads an integer number from input within the specified range, handling invalid inputs
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	// Reads a floating-point number from input, handling invalid inputs
	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	// Reads a floating-point number from input within the specified range, handling invalid inputs
	static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) 
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	// Reads a double-precision floating-point number from input, handling invalid inputs
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	// Reads a double-precision floating-point number from input within the specified range, handling invalid inputs
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) 
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	// Checks if a given date is valid
	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	// Reads a string from input
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};
