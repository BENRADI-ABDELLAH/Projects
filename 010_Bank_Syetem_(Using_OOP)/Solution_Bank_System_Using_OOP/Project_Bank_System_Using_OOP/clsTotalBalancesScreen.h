#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
class clsTotalBalancesScreen:protected clsScreen
{
private:
	static void PrintClientRecordBalanceLine(clsBankClient Client) {
        cout << setw(25) << left << "";
        cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
public:

	static void ShowTotalBalances() {
      
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();

        string Title = "\t Balances List Screen";
        string SubTitle = "\t   ( " + to_string(vClients.size()) + " ) Client(s).";

        _DrawScreenHeader(Title,SubTitle);
        cout << setw(25) << left << "";
        cout << "\n\t\t-----------------------------------------------";
        cout << "----------------------------------\n";
        cout << setw(25) << left << "";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "";
        cout << "\n\t\t-----------------------------------------------";
        cout << "----------------------------------\n";

        double TotalBalances = clsBankClient::GetTotalBalances();
        if (vClients.size() == 0) {
            cout << "\t\t\t\tNo Client Available In the system!";

        }
        else {
            for (clsBankClient Client : vClients) {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
            cout << setw(25) << left << "";
            cout << "\n\t\t-----------------------------------------------";
            cout << "----------------------------------\n";
            cout << setw(8) << left << "";

            cout << "\t\t\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
           
            cout << setw(8) << left << "";

            cout << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ").";
        }
    }
};

