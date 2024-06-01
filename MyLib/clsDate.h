#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<string>
#include "clsString.h"

using namespace std;

class clsDate
{

private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	// Default constructor to initialize date with current system date
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	// Constructor to initialize date from string in format "dd/mm/yyyy"
	clsDate(string sDate)
	{
		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	// Constructor to initialize date with given day, month, and year
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	// Constructor to initialize date from day order in the year
	clsDate(short DateOrderInYear, short Year)
	{
		//This will construct a date by date order in year
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
		_Day = Date1.Day;
		_Month = Date1.Month;
		_Year = Date1.Year;
	}

	// Setter method for Day
	void SetDay(short Day) {
		_Day = Day;
	}

	// Getter method for Day
	short GetDay() {
		return _Day;
	}
	// Getter and setter for Day property
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_Month = Month;
	}

	// Getter method for Month
	short GetMonth() {
		return _Month;
	}
	// Getter and setter for Month property
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	// Setter method for Year
	void SetYear(short Year) {
		_Year = Year;
	}

	// Getter method for Year
	short GetYear() {
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	// Print the date in "dd/mm/yyyy" format
	void Print()
	{
		cout << DateToString() << endl;
	}

	// Get the current system date
	static clsDate GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	// Get the current system date and time as a string
	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

	// Check if a given date is valid
	static	bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2)
		{
			if (isLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;
	}

	// Check if this date object is valid
	bool IsValid()
	{
		return IsValidDate(*this);
	}

	// Convert date to string in "dd/mm/yyyy" format
	static string DateToString(clsDate Date)
	{
		return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	// Convert this date object to string
	string DateToString()
	{
		return  DateToString(*this);
	}

	// Check if a given year is a leap year
	static bool isLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 100
	    // OR if year is divisible by 400
	    // then it is a leap year
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	// Check if this year is a leap year
	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	// Get the number of days in a year
	static short NumberOfDaysInAYear(short Year)
	{
		return  isLeapYear(Year) ? 365 : 364;
	}

	// Get the number of days in this year
	short NumberOfDaysInAYear()
	{
		return  NumberOfDaysInAYear(_Year);
	}

	// Get the number of hours in a year
	static short NumberOfHoursInAYear(short Year)
	{
		return  NumberOfDaysInAYear(Year) * 24;
	}

	// Get the number of hours in this year
	short NumberOfHoursInAYear()
	{
		return  NumberOfHoursInAYear(_Year);
	}

	// Get the number of minutes in a year
	static int NumberOfMinutesInAYear(short Year)
	{
		return  NumberOfHoursInAYear(Year) * 60;
	}

	// Get the number of minutes in this year
	int NumberOfMinutesInAYear()
	{
		return  NumberOfMinutesInAYear(_Year);
	}

	// Get the number of seconds in a year
	static int NumberOfSecondsInAYear(short Year)
	{
		return  NumberOfMinutesInAYear(Year) * 60;
	}

	// Get the number of seconds in this year
	int NumberOfSecondsInAYear()
	{
		return  NumberOfSecondsInAYear();
	}

	// Get the number of days in a given month of a given year
	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return  0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
	}

	// Get the number of days in this month of this year
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	// returns the number of hours in a given month and year
	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return  NumberOfDaysInAMonth(Month, Year) * 24;
	}

	// returns the number of hours in the month of this date object
	short NumberOfHoursInAMonth()
	{
		return  NumberOfDaysInAMonth(_Month, _Year) * 24;
	}

