#include <iostream>
#include "DataBase.h"
#include "Client.h"

int main() {
	//Seeding database
	DataBase& d1 = DataBase::getInstance();
	d1.clients.push_back(new Client("adrian-dev", "1234"));
	d1.clients.push_back(new Client("stefan-dev", "1234b"));
	d1.emps.push_back(new Employee("admin", "1291"));
	while(d1.isRunning()) {
	}
}
