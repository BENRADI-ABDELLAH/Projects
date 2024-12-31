#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include<istream>
#include<iomanip>

class clsLoginRegisterScreen: protected clsScreen
{
private:
	
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord) {
		cout << "\t| " << setw(25) << left << LoginRegisterRecord.Date;
		cout << "| " << setw(15) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(15) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(15) << left << LoginRegisterRecord.Permissions;
		cout << "\n";
	}
public:
	static void ShowLoginRegisterScreen() {


		if (!CheckAccessRight(clsUser::enPermissions::pShowLoginRegister)) {
			return;
		}

		vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\t  Login Register List Screen";
		string Subtitle = "\t\t("+ to_string(vLoginRegisterRecord.size()) + ") Record(s).";
		_DrawScreenHeader(Title,Subtitle);

		cout << "\n\t----------------------------------------------------------------------------\n";
		cout << "\t| " << setw(25) << left << "DateTime";
		cout << "| " << setw(15) << left << "User Name";
		cout << "| " << setw(15) << left << "PassWord";
		cout << "| " << setw(15) << left << "Permissions";
		cout << "\n\t----------------------------------------------------------------------------\n";

		if (vLoginRegisterRecord.size() == 0)
		{
			cout << "\n\t\t\tNo Login Available in the system!\n";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord record : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecordLine(record);
			}
		}

		cout << "\t----------------------------------------------------------------------------\n";


	}
};

