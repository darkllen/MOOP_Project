#ifndef MOOP_ATM_PROJECT_CHECKINGACCOUNT_H
#define MOOP_ATM_PROJECT_CHECKINGACCOUNT_H

#include <string>
#include "Account.h"

class Account;

class CheckingAccount : public Account {
public:
    CheckingAccount(const int & ownerId, const std::string & IBAN, const BANK_NUMBER_T& bankNumberT, const ACCOUNT_BALANCE_AMOUNT_T& money) : Account(ownerId, IBAN, bankNumberT, money) {}
};

#endif // MOOP_ATM_PROJECT_CHECKINGACCOUNT_H
