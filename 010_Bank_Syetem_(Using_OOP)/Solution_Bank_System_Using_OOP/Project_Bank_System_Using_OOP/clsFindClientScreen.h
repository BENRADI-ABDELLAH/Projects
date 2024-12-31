#pragma once

#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsFindClientScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client) {
        cout << "\nClient Card";
        cout << "\n-----------------------------";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastname    : " << Client.LastName;
        cout << "\nFullName    : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n-----------------------------\n";
    }

public:

	static void ShowFindClientScreen() {
        if (!CheckAccessRight(clsUser::enPermissions::pFindClient)) {
            return;
        }
        _DrawScreenHeader("\t Find Client Screen");
        cout << "\nPLease enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty()) {
            cout << "\nClient Found\n";
        }
        else {
            cout << "\nClient Was Not Found";
        }
        _PrintClient(Client1);

	}
};

