#ifndef MOOP_ATM_PROJECT_SAVINGACCOUNT_H
#define MOOP_ATM_PROJECT_SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account {
private:

    // avaliable number of times to take money
    unsigned int limit_;
    float interestRate_;

public:
    SavingAccount(const std::string& ownerName, const std::string& IBAN, const BANK_NUMBER_T & bank, const unsigned int& limit, const float& interestRate) :
            Account(ownerName, IBAN, bank),  limit_(limit), interestRate_(interestRate) {}
    ~SavingAccount() = default;
};
#endif //MOOP_ATM_PROJECT_SAVINGACCOUNT_H
