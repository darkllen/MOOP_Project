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
	static Account getCardAccount(const DebitCard&);
};