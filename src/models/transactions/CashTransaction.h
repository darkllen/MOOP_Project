//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_CASHTRANSACTION_H
#define MOOP_ATM_PROJECT_CASHTRANSACTION_H

#include <QtCore/qdatetime.h>
#include "Transaction.h"
#include "../../constants/ATMTypes.h"

class CashTransaction : public Transaction {
private:

    ACCOUNT_BALANCE_AMOUNT_T amount_;
    bool isWithdrawal_;

public:

    CashTransaction(const QDateTime &dateTime, ACCOUNT_BALANCE_AMOUNT_T amount, bool isWithdrawal) :
            Transaction(dateTime), amount_(amount), isWithdrawal_(isWithdrawal) {}
    ~CashTransaction() = default;

    ACCOUNT_BALANCE_AMOUNT_T getAmount() const { return amount_; }
    bool getIsWithdrawal() const { return isWithdrawal_; }
};

#endif //MOOP_ATM_PROJECT_CASHTRANSACTION_H
