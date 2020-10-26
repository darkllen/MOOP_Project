#ifndef MOOP_ATM_PROJECT_CHECKINGACCOUNT_H
#define MOOP_ATM_PROJECT_CHECKINGACCOUNT_H

#include <string>
#include "Account.h"

class Account;

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string & ownerName, const std::string & IBAN, const BANK_NUMBER_T& bankNumberT, const CASH_AMOUNT_T& money) : Account(ownerName, IBAN, bankNumberT, money) {}
    ~CheckingAccount() = default;
};

#endif // MOOP_ATM_PROJECT_CHECKINGACCOUNT_H
