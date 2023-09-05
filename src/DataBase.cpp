#include "DataBase.h"
#include <iostream>

DataBase DataBase::b1;
bool DataBase::isRunning() {
		std::cout << "Welcome! \n"
			<< "So you are a [1] - user [2] - employee [3] - any key to close\n";
		size_t type;
		bool flag = false;
		std::cin>>type;
		if (type == 1){
			for (size_t i =0; i<clients.size(); i++) {
					std::cout << "Enter user name and password: \n"
							<< "user name: \n";
					std::string usr, pwd;
					std::cin >> usr;
					std::cout << "password: \n";
					std::cin >> pwd;
					if (clients[i]->m_usr == usr && clients[i]->m_pswd == pwd) {
						size_t option = -1;
						flag = true;
						while (option!=0){
							std::cout << "Enter the option: \n";
							std::cout << "[1] Open new account \n";
							std::cout << "[2] See account details \n";
							std::cout << "[3] Deposit cash \n";
							std::cout << "[4] Withdraw cash \n";
							std::cout << "[5] Any key to exit \n";
							std::cin >> option;
							switch (option) {
							case 1:
								clients[i]->openNewAccount(*clients[i]);
								break;
							case 2:
								clients[i]->seeAccountDetails(*clients[i]);
								break;
							case 3:
								clients[i]->depositCash(*clients[i]);
								break;
							case 4:
								clients[i]->withdrawCash(*clients[i]);
								break;
							default:
								isRunning();
							}
						}
				 }
				if (flag == false) {
						std::cout << "Invalid login data.\n";
						return false;
				}
			}
		}
		else if (type == 2) {
		  for (auto& employee: emps) {
			std::cout << "Enter user name and password: \n"
					<< "user name: \n";
			std::string usr, pwd;
			std::cin >> usr;
			std::cout << "password: \n";
			std::cin >> pwd;
		    if (employee-> m_usr == usr && employee-> m_pswd == pwd) {
		      size_t option = -1;
		      flag = true;
		      while (option != 0) {
		    	  std::cout << "Enter the option: \n";
		    	  std::cout << "[1] Open new account for anybody \n";
		    	  std::cout << "[2] Search for a client in DB \n";
		    	  std::cout << "[3] Edit current account\n";
		    	  std::cout << "[4] Deposit cash in an account \n";
		    	  std::cout << "[5] Withdraw cash \n";
		    	  std::cout << "[6] Transfer money \n";
		    	  std::cout << "[7] Inform customers \n";
		    	  std::cout << "[8] Any key to exit \n";
		    	  std::cin >> option;
		    	  switch (option) {
		    	  case 1:
		    		  employee->openNewAccount(*employee->searchClient());
		    		  break;
		    	  case 2:
		    		  employee->searchClient();
		    		  break;
		    	  case 3:
		    		  employee->editCurrentAccounts();
		    		  break;
		    	  case 4:
		    		  employee->depositCash(*employee->searchClient());
		    		  break;
		    	  case 5:
		    		  if (employee->searchClient()!=nullptr)
		    			  employee ->withdrawCash(*employee->searchClient());
		    		  break;
		    	  case 6:
		    		  employee->transferMoney();
		    		  break;
		    	  case 7:
		    		  employee->informClients();
		    		  break;
		    	  default:
		    		  isRunning();
		          }
		        }
		      }
			if (flag == false) {
				std::cout << "Invalid login data.\n";
				return false;
			}
		   }
		}
		else if (type ==3) {
			std::cout << "Have a nice day! \n";
			return false;
		}
}
