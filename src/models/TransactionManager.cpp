//
// Created by Lemonderon on 21.10.2020.
//

#include "TransactionManager.h"

const Transaction &TransactionManager::createTransaction(const QDateTime &, const Account &, const Account &, int) {
    //TODO: Requires implementation
    return *(new Transaction(QDateTime::currentDateTime()));
}

const Transaction &TransactionManager::createTransaction(const QDateTime &, const Account &, const Account &, int, const QDateTime &) {
    //TODO: Requires implementation
    return *(new Transaction(QDateTime::currentDateTime()));
}

const Transaction &TransactionManager::createTransaction(const QDateTime &, int, bool) {
    //TODO: Requires implementation
    return *(new Transaction(QDateTime::currentDateTime()));
}

const Transaction &TransactionManager::createTransaction(const QDateTime &, AccountManaging::ValueChanged, int, int) {
    //TODO: Requires implementation
    return *(new Transaction(QDateTime::currentDateTime()));
}
