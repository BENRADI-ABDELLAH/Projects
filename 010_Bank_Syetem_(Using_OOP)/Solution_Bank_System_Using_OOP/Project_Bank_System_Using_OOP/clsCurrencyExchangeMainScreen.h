#pragma once
#include "clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:

	enum enCurrenciesMainMenueOptions {eListCurrency=1,eFindCurrency=2,eUpdateRate=3,eCurrencyCalculator=4,eMainMenu=5};
	static short _ReadCurrenciesMainMenueeOptions() {

		cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 to 5]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5);

		return Choice;
	}
	static void _GoBackToCurrencieMenue() {

		cout << "\n\nPress any key to go back to main menue...\n";
		system("pause>0");
		ShowCurrencyExchangeMenue();
		
	}
	static void _ShowCurrenciesListScreen() {
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrencyScreen() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateCurrencyRateScreen() {
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen() {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions) {
		switch (CurrenciesMainMenueOptions	)
		{
		case enCurrenciesMainMenueOptions::eListCurrency:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencieMenue();

			break;
		case enCurrenciesMainMenueOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencieMenue();
			break;
		case enCurrenciesMainMenueOptions::eUpdateRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencieMenue();
			break;
		case enCurrenciesMainMenueOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencieMenue();
			break;
		case enCurrenciesMainMenueOptions::eMainMenu:
			//
			break;
		
		}
		
	}
public:
	static void ShowCurrencyExchangeMenue() {
		system("cls");
		_DrawScreenHeader("\t\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currency.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)_ReadCurrenciesMainMenueeOptions());
	}
	
};

