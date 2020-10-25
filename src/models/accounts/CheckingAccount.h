#ifndef MOOP_ATM_PROJECT_CHECKINGACCOUNT_H
#define MOOP_ATM_PROJECT_CHECKINGACCOUNT_H

#include <string>
#include "Account.h"

class Account;

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string &, const std::string &) : Account("", "") {}
    ~CheckingAccount() = default;
};

#endif // MOOP_ATM_PROJECT_CHECKINGACCOUNT_H
