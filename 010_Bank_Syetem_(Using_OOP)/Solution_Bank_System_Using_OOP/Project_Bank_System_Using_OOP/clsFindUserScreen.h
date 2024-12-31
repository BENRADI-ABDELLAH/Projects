#pragma once
#include <iostream>
#include"clsScreen.h"
class clsFindUserScreen: protected clsScreen
{

private :
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}


public:
	static void ShowFindUserScreen() {
		_DrawScreenHeader("\t   Find User Screen");

		string UserName = "";
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUser is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.IsEmpty()) {
			cout << "\nUser Found :-)";
		}
		else {
			cout << "\nUser was not found :-(";
		}
		_PrintUser(User1);
	}
};
