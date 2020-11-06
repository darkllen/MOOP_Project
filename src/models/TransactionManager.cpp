//
// Created by Lemonderon on 21.10.2020.
//

#include "TransactionManager.h"
#include "transactions/OneTimeTransfer.h"
#include "transactions/RegularTransfer.h"
#include "transactions/CashTransaction.h"
#include "transactions/AccountManaging.h"



const OneTimeTransfer &TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, const CASH_AMOUNT_T & amount) {
    return *(new OneTimeTransfer(date, to, from, amount));
}

const RegularTransfer &TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, const CASH_AMOUNT_T & amount, int reg) {
    return *(new RegularTransfer(date, to, from, amount, reg));
}

const CashTransaction &TransactionManager::createTransaction(const QDateTime & date, const Account & from, const ACCOUNT_BALANCE_AMOUNT_T & amount, bool isWithdrawal) {
    return *(new CashTransaction(date, from, amount, isWithdrawal));
}

const AccountManaging &TransactionManager::createTransaction(const QDateTime & date,const Account & from, const CARD_NUMBER_T & card_n, AccountManaging::ValueChanged valueType, unsigned __int64 oldValue, unsigned __int64 newValue) {
    return *(new AccountManaging(date, from, card_n, valueType, oldValue, newValue));

}
