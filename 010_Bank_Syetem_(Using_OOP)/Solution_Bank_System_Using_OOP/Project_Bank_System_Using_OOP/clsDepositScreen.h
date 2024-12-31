#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iostream>
class clsDepositScreen:protected clsScreen
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
	static string _ReadAccountNumber() {
		string AccountNumber = "";
		cout << "\nPlease enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}


public :
	static void ShowDepositScreen() {
		_DrawScreenHeader("\t   Deposit Screen");
		string AccountNumber = _ReadAccountNumber();


		while(!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with ["<<AccountNumber<<"] does not found";
			 AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "Please enter deposit amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure want to perform this transaction? [y/n]: ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Succefully.\n";
			cout << "\nNew Balance Is: " << Client1.AccountBalance;
		}
		else {
			cout << "\nOperation was cancelled.\n";
		}

	}
};

