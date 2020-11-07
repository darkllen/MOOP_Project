#ifndef MOOP_ATM_PROJECT_BANK_H
#define MOOP_ATM_PROJECT_BANK_H

#include <string>

#include "../constants/ATMTypes.h"

class Account;
class DebitCard;
class Customer;

class Bank {
private:

    BANK_NUMBER_T id_;
    std::string address_;
    std::string name_;

public:
    Bank(BANK_NUMBER_T, std::string, std::string);
    ~Bank() = default;
    static DebitCard getCard(const CARD_NUMBER_T &);
    static Account* getAccount(const std::string&);
    static Account* getAccount(const CARD_NUMBER_T&);
    static Customer* getCustomer(const CARD_NUMBER_T&);

};

#endif //MOOP_ATM_PROJECT_BANK_H
