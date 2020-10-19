#ifndef MOOP_ATM_PROJECT_ACCOUNT_H
#define MOOP_ATM_PROJECT_ACCOUNT_H

#include <string>
#include "../constants/ATM_Types.h"

class Account {
private:
    std::string ownerName_;
    std::string IBAN_;
public:
    Account(const std::string &, const std::string &);
    ~Account();
    PIN_T getCardPIN();
    BANK_NUMBER_T getBank();
};

#endif //MOOP_ATM_PROJECT_ACCOUNT_H
