#pragma once
#include<iostream>
#include"clsPerson.h";
#include"clsString.h";
#include<fstream>
#include<string>
#include<vector>
#include"clsDate.h"
#include"Global.h"
using namespace std;
class clsBankClient :public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	enMode _Mode;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {

		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4],
			vClientData[5], stod(vClientData[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string seperator = "#//#") {

		string DataLine = "";
		DataLine += Client.FirstName + seperator;
		DataLine += Client.LastName + seperator;
		DataLine += Client.Email + seperator;
		DataLine += Client.Phone + seperator;
		DataLine += Client.AccountNumber() + seperator;
		DataLine += Client.PinCode + seperator;
		DataLine += to_string(Client.AccountBalance) + seperator;

		return DataLine;
	}
	static vector<clsBankClient> _LoadClientsDataFromFile() {

		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string line = "";

			while (getline(MyFile, line)) {

				clsBankClient Client = _ConvertLineToClientObject(line);
				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static void _SaveClientsDataToFile(vector<clsBankClient> vClients) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (clsBankClient C : vClients) {
				if (C.MarkForDelete() == false) {
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}

	}
	void _Update() {
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients) {
			if (C.AccountNumber() == AccountNumber()) {
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << stDataLine << endl;
			MyFile.close();
		}

	}
	string _PrepareTransferLogRecord(double amount,clsBankClient DestinationClient,string UserName,string Seperator="#//#") {
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateString() + Seperator;
		TransferLogRecord += AccountNumber()+Seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLogRecord += to_string(amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}
	void _RegisterTransferLog(double amount, clsBankClient DestinationClient) {

		string stDataLine = _PrepareTransferLogRecord(amount,DestinationClient,CurrentUser.UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open()) {
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string stDataLine, string Seperator = "#//#") {

		stTransferLogRecord TransferLogRecord;
		vector<string>vTransferLogData = clsString::Split(stDataLine, Seperator);

		TransferLogRecord.Date = vTransferLogData[0];
		TransferLogRecord.SourceClientAccount = vTransferLogData[1];
		TransferLogRecord.DestinationClientAccount = vTransferLogData[2];
		TransferLogRecord.Amount = stod(vTransferLogData[3]);
		TransferLogRecord.SourceClientAccountBlance = stod(vTransferLogData[4]);
		TransferLogRecord.DeestinationAccountBlance = stod(vTransferLogData[5]);
		TransferLogRecord.User = vTransferLogData[6];


		return TransferLogRecord;
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;

	bool MarkForDelete() {
		return _MarkedForDelete;
	}

	

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string line = "";


			while (getline(MyFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);

				if (Client.AccountNumber() == AccountNumber) {

					MyFile.close();

					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string line = "";

			while (getline(MyFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode) {

					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}



	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		return (!Client.IsEmpty());
	}


	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists =2};
	enSaveResults Save() {
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty()) {
				return enSaveResults::svFaildEmptyObject;
			}
		}
		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildAccountNumberExists;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;

				return enSaveResults::svSucceeded;
		   	}
		}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	bool Delete() {
		vector<clsBankClient> _vClients;
		_vClients= _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients) {
			if (C.AccountNumber() == _AccountNumber) {
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}
	static vector<clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalances() {
		vector<clsBankClient>vClients = GetClientsList();
		double TotalBalances = 0;

		for (clsBankClient Client : vClients) {
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}

	bool  WithDraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double amount, clsBankClient& DestinationClient) {
		

		if (amount > _AccountBalance)
			return false;
		


		 WithDraw(amount);
		 DestinationClient.Deposit(amount);

		 _RegisterTransferLog(amount, DestinationClient);

		 return true;



		

		
	}

	struct stTransferLogRecord {
		string Date;
		string SourceClientAccount;
		string DestinationClientAccount;
		double Amount;
		double SourceClientAccountBlance;
		double DeestinationAccountBlance;
		string User;
	};
	static vector<stTransferLogRecord>GetTransferLogList() {

		vector<stTransferLogRecord> vtransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";
			stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line)) {

				TransferRecord = _ConvertTransferLogLineToRecord(Line);
				vtransferLogRecord.push_back(TransferRecord);
			}
			MyFile.close();
		}

		return vtransferLogRecord;
	}
};

