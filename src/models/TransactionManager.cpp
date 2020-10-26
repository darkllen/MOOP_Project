//
// Created by Lemonderon on 21.10.2020.
//

#include "TransactionManager.h"
#include "transactions/OneTimeTransfer.h"
#include "transactions/RegularTransfer.h"
#include "transactions/CashTransaction.h"
#include "transactions/AccountManaging.h"



const Transaction &TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, int amount) {
    return *(new OneTimeTransfer(date, to, from, amount));
}

const Transaction &TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, int amount, int reg) {
    return *(new RegularTransfer(date, to, from, amount, reg));
}

const Transaction &TransactionManager::createTransaction(const QDateTime & date, const Account & from, int amount, bool isWithdrawal) {
    return *(new CashTransaction(date, from, amount, isWithdrawal));
}

const Transaction &TransactionManager::createTransaction(const QDateTime & date,const Account & from,  AccountManaging::ValueChanged valueType, unsigned __int64 oldValue, unsigned __int64 newValue) {
    return *(new AccountManaging(date, from, valueType, oldValue, newValue));
}
