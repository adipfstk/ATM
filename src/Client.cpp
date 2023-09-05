#include "Client.h"
#include "DataBase.h"
#include "Account.h"
#include <iostream>

void Client::openNewAccount(Client& c) {
	DataBase::getInstance().accounts.emplace_back(c.m_id, new Account());
}

Account* Client::accountSelector (Client& c){
	auto accounts = DataBase::getInstance().accounts;
	for (auto& account : accounts) {
			if (account.first==c.m_id) {
				std::cout << "You have an account with IBAN " <<account.second->getIban()
						<< "\nDo you choose this account for next operation(s)? [1]-yes [2]-no\n";
				int option;
				std::cin >>option;
				if (option == 1) {
					return account.second;
				}
				else
					continue;
			}
	}
	return nullptr;
}

void Client::seeAccountDetails(Client& c) {
	auto theAccount = accountSelector(c);
	try{
		if (theAccount==nullptr){
			throw std::string("Doesn't exist any (other) accounts \n\n");
		}
		theAccount->printDetails();
	}
	catch (std::string& e) {
		std::cout << e;
	}
}

double enterSum() {
	double sum;
	std::cout << "Enter the sum: ";
	std::cin>>sum;
	return sum;
}

int enterPin() {
	std::cout << "Enter the pin: ";
	int pin;
	std::cin >> pin;
	return pin;
}

void Client::depositCash(Client& c) {
	auto theAccount = accountSelector(c);
	try{
		if (theAccount==nullptr){
			throw "Empty account exception";
		}
		if (&c==this){
			theAccount->addMoney(enterSum());
			std::cout << "You successfully added entered sum. \n";
		}
		else {
			if (enterPin() == theAccount->getMPin()){
				theAccount->addMoney(enterSum());
			}
			else {
				std::cout << "The entered pin is incorrect. \n";
			}
		}
	}
	catch (const std::string &e) {
		std::cout << e;
	}
}

void Client::withdrawCash(Client& c) {
	auto theAccount = accountSelector(c);
	try
	{
		if (theAccount==nullptr) {
			throw "Empty account exception.";
		}
		else {
			if (&c==this){
				double sum = enterSum();
				if(theAccount->getMCash() < sum) {
					std::cout << "You don't have sufficient amount of money.";
				}
				else {
					theAccount->withdrowMoney(sum);
					std::cout << "You successfully withdraw the sum: " <<sum << "\n";
				}
			}
			else {
				if (enterPin() == theAccount->getMPin()){
					double sum = enterSum();
					if(theAccount->getMCash() < sum) {
						std::cout << "You don't have sufficient amount of money.";
					}
					else {
						theAccount->withdrowMoney(sum);
						std::cout << "You successfully withdraw the sum: " <<sum << "\n";
					}
				}
				else {
					std::cout << "The entered pin is incorrect. \n";
				}
			}
		}
	}
	catch (const std::string &e){
		std::cout << e;
	}
}

Client::Client(const std::string& usr, const std::string& pswd) {
	this->m_usr = usr;
	this->m_pswd = pswd;
	this->m_id=s_incrementId++;
}

Client::~Client() {
}

int Client::s_incrementId = 0;
