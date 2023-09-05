/*
 * DataBase.h
 *
 *  Created on: Jun 17, 2022
 *      Author: asplacinta
 */
#ifndef DATABASE_H_
#define DATABASE_H_
#include <vector>
#include "Employee.h"
#include "Account.h"
class DataBase {
private:
	static DataBase b1;
	DataBase(const DataBase&) = delete;
	DataBase() = default;
public:
	static DataBase& getInstance() {
		return b1;
	}
	bool isRunning();
	std::vector <Client*> clients;
	std::vector <std::pair <int, Account*>> accounts;
	std::vector <Employee*> emps;
};
#endif /* DATABASE_H_ */
