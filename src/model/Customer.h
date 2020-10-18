#ifndef MOOP_ATM_PROJECT_CUSTOMER_H
#define MOOP_ATM_PROJECT_CUSTOMER_H

#include <string>
class Account;
class Customer {
private:
	std::string name_;
	std::string address_;
	Account* accounts_;
public:
	Customer(std::string, std::string, Account* accounts);
	~Customer();
};
#endif //MOOP_ATM_PROJECT_CUSTOMER_H
