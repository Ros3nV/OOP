#include "BankAccount.h"
BankAccount::~BankAccount()
{
	delete[] this->name;
	delete[] this->bankNumber;

}

BankAccount::BankAccount(const char* name, const char* bankNumber, double accountMoney)
{
	strcpy_s(this->name, maxName, name);
	strcpy_s(this->bankNumber, maxBankNumber, bankNumber);
	this->accountMoney = accountMoney;
}

void BankAccount::printAccount() const
{
	std::cout <<"Name: " << this->name<<std::endl;
	std::cout << "Bank Number: " << this->bankNumber << std::endl;
	std::cout <<"Account Money: " << this->accountMoney << std::endl;
}

void BankAccount::getMoneyFromAccount(double wantedMoney){
	if (this->accountMoney - wantedMoney < 0)
		return;
	this->accountMoney -= wantedMoney;
}

void BankAccount::putMoneyInAccount(double givenMoney)
{
	this->accountMoney += givenMoney;
}

BankAccount::BankAccount(std::ifstream& inPutFile)
{
	inPutFile >> this->name >> this->bankNumber >> this->accountMoney;
}

BankAccount::BankAccount()
{
}
