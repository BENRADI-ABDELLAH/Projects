#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsTransferScreen:protected clsScreen
{

private:
	static void _PrintClientCard(clsBankClient Client) {
		cout << "\n-------------------------";
		cout << "\n    CLient Card";
		cout << "\n-------------------------";
		cout << "\n\nFullName: " << Client.FullName();
		cout << "\nAcc. Number: " << Client.AccountNumber();
		cout << "\nBalance: " << Client.AccountBalance;
		cout << "\n-------------------------";

	}
	static string _ReadAccountNumber() {
		cout << "\nPlease enter Account number to transfer from: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient not exists, choose another account number: ";
			string AccountNumber = clsInputValidate::ReadString();

		}

		return AccountNumber;
	}
	static double _ReadAmount(clsBankClient SourceClient) {
		cout << "\nEnter transfer amount: ";
		double amount = clsInputValidate::ReadDblNumber();

		while (amount > SourceClient.AccountBalance) {
			cout << "\nAmount exceeds the available balance, enter another amount: ";
			amount = clsInputValidate::ReadDblNumber();
		}

		return amount;
	}
public:
	static void ShowTransferScreen() {

		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(SourceClient);


		
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(DestinationClient);

		double amount = _ReadAmount(SourceClient);

		cout << "\nAre you sure to perform this operation? y/n: ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			if (SourceClient.Transfer(amount, DestinationClient)) {
				
				cout << "\n Transfer done succefully.";
				
			}
			else {
				cout << "\nTransfer Faild.";
			}
		}
		else {
			cout << "\nOperation canceled.";
		}
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);

	}
};

