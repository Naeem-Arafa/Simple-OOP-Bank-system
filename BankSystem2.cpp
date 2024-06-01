#include <iostream>
#include "Screens/User/clsLoginScreen.h"

int main()

{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

    return 0;
}