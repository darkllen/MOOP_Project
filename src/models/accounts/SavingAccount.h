#ifndef MOOP_ATM_PROJECT_SAVINGACCOUNT_H
#define MOOP_ATM_PROJECT_SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account {
private:

    // avaliable number of times to take money
    ACCOUNT_BALANCE_AMOUNT_T limit_;
    float interestRate_;

public:
    SavingAccount(const int& ownerId, const std::string& IBAN, const BANK_NUMBER_T & bank, const ACCOUNT_BALANCE_AMOUNT_T& limit, const float& interestRate,const ACCOUNT_BALANCE_AMOUNT_T& money) :
            Account(ownerId, IBAN, bank, money),  limit_(limit), interestRate_(interestRate) {}
    ~SavingAccount() = default;

    unsigned int getLimit() const {return limit_;}
};
#endif //MOOP_ATM_PROJECT_SAVINGACCOUNT_H
