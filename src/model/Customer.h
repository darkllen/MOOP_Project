#include <string>
class Account;
class Customer {
private:
	std::string name_;
	std::string address_;
	Account* accounts_;
public:
	Customer(std::string, std::string, Account* accounts);
};