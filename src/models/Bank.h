#ifndef MOOP_ATM_PROJECT_BANK_H
#define MOOP_ATM_PROJECT_BANK_H

#include <string>

#include "../constants/ATMTypes.h"

class Account;
class DebitCard;

class Bank {
private:

    BANK_NUMBER_T id_;
    std::string address_;
    std::string name_;

public:
    //TODO DB add method getCard, getAccount
    Bank(BANK_NUMBER_T, std::string, std::string);
    ~Bank() = default;

    static PIN_T getCardPIN(const CARD_NUMBER_T &);
    static DebitCard getCard(const CARD_NUMBER_T &);
};

#endif //MOOP_ATM_PROJECT_BANK_H
