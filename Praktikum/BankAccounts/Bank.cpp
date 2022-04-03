#include <iostream>
#include <fstream>
#include "BankAccount.h"

int main()
{

	std::ifstream inputFile("TextFile.txt");

	BankAccount Ivan(inputFile);

	Ivan.putMoneyInAccount(4);

	Ivan.printAccount();

	BankAccount Georgi(inputFile);

	std::cout << std::endl;


	Georgi.putMoneyInAccount(8);

	Georgi.printAccount();
}
