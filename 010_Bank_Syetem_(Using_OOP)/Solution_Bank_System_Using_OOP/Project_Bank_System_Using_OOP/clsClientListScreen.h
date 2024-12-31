#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>

class clsClientListScreen:protected clsScreen
{
private:
    static void PrintClientsRecordLine(clsBankClient Client) {
        cout << setw(8) << left << "";
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout << "| " << left << setw(12) << Client.AccountBalance;

    }

	
public:
    static void ShowClientsList() {
       


        if (!CheckAccessRight(clsUser::enPermissions::pListClients)) {
            return;
        }

        vector<clsBankClient>vClients = clsBankClient::GetClientsList();

        string Title = "\t   Client List Screen";
        string SubTitle = "\t   (" +to_string(vClients.size() )+ ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout <<"\n"<< setw(8) << left << "";
        cout << "---------------------------------------------";
        cout << "-------------------------------------------------------\n";
        cout << setw(8) << left << "";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout <<"\n"<< setw(8) << left << "";
        cout << "---------------------------------------------";
        cout << "-------------------------------------------------------\n";

        if (vClients.size() == 0) {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else {
            for (clsBankClient Client : vClients) {
                PrintClientsRecordLine(Client);
                cout << endl;
            }
        }
        cout <<setw(8)<<left<<""<< "---------------------------------------------";
        cout << "-------------------------------------------------------\n";


    }

};

