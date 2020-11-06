//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
#define MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H

#include <QtCore/qdatetime.h>

#include "transactions/AccountManaging.h"
#include "transactions/CashTransaction.h"
#include "transactions/OneTimeTransfer.h"
#include "transactions/RegularTransfer.h"

#include "../constants/ATMTypes.h"

class Account;
class Transaction;

class TransactionManager {
private:

public:
    TransactionManager() = default;
    ~TransactionManager() = default;

    static const OneTimeTransfer &createTransaction(const QDateTime &, const Account &, const Account &, const CASH_AMOUNT_T &);
    static const RegularTransfer &createTransaction(const QDateTime &, const Account &, const Account &, const CASH_AMOUNT_T &, int);
    static const CashTransaction &createTransaction(const QDateTime &, const Account &, const ACCOUNT_BALANCE_AMOUNT_T &, bool);
    static const AccountManaging &createTransaction(const QDateTime &, const Account &,  const CARD_NUMBER_T & , AccountManaging::ValueChanged, unsigned __int64, unsigned __int64);
};

#endif //MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
