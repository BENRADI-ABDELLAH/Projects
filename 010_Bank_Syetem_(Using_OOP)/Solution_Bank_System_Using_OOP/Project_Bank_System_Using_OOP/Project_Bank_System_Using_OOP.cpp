
//ProgrammingAdvices.com
//Mohmammed Abu-Hadhoud
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <string>
#include<iomanip>
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
#include"clsCurrency.h"
using namespace std;




int main()
{

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen()) {
            break;
        }
    }



    return 0;

}


