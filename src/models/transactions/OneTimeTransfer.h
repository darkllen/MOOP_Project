//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ONETIMETRANSFER_H
#define MOOP_ATM_PROJECT_ONETIMETRANSFER_H

#include <QtCore/qdatetime.h>

#include "Transaction.h"
#include "../../constants/ATMTypes.h"

class Account;
class OneTimeTransfer : public Transaction {
private:
    Account &to_;
    Account &from_;
    CASH_AMOUNT_T amount_;

public:

    OneTimeTransfer(const QDateTime &dateTime, Account &to, Account &from, CASH_AMOUNT_T amount) :
            Transaction(dateTime), to_(to), from_(from), amount_(amount) {}
    ~OneTimeTransfer() = default;
};

#endif //MOOP_ATM_PROJECT_ONETIMETRANSFER_H
