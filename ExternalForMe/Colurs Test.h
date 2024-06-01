#pragma once
#include <iostream>
using namespace std;
class clsColors
{
public:
    // Colors Any Line Of Text 
    static void ColorJustLineOfTextByRed(string Text)
    {
        cout << "\x1B[31m" << Text << "\033[0m"; // red
    }

    static void ColorJustLineOfTextByGreen(string Text)
    {
        cout << "\x1B[32m " << Text << "\033[0m"; // green
    }

    static void ColorJustLineOfTextByYellow(string Text)
    {
        cout << "\x1B[33m " << Text << "\033[0m"; // yellow 
    }
    static void ColorJustLineOfTextByOrange(string Text)
    {
        cout << "\x1B[38;5;208m" << Text << "\033[0m"; // Orange (combining red and yellow)
    }

    static void ColorJustLineOfTextByPink(string Text)
    {
        cout << "\x1B[38;5;205m" << Text << "\033[0m"; // Pink
    }
    static void ColorJustLineOfTextByBackGroundYellow(string Text)
    {
        cout << "\033[3;43;30m" << Text << "\033[0m"; // Yellow background
    }

    static void ColorJustLineOfTextByLightYellow(string Text)
    {
        cout << "\x1B[93m" << Text << "\033[0m";   // light yellow
    }

    static void ColorJustLineOfTextByGreenBackGround(string Text)
    {
        cout << "\033[3;42;30m" << Text << "\033[0m"; // green background
    }

    static void ColorJustLineOfTextByWhite(string Text)
    {
        cout << "\x1B[37m " << Text << "\033[0m"; // white
    }

    static void ColorJustLineOfTextByBrightBlue(string Text)
    {
        cout << "\x1B[36m" << Text << "\033[0m"; // Bright blue 

    }

    static void ColorJustLineOfTextByMagenta(string Text)
    {
        cout << "\x1B[35m " << Text << "\033[0m";   // magenta

    }

    static void ColorJustLineOfTextByBlue(string Text)
    {
        cout << "\x1B[34m" << Text << "\033[0m"; // blue
    }

    static void ColorJustLineOfTextByBlueBackGround(string Text)
    {
        cout << "\033[3;44;30m " << Text << "\033[0m"; // blue background
    }

    static void ColorJustLineOfTextByBrightBlueBackGround(string Text)
    {
        cout << "\033[3;104;30m " << Text << "\033[0m";  // bright blue background
    }

    static void ColorJustLineOfTextBygrayBackGround(string Text)
    {
        cout << "\033[3;100;30m" << Text << "\033[0m"; // gray background
    }

    static void ColorJustLineOfTextByRedAndWhiteBackGround(string Text)
    {
        cout << "\033[1;47;35m" << Text << "\033[0m";  // red and white background
    }

    static void ColorJustLineOfTextByPinkAndWhiteBackGround(string Text)
    {
        cout << "\033[3;47;35m" << Text << "\033[0m"; // Pink and white background
    }


    // Color Any Long Text I Want 
  //  بعد تلوين النص انت بحاجة لوضع الكود هاد
// Example 
/*static void _DrawScreenHeader(string Title, string SubTitle = "")
{
    clsColors::SetTextColorForBrightBlue();
    cout << "\t\t\t\t\t________________________________________";
    clsColors::SetTextColorForDefualte();
    cout << "\n\n\t\t\t\t\t  " << Title;
    if (SubTitle != "")
    {
        cout << "\n\t\t\t\t\t  " << SubTitle;
    }
    clsColors::SetTextColorForBrightBlue();
    cout << "\n\t\t\t\t\t________________________________________\n\n";
    clsColors::SetTextColorForBrightMagenta();
    cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << "\t";
    cout << "\tDate : " << clsDate::DateToString(clsDate()) << "\n\n";

    clsColors::SetTextColorForDefualte();
}*/
    static void SetTextColorForDefualte()
    {
        cout << "\033[0m"; // 0
    }

    static void SetTextColorForRed()
    {
        cout << "\033[31m"; // 31
    }

    static void SetTextColorForBrightRed()
    {
        cout << "\033[91m"; // 91
    }

    static void SetTextColorForGreen()
    {
        cout << "\033[32m"; // 32
    }

    static void SetTextColorForBrightGreen()
    {
        cout << "\033[92m"; // 92
    }

    static void SetTextColorForYellow()
    {
        cout << "\033[33m"; // 33
    }

    static void SetTextColorForBrightYellow()
    {
        cout << "\033[93m"; // 93
    }

    static void SetTextColorForBlue()
    {
        cout << "\033[34m"; // 34
    }

    static void SetTextColorForBrightBlue()
    {
        cout << "\033[94m"; // 94
    }

    static void SetTextColorForMagenta()
    {
        cout << "\033[35m"; // 35
    }

    static void SetTextColorForBrightMagenta()
    {
        cout << "\033[95m"; // 95
    }

    static void SetTextColorForCyan()
    {
        cout << "\033[36m"; // 36
    }

    static void SetTextColorForWhite()
    {
        cout << "\033[37m"; // 37
    }
};