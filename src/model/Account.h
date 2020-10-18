#ifndef MOOP_ATM_PROJECT_ACCOUNT_H
#define MOOP_ATM_PROJECT_ACCOUNT_H
#include <string>
class Account {
private:
	std::string ownerName_;
	std::string IBAN_;
public:
	Account(const std::string&, const std::string&);
	~Account();
	size_t getCardPIN();
	size_t getBank();
};
#endif //MOOP_ATM_PROJECT_ACCOUNT_H
