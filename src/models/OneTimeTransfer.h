//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ONETIMETRANSFER_H
#define MOOP_ATM_PROJECT_ONETIMETRANSFER_H

#include <QtCore/qdatetime.h>

#include "Transaction.h"
#include "../constants/ATM_Types.h"

class Account;
class OneTimeTransfer: public Transaction{
private:
    Account& to_;
    Account& from_;
    CASH_AMOUNT_T amount_;

public:
    OneTimeTransfer(const QDateTime&, const Account&, const Account&, CASH_AMOUNT_T);
    ~OneTimeTransfer();
};

#endif //MOOP_ATM_PROJECT_ONETIMETRANSFER_H
