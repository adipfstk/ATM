/*
 * Bank.h
 *
 *  Created on: Jun 17, 2022
 *      Author: asplacinta
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include "Account.h"
#include <string>
class Client {
public:
	void openNewAccount(Client&);
	void seeAccountDetails(Client&);
	void depositCash(Client&);
	void withdrawCash(Client&);
	Account* accountSelector(Client&);

	Client(const std::string&, const std::string&);
	~Client();

public:
	static int s_incrementId;
	int m_id;
	std::string m_usr;
	std::string m_pswd;
};

double enterSum();
int enterPin();
#endif
