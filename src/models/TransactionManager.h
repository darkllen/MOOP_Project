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

    static OneTimeTransfer createTransaction(const QDateTime &, const Account &, const Account &, const CASH_AMOUNT_T &);
    static RegularTransfer createTransaction(const QDateTime &, const Account &, const Account &, const CASH_AMOUNT_T &, const int&);
    static CashTransaction createTransaction(const QDateTime &, const Account &, const ACCOUNT_BALANCE_AMOUNT_T &, const bool&);
    static AccountManaging createTransaction(const QDateTime &, const Account &,  const CARD_NUMBER_T & , const AccountManaging::ValueChanged &, const VAL&, const VAL&);
};

#endif //MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
