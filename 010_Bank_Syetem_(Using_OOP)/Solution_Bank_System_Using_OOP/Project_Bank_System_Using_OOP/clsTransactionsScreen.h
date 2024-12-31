#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTransferScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferLogScreen.h"
class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,eTransfer=4 ,eTransferLog=5,eShowMainMenu = 6
	};
	static short ReadTransactionsMenueOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice=clsInputValidate::ReadShortNumberBetween(1,6,"Enter Number between 1 and 6: ");
		return Choice;
	}
	static void _GoBackToTransactionsMenue() {
		cout << "\n\nPress any key to go back to transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		clsWithDrawScreen::ShowWithDrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen() {
		clsTransferLogScreen::ShowTransferLogScreen();
	}
	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenuOption) {
		switch (TransactionsMenuOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
		}
		case enTransactionsMenueOptions::eShowMainMenu:
		{
			//do nothing here the main screen will handle it:-)
			break;
		}
		
		}
	}
public:
	static void ShowTransactionsMenue() {
		if (!CheckAccessRight(clsUser::enPermissions::pTransactions)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Transactions Screen");

		cout<<setw(37)<<left<<""<< "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main menue.\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	}
};

