#ifndef MOOP_ATM_PROJECT_ACCOUNT_H
#define MOOP_ATM_PROJECT_ACCOUNT_H

#include <string>
#include <QtCore/QString>
#include "../../constants/ATMTypes.h"

class Account {
private:
    int ownerId_;
    std::string IBAN_;
    BANK_NUMBER_T bank_;
    CASH_AMOUNT_T money_;
public:
    Account(int ownerId, std::string IBAN, const BANK_NUMBER_T &bank_, const ACCOUNT_BALANCE_AMOUNT_T &);
    virtual ~Account() = default;

    BANK_NUMBER_T getBank() const;
    std::string getIBAN_() const;

    CASH_AMOUNT_T getMoney() const;
    void setMoney(const CASH_AMOUNT_T &);

    int getOwnerId() const { return ownerId_; }

    QString print() const {
        return QString("Account:\n\t\tIBAN: " + QString(IBAN_.c_str()) + "\n\t\tBank: " + QString::number(bank_));
    }
};

#endif //MOOP_ATM_PROJECT_ACCOUNT_H
