#ifndef MOOP_ATM_PROJECT_BANK_H
#define MOOP_ATM_PROJECT_BANK_H
#include<string>
class Account;
class DebitCard;
class Bank {
private:
	unsigned int id_;
	std::string address_;
	std::string name_;
public:
	Bank(unsigned int, std::string, std::string);
	~Bank();
	static Account getCardAccount(const DebitCard&);
};
#endif #ifndef MOOP_ATM_PROJECT_BANK_H
