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
    static const Transaction &createTransaction(const QDateTime &, const Account &, const Account &, int, const QDateTime &);
    static const Transaction &createTransaction(const QDateTime &, int, bool);
    static const Transaction &createTransaction(const QDateTime &, AccountManaging::ValueChanged, int, int);
};

#endif //MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
