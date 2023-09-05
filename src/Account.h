/*
 * Account.h
 *
 *  Created on: Jun 17, 2022
 *      Author: asplacinta
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
class Account {
private:
	double m_cash;
	int m_pin;
	int m_iban = 1000;
	static int ibanIncreaser;

public:
	void printDetails();
	void addMoney(const double&);
	void withdrowMoney(const double&);

	Account();
	~Account();

	double getMCash() const;
	inline const int& getIban() const {return this->m_iban;}

	int getMPin() const;
	void setMPin(int);

	void setMCash(double mCash);

	std::string currency = "RON";
};

#endif /* ACCOUNT_H_ */
