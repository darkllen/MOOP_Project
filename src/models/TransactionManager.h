//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
#define MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H

#include <QtCore/qdatetime.h>


#include "AccountManaging.h"

class Account;

class Transaction;

class TransactionManager {
private:

public:
    TransactionManager();
    ~TransactionManager();

    const Transaction &createTransaction(const QDateTime &, const Account &, const Account &, int);
    const Transaction &createTransaction(const QDateTime &, const Account &, const Account &, int, const Date &);
    const Transaction &createTransaction(const QDateTime &, int, bool);
    const Transaction &createTransaction(const QDateTime &, AccountManaging::ValueChanged, int, int);

};

#endif //MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
