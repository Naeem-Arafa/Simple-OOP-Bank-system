#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{

private:
    string _Value;

public:

    // Default constructor
    clsString()
    {
        _Value = "";
    }

    // Constructor with initial value
    clsString(string Value)
    {
        _Value = Value;
    }

    // Getter and setter for the string value
    void SetValue(string Value) {
        _Value = Value;
    }
    string GetValue() {
        return _Value;
    }
    __declspec(property(get = GetValue, put = SetValue)) string Value;

    // Static method to get the length of a string
    static short Length(string S1)
    {
        return S1.length();
    };

    // Method to get the length of the string object
    short Length()
    {
        return _Value.length();
    };

    // Static method to count the number of words in a string
    static short CountWords(string S1)
    {
        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }
            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }
        return Counter;
    }

    // Method to count the number of words in the string object
    short CountWords()
    {
        return CountWords(_Value);
    };

    // Static method to convert the first letter of each word to uppercase in a string
    static string  UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    // Method to convert the first letter of each word to uppercase in the string object
    void  UpperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    // Static method to convert the first letter of each word to lowercase in a string
    static string  LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    // Method to convert the first letter of each word to lowercase in the string object
    void  LowerFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    // Static method to convert all letters to uppercase in a string
    static string  UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    // Method to convert all letters to uppercase in the string object
    void  UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    // Static method to convert all letters to lowercase in a string
    static string  LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    // Method to convert all letters to lowercase in the string object
    void  LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

        static char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    // Static method to invert the case of all letters in a string
    static string  InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    // Method to invert the case of all letters in the string object
    void  InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    // Static method to count specific types of letters in a string
    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }
        return Counter;
    }

    // Static method to count the number of capital letters in a string
    static short  CountCapitalLetters(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Counter++;
        }
        return Counter;
    }

    // Method to count the number of capital letters in the string object
    short  CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    // Static method to count the number of small letters in a string
    static short  CountSmallLetters(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Counter++;
        }
        return Counter;
    }

    // Method to count the number of small letters in the string object
    short  CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    // Static method to count the occurrences of a specific letter in a string
    static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }
        }
        return Counter;
    }

    // Method to count the occurrences of a specific letter in the string object
    short  CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

    // Static method to count the number of vowels in a string
    static short  CountVowels(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
                Counter++;
        }
        return Counter;
    }

    // Method to count the number of vowels in the string object
    short  CountVowels()
    {
        return CountVowels(_Value);
    }

    // Static method to split a string into substrings based on a delimiter
    static vector<string> Split(string S1, string Delim)
    {
        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
           
            vString.push_back(sWord);

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }
        return vString;
    }

    // Method to split the string object into substrings based on a delimiter
    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    // Static method to trim leading whitespace from a string
    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    // Method to trim leading whitespace from the string object
    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    // Static method to trim trailing whitespace from a string
    static string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    // Method to trim trailing whitespace from the string object
    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    // Static method to trim leading and trailing whitespace from a string
    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));
    }

    // Method to trim leading and trailing whitespace from the string object
    void Trim()
    {
        _Value = Trim(_Value);
    }

    // Static method to join an vector of strings into a single string with a delimiter
    static string JoinString(vector<string> vString, string Delim)
    {
        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    // Static method to join an array of strings into a single string with a delimiter
    static string JoinString(string arrString[], short Length, string Delim)
    {
        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    // Static method to reverse the order of words in a string
    static string ReverseWordsInString(string S1)
    {
        vector<string> vString;
        string S2 = "";

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1); //remove last space.

        return S2;
    }

    // Method to reverse the order of words in the string object
    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    // Static method to replace occurrences of a word in a string with another word
    static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {
        vector<string> vString = Split(S1, " ");

        for (string& s : vString)
        {
            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }
            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }
            }
        }
        return JoinString(vString, " ");
    }

    // Method to replace occurrences of a word in the string object with another word
    string ReplaceWord(string StringToReplace, string sRepalceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sRepalceTo);
    }

    // Static method to remove punctuations from a string
    static string RemovePunctuations(string S1)
    {
        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }
        return S2;
    }

    // Method to remove punctuations from the string object
    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }
};
