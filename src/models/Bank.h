#ifndef MOOP_ATM_PROJECT_BANK_H
#define MOOP_ATM_PROJECT_BANK_H

#include <string>

#include "../constants/ATM_Types.h"

class Account;

class DebitCard;

class Bank {
private:
    BANK_NUMBER_T id_;
    std::string address_;
    std::string name_;
public:
    Bank(unsigned int, std::string, std::string);
    ~Bank();
    static Account getCardAccount(const DebitCard &);
};

#endif //MOOP_ATM_PROJECT_BANK_H
