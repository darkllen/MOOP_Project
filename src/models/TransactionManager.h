//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
#define MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H

#include <QtCore/qdatetime.h>

#include "transactions/AccountManaging.h"

class Account;
class Transaction;

class TransactionManager {
private:

public:
    TransactionManager() = default;
    ~TransactionManager() = default;

    static const Transaction &createTransaction(const QDateTime &, const Account &, const Account &, int);
    static const Transaction &createTransaction(const QDateTime &, const Account &, const Account &, int, int);
    static const Transaction &createTransaction(const QDateTime &, const Account &, int, bool);
    static const Transaction &createTransaction(const QDateTime &, const Account &, AccountManaging::ValueChanged, unsigned __int64, unsigned __int64);
};

#endif //MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
