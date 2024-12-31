#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsWithDrawScreen: protected clsScreen
{
private :
	
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

	static string _ReadAccountNumber() {
		string AccountNumber = "";
        cout << "\nPlease enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public:
	static void ShowWithDrawScreen() {
		_DrawScreenHeader("\t  With Draw Screen");

        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nClient with ["<<AccountNumber<<"] does not exist, choose another one: ";
             AccountNumber = _ReadAccountNumber();

        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter Withdraw Amount: ";
        cin >> Amount;

        char Choice = 'n';
        cout << "\nAre you sure you want to perform this transaction? [y/n]: ";
        cin >> Choice;

        if (Choice == 'y' || Choice == 'Y') {
            if (Client1.WithDraw(Amount)) {
                cout << "\nAmount WithDraw Succefully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else {
                cout << "\nCannot withdraw, Insuffecient Balance!";
                cout << "\nAmount to withdraw is: " << Amount;
                cout << "\nYour balance is: " << Client1.AccountBalance;
            }
        }
        else {
            cout << "\nOperation was cancelled.";
        }
    }
};

