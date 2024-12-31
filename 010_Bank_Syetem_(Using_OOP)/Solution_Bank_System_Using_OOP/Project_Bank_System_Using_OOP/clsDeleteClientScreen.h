#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsDeleteClientScreen:protected clsScreen
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
   
	static void ShowDeleteClientScreen() {

        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient)) {
            return;
        }
        _DrawScreenHeader("\t Delete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        cout << "\nAre you sure you want to delete this client y/n ?";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (Client1.Delete()) {
                cout << "\nClient Deleted Successfully";
                _PrintClient(Client1);
            }
            else {
                cout << "\nError Client was not deleted";
            }
        }
	}
};

