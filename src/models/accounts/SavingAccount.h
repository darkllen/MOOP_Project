#ifndef MOOP_ATM_PROJECT_SAVINGACCOUNT_H
#define MOOP_ATM_PROJECT_SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account {
private:

    unsigned int limit_;
    float interestRate_;

public:
    SavingAccount(std::string ownerName, std::string IBAN, unsigned int limit, float interestRate) :
            Account(std::move(ownerName), std::move(IBAN)), limit_(limit), interestRate_(interestRate) {}
    ~SavingAccount() = default;
};
#endif //MOOP_ATM_PROJECT_SAVINGACCOUNT_H
