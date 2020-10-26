#ifndef MOOP_ATM_PROJECT_ACCOUNT_H
#define MOOP_ATM_PROJECT_ACCOUNT_H

#include <string>
#include "../../constants/ATMTypes.h"

class Account {
private:
    std::string ownerName_;
    std::string IBAN_;
    BANK_NUMBER_T bank_;
public:
    Account(std::string ownerName, std::string IBAN, BANK_NUMBER_T bank_);
    ~Account() = default;

    BANK_NUMBER_T getBank() const;
    std::string getIBAN_() const;
};

#endif //MOOP_ATM_PROJECT_ACCOUNT_H
