#pragma once
#include <iostream>
#include <fstream>
const size_t maxName = 23;
const size_t maxBankNumber = 15;

class BankAccount
{
private:
	char* name = new char[maxName];
	char* bankNumber = new char[15];
	double accountMoney;
public:
	
	BankAccount(std::ifstream& inFile);

	BankAccount();

	~BankAccount();

	BankAccount(const char* name, const char* bankNumber, double accountMoney);


	void printAccount()const;

	void getMoneyFromAccount(double wantedMoney);

	void putMoneyInAccount(double wantedMoney);

	
	
};

