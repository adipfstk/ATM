/*
 * Account.cpp
 *
 *  Created on: Jun 17, 2022
 *      Author: asplacinta
 */

#include "Account.h"
#include <iostream>
int Account::ibanIncreaser = 1;
Account::Account() {
	std::cout << "Enter the pin for the new account(digital signature): \n";
	int pin;
	std::cin>>pin;
	this->m_pin=pin;
	this->m_iban += ibanIncreaser++;;
	this->m_cash=0;
}

Account::~Account() {
}

void Account::printDetails() {
	std::cout << "IBAN: " << this->m_iban << "\n" <<"CASH: " << this->m_cash << "\n";
}

void Account::addMoney(const double& money) {
	this->m_cash += money;
}

void Account::withdrowMoney(const double &money) {
	this->m_cash -= money;
}

double Account::getMCash() const {
	return this->m_cash;
}

int Account::getMPin() const {
	return this->m_pin;
}

void Account::setMPin(int mPin) {
	this->m_pin = mPin;
}

void Account::setMCash(double mCash) {
	m_cash = mCash;
}
