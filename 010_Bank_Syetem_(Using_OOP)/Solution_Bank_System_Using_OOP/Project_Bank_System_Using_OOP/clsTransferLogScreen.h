#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include "Global.h"
#include "clsUser.h"
#include<iomanip>
class clsTransferLogScreen: protected clsScreen
{

private:
	



	static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		 cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.Date;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceClientAccount;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationClientAccount;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.SourceClientAccountBlance;
		cout << "| " << setw(10) << left << TransferLogRecord.DeestinationAccountBlance;
		cout << "| " << setw(8) << left << TransferLogRecord.User;

	}



public :
	static void ShowTransferLogScreen() {


		vector<clsBankClient::stTransferLogRecord>vTransferLogRecord = clsBankClient::GetTransferLogList();
		
		string Title = "\t   Transfer log list Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord) {
				PrintTransferLogRecordLine(Record);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;






		
	}
};

