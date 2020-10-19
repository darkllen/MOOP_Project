#ifndef MOOP_ATM_PROJECT_ACCOUNT_H
#define MOOP_ATM_PROJECT_ACCOUNT_H

#include <string>

class Account {
private:
    std::string ownerName_;
    std::string IBAN_;
public:
    Account(const std::string &, const std::string &);
    ~Account();
    unsigned __int64 getCardPIN();
    unsigned __int64 getBank();
};

#endif //MOOP_ATM_PROJECT_ACCOUNT_H
