//
// Created by Lemonderon on 21.10.2020.
//

#include "TransactionManager.h"
#include "accounts/CheckingAccount.h"
#include "accounts/SavingAccount.h"
#include "../exceptions/ATMException.h"

const OneTimeTransfer &TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, const CASH_AMOUNT_T & amount) {
    if (const auto* t = dynamic_cast<const CheckingAccount*>(&from)){
        return *(new OneTimeTransfer(date, to, from, amount));
    } else  if (const auto* t = dynamic_cast<const SavingAccount*>(&from)){
        if(t->getMoney() >= t->getLimit() + amount)
            return *(new OneTimeTransfer(date, to, from, amount));
         else
            throw TransactionException("You can't take this amount of money because of card limit");
    } else throw TransactionException("Wrong account type");

}

const RegularTransfer &TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, const CASH_AMOUNT_T & amount, const int& reg) {
    if (const auto* t = dynamic_cast<const CheckingAccount*>(&from)){
        return *(new RegularTransfer(date, to, from, amount, reg));
    } else  if (const auto* t = dynamic_cast<const SavingAccount*>(&from)){
        if(t->getMoney() >= t->getLimit() + amount)
            return *(new RegularTransfer(date, to, from, amount, reg));
        else
            throw TransactionException("You can't take this amount of money because of card limit");
    } else throw TransactionException("Wrong account type");

}

const CashTransaction &TransactionManager::createTransaction(const QDateTime & date, const Account & from, const ACCOUNT_BALANCE_AMOUNT_T & amount, const bool& isWithdrawal) {
    if (const auto* t = dynamic_cast<const CheckingAccount*>(&from)){
        return *(new CashTransaction(date, from, amount, isWithdrawal));
    } else  if (const auto* t = dynamic_cast<const SavingAccount*>(&from)){
        if (((isWithdrawal)&&(t->getMoney() >= t->getLimit() + amount))||(!isWithdrawal))
            return *(new CashTransaction(date, from, amount, isWithdrawal));
        else
            throw TransactionException("You can`t take this amount of money because of card limit");
    } else throw TransactionException("Wrong account type");

    }

const AccountManaging &TransactionManager::createTransaction(const QDateTime & date,const Account & from, const CARD_NUMBER_T & card_n, const AccountManaging::ValueChanged& valueType, const VAL& oldValue, const VAL& newValue) {
    return *(new AccountManaging(date, from, card_n, valueType, oldValue, newValue));
}
