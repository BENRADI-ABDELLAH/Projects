#pragma once
#include<iomanip>
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"
#include "clsScreen.h"
class clsLoginScreen: protected clsScreen
{
private:
	static bool _Login() {

		bool LoginFaild = false;

		string Username, Password;

		short FaildLoginCount = 0;
		do {

			if (LoginFaild) {
				FaildLoginCount++;
				cout << "\nInvalid Username/Password!\n";
				cout << "You have " << (3-FaildLoginCount) << " Trials to login.\n\n";
			}

			if (FaildLoginCount == 3) {
				cout << "You are locked after 3 faild trials.";
				return false;
			}
			cout << "Enter Username: ";
			cin >> Username;

			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

			

		} while (LoginFaild);

		
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}
public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();
	}
};

