/*
 * Employee.cpp
 *
 *  Created on: Jun 22, 2022
 *      Author: asplacinta
 */

#include "Employee.h"
#include "DataBase.h"
#include <ctime>
const double EUR = 4.62;

Client* Employee::searchClient() const {
	std::cout << "Enter client id you want to search for: \n";
	int id;
	bool isFound = false;
	std::cin >> id;
	auto& clients = DataBase::getInstance().clients;
	for (auto client : clients){
		if (client->m_id == id) {
			isFound = true;
			std::cout << "The client with id " <<id << " was found in database. \n";
			return client;
		}
	}
	if (!isFound) {
		std::cout << "The client with given id was not found in database. \n";
	}
	return nullptr;
}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}

Account* searchByIban() {
	std::cout << "Enter the IBAN of account you want to do this operation: ";
	int iban;
	std::cin >>iban;
	auto& accounts = DataBase::getInstance().accounts;
	for (auto& account : accounts){
		if (account.second->getIban() == iban){
			std::cout <<"The IBAN was found in db. \n";
			return account.second;
		}
	}
	return nullptr;
}

void Employee::editCurrentAccounts() {
	auto account = searchByIban();
	try {
		if (account==nullptr) {
			throw std::string("Can't find the given IBAN.\n");
		}
		else {
			std::cout << "What you want to edit? \n"
					<< "[1] Change concurrency to EUR \n"
					<< "[2] Change PIN \n";
			int option;
			std::cin>>option;
			switch(option){
			case 1:
			{
				account->setMCash(account->getMCash()/EUR);
				account->currency = "EUR";
				break;
			}
			case 2:
			{
				std::cout << "Enter the pin: \n";
				account->setMPin(enterPin());
				break;
			}
			}
		}
	}
	catch(std::string& e) {
		std::cout <<e;
	}
}

void Employee::transferMoney() {
	std::cout << "By using this option, you will transfer money from an account to other \n";
	std::cout << "The sender account: \n";
	auto first = searchByIban();
	std::cout << "The receiver account: \n";
	auto second = searchByIban();
	if (first==second || first ==nullptr || second == nullptr) {
		std::cout << "The IBANs should be valid \n";
	}
	else {
		double sum = enterSum();
		first->setMCash(first->getMCash()-sum);
		second->setMCash(second->getMCash()+sum);
	}
}

void Employee::informClients() {
	srand(time(0));
    std::cout << this->randomMessages[rand()%3] << "\n";
}

Employee::Employee(const std::string &usr,
		const std::string &pswd) : Client(usr, pswd) {
}
