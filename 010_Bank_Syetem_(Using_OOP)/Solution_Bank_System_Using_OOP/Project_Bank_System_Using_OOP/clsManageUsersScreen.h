#pragma once
#include"clsScreen.h"
#include<iomanip>
#include "clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
class clsManageUsersScreen: protected clsScreen
{


private:
	enum enManageUsersMenueOptions {
		eListUsers = 1,
		eAddNewUser=2,
		eDeleteUser=3,
		eUpdateUser=4,
		eFindUser=5,
		eMainMenue=6
	};
	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions Option) {
		switch (Option)
		{
		case enManageUsersMenueOptions::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eMainMenue:
			
			
			
			break;
		default:
			break;
		}
	}
	static short _ReadManageUsersOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1,6);
		return Choice;

	}
	
	static void _ShowAddNewUserScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen() {
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _ShowListUsersScreen() {
		clsListUsersScreen::ShowUsersList();
	}
	static void _GoBackToManageUsersMenue() {
		cout << "\nPress any key to go back to Manage users menue...\n";
		system("pause>0");
		ShowManageUsersMenue();
	}
public:
	static void ShowManageUsersMenue() {
		if (!CheckAccessRight(clsUser::enPermissions::pManageUsers)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");
		cout << setw(37) << left << "" << "=================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "=================================\n";
		cout << setw(37) << left << "" << "\t[1] List users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersOption());
	}
};
