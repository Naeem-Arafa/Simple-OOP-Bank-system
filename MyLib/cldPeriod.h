#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    // Constructor to initialize the period with start and end dates
    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    // Static method to check if two periods overlap
    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        // Check if Period2 ends before Period1 starts or starts after Period1 ends
        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }

    // Method to check if this period overlaps with another period
    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    // Method to print the start and end dates of the period
    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};
