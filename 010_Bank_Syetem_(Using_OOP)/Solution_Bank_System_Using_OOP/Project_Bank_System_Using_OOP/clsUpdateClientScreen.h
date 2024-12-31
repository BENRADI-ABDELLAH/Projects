#pragma once

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen: protected clsScreen
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
        static void _ReadClientInfo(clsBankClient& Client) {

            cout << "\nEnter FirstName: ";
            Client.FirstName = clsInputValidate::ReadString();

            cout << "\nEnter LastName: ";
            Client.LastName = clsInputValidate::ReadString();

            cout << "\nEnter Email: ";
            Client.Email = clsInputValidate::ReadString();

            cout << "\nEnter Phone: ";
            Client.Phone = clsInputValidate::ReadString();

            cout << "\nEnter PinCode: ";
            Client.PinCode = clsInputValidate::ReadString();

            cout << "\nEnter Account Balance: ";
            Client.AccountBalance = clsInputValidate::ReadFloatNumber();

        }

public:
	static void ShowUpdateClientScreen() {
        if (!CheckAccessRight(clsUser::enPermissions::pUpdateClients)) {
            return;
        }
        _DrawScreenHeader("\t Update Client Screen");
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number Is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        cout << "\nUpdate Client Info:";
        cout << "\n------------------------\n";
        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:

            cout << "\nAccount Updated Succefully :-)\n";
            _PrintClient(Client1);

            break;

        case clsBankClient::enSaveResults::svFaildEmptyObject:

            cout << "\nError accountwas not saved because it's Empty";
            break;

        }
	}
};