	// returns the number of minutes in a given month and year
	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return  NumberOfHoursInAMonth(Month, Year) * 60;
	}

	// returns the number of minutes in the month of this date object
	int NumberOfMinutesInAMonth()
	{
		return  NumberOfHoursInAMonth(_Month, _Year) * 60;
	}

	// returns the number of seconds in a given month and year
	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return  NumberOfMinutesInAMonth(Month, Year) * 60;
	}

	// returns the number of seconds in the month of this date object
	int NumberOfSecondsInAMonth()
	{
		return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
	}

	// returns the day of the week order for a given date (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		// Calculate the day of the week order using Zeller's Congruence formula
		// Gregorian: 0:Sun, 1:Mon, 2:Tue...etc
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	// returns the day of the week order for this date object
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	// returns the short name of the day of the week based on its order
	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder];
	}

	// returns the short name of the day of the week for a given date
	static string DayShortName(short Day, short Month, short Year)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
	}

	// returns the short name of the day of the week for this date object
	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder(_Day, _Month, _Year));
	}

	// returns the short name of the month for a given month number (1 = Jan, 2 = Feb, ..., 12 = Dec)
	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}

	// returns the short name of the month for this date object
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	// prints the calendar for a given month and year
	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n  _________________________________\n");
	}

	// prints the calendar for the month of this date object
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	// prints the calendar for a given year
	static void PrintYearCalendar(int Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

		return;
	}

	// prints the calendar for the year of this date object
	void PrintYearCalendar()
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _Year);
		printf("  _________________________________\n");

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, _Year);
		}
		return;
	}

	// returns the number of days from the beginning of the year for a given date
	static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;

		return TotalDays;
	}

	// returns the number of days from the beginning of the year for this date object
	short DaysFromTheBeginingOfTheYear()
	{
		short TotalDays = 0;

		for (int i = 1; i <= _Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, _Year);
		}
		TotalDays += _Day;

		return TotalDays;
	}

	// This method calculates a date based on its order within a year and the year itself.
	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	// This method adds a specified number of days to the current date.
	void AddDays(short Days)
	{
		short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(_Month, _Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}
		}
	}

	// This method checks if Date1 is before Date2.
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	// This method checks if the current date is before the specified date.
	bool IsDateBeforeDate2(clsDate Date2)
	{
		//note: *this sends the current object :-) 
		return  IsDate1BeforeDate2(*this, Date2);
	}

	// This method checks if Date1 is equal to Date2.
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}

	// This method checks if the current date is equal to the specified date.
	bool IsDateEqualDate2(clsDate Date2)
	{
		return  IsDate1EqualDate2(*this, Date2);
	}

	// This method checks if the specified date is the last day of its month.
	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}

	// This method checks if the current date is the last day of its month.
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	// This method checks if the specified month is the last month of the year.
	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	// This method increments the given date by one day.
	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}

	// This method increments the current date by one day.
	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	// This method swaps two dates.
	static void  SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	// This method calculates the difference in days between two dates.
	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff
		int Days = 0;
		short SawpFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates 
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	// This method calculates the difference in days between the current date and a specified date.
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	// This method calculates the age in days based on the given date of birth.
	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
	}

	// This method increments the given date by one week.
	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}

	// This method increments the current date by one week.
	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	// This method increments the given date by the specified number of weeks.
	clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	// This method increments the current date by the specified number of weeks.
	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	// This method increments the given date by one month, adjusting for month-end overflow.
	clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	// This method increments the current date by one month, adjusting for month-end overflow.
	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	// This method increments the given date by the specified number of days.
	clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	// This method increments the current date by the specified number of days.
	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}

	// This method increments the given date by the specified number of months, adjusting for month-end overflow.
	clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	// This method increments the current date by the specified number of months, adjusting for month-end overflow.
	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	// This method increments the given date by one year.
	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}

	// This method increments the current date by one year.
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	// This method increments the given date by the specified number of years.
	clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date.Year += Years;
		return Date;
	}

	// This method increments the current date by the specified number of years.
	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	// Increases the date by one decade
	clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	}

	// Increases the date of the object by one decade
	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	// Increases the date by a specified number of decades
	clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}

	// Increases the date of the object by a specified number of decades
	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	// Increases the date by one century
	clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years
		Date.Year += 100;
		return Date;
	}

	// Increases the date of the object by one century
	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	// Increases the date by one millennium
	clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years
		Date.Year += 1000;
		return Date;
	}

	// Increases the date of the object by one millennium
	clsDate IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	// This method decrements the given date by one day.
	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}

	// Decrements the date of the object by one day
	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	// Decrements the given date by one week
	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	// Decrements the date of the object by one week
	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	// Decrements the date by a specified number of weeks
	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	// Decrements the date of the object by a specified number of weeks
	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	// Decrements the given date by one month
	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;

		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	// Decrements the date of the object by one month
	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	// Decrements the given date by a specified number of days
	static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	// Decrements the date of the object by a specified number of days
	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	// Decrements the given date by a specified number of months
	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	// Decrements the date of the object by a specified number of months
	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}

	// Decrements the given date by one year
	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date.Year--;
		return Date;
	}

	// Decrements the date of the object by one year
	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	// Decrements the given date by a specified number of years
	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
	{
		Date.Year -= Years;
		return Date;
	}

	// Decrements the date of the object by a specified number of years
	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	// Decrements the given date by one decade
	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years
		Date.Year -= 10;
		return Date;
	}

	// Decrements the date of the object by one decade
	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	// Decrements the given date by a specified number of decades
	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
	{
		Date.Year -= Decades * 10;
		return Date;
	}

	// Decrements the date of the object by a specified number of decades
	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	// Decrements the given date by one century
	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years
		Date.Year -= 100;
		return Date;
	}

	// Decrements the date of the object by one century
	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	// Decrements the given date by one millennium
	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years
		Date.Year -= 1000;
		return Date;
	}

	// Decrements the date of the object by one millennium
	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	// Checks if the given date is the end of a week
	static short IsEndOfWeek(clsDate Date)
	{
		return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
	}

	// Checks if the date of the object is the end of a week
	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	// Checks if the given date is a weekend
	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	// Checks if the date of the object is a weekend
	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	// Checks if the given date is a business day
	static bool IsBusinessDay(clsDate Date)
	{
	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(Date);
	}

	// Checks if the date of the object is a business day
	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	// Calculates the number of days until the end of the week for the given date
	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	// Calculates the number of days until the end of the week for the date of the object
	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	// Calculates the number of days until the end of the month for the given date
	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{
		clsDate EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);
	}

	// Calculates the number of days until the end of the month for the date of the object
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	// Calculates the number of days until the end of the year for the given date
	static short DaysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);
	}

	// Calculates the number of days until the end of the year for the date of the object
	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	// Calculates the number of business days between two dates
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}
		return Days;
	}

	// Calculates the number of vacation days between two dates (same as business days)
	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	// Calculates the return date after a vacation given the start date and vacation days
	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = AddOneDay(DateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	// Checks if Date1 is after Date2
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	// Checks if the date of the object is after the given date
	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	// Compares two dates and returns their relationship
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

			 //this is faster
		return enDateCompare::After;
	}

	// Compares the date of the object with the given date and returns their relationship
	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}
};
