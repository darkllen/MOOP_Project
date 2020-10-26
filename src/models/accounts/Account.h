#ifndef MOOP_ATM_PROJECT_ACCOUNT_H
#define MOOP_ATM_PROJECT_ACCOUNT_H

#include <string>
#include "../../constants/ATMTypes.h"

class Account {
private:
    std::string ownerName_;
    std::string IBAN_;
    BANK_NUMBER_T bank_;
    CASH_AMOUNT_T money_;
public:
    Account(std::string ownerName, std::string IBAN, const BANK_NUMBER_T& bank_, const CASH_AMOUNT_T&);
    ~Account() = default;

    BANK_NUMBER_T getBank() const;
    std::string getIBAN_() const;

    CASH_AMOUNT_T getMoney() const;
};

#endif //MOOP_ATM_PROJECT_ACCOUNT_H
