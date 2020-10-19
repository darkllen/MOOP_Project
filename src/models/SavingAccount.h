#ifndef MOOP_ATM_PROJECT_SAVINGACCOUNT_H
#define MOOP_ATM_PROJECT_SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account {
private:
	unsigned int limit_;
	float interestRate_;

public:
	SavingAccount(const std::string&, const std::string&, const unsigned int&, const double&);
	~SavingAccount();
};
#endif //MOOP_ATM_PROJECT_SAVINGACCOUNT_H
