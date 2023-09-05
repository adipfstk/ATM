/*
 * Employee.h
 *
 *  Created on: Jun 22, 2022
 *      Author: asplacinta
 */
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "Account.h"
#include "Client.h"
#include <iostream>
#include <random>
class Employee : public Client {
private:
	std::vector <std::string> randomMessages =
	{"If you are under 25 years old and you open a new account now, you can win a car.",
	 "If you invite a friend of you to open a new account you will receive 50 RONS as a gift.",
	"All of our clients should actualize their data next week."
	};
public:
	Employee(const std::string&, const std::string&);
	Employee() = default;
	Client* searchClient() const;
	void editCurrentAccounts();
	void transferMoney();
	void informClients();
	~Employee();
};
#endif /* EMPLOYEE_H_ */
