#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>

class clsAddNewClientScreen:protected clsScreen
{
private:
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
    static void _PrintClient(clsBankClient Client) {
        cout << "\nClient Card";
        cout << "\n-----------------------------";
        cout << "\nFirstName   : " <<Client.FirstName;
        cout << "\nLastname    : " <<Client.LastName;
        cout << "\nFullName    : " <<Client.FullName();
        cout << "\nEmail       : " <<Client.Email;
        cout << "\nPhone       : " <<Client.Phone;
        cout << "\nAcc. Number : " <<Client.AccountNumber();
        cout << "\nPassword    : " <<Client.PinCode;
        cout << "\nBalance     : " <<Client.AccountBalance;
        cout << "\n-----------------------------\n";
    }

public:
    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient)) {
            return;
        }

        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number Is Already Used, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\nError Accout Was Not Saved Because it't Empty";
            break;
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!";
            break;
        }

        }
    }

};

