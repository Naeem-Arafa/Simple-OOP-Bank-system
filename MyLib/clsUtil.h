#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:
    // Enum defining types of characters
    enum enCharType 
    {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    // Method to seed the random number generator
    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    // Method to generate a random number within a specified range
    static  int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    // Method to get a random character of a specified type
    static char GetRandomCharacter(enCharType CharType)
    {
        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    // Method to generate a random word of a specified length and character type
    static  string GenerateWord(enCharType CharType, short Length)
    {
        string Word;

        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    // Method to generate a random key string of a specified character type
    static string  GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);

        return Key;
    }

    // Method to generate and display multiple random keys
    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    // Method to fill an array with random numbers
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    // Method to fill an array with random words
    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);
    }

    // Method to fill an array with random keys
    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    // Methods to swap values of different types
    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    // Method to shuffle an array
    static  void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    // Method to shuffle an array
    static  void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    // Method to generate tabs as per input
    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    // Method to encrypt text using a simple encryption algorithm
    static string  EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    // Method to decrypt text encrypted using the above encryption algorithm
    static string  DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    // Method to convert a number to its textual representation
    static string NumberToText(int Number)
    {
        if (Number == 0)
            return "";

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
            return  "One Hundred " + NumberToText(Number % 100);

        if (Number >= 200 && Number <= 999)
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);

        if (Number >= 1000 && Number <= 1999)
            return  "One Thousand " + NumberToText(Number % 1000);

        if (Number >= 2000 && Number <= 999999)
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);

        if (Number >= 1000000 && Number <= 1999999)
            return  "One Million " + NumberToText(Number % 1000000);

        if (Number >= 2000000 && Number <= 999999999)
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);

        if (Number >= 1000000000 && Number <= 1999999999)
            return  "One Billion " + NumberToText(Number % 1000000000);
        else
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);


    }

};