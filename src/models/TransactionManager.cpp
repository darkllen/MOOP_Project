//
// Created by Lemonderon on 21.10.2020.
//

#include "TransactionManager.h"
#include "accounts/CheckingAccount.h"
#include "accounts/SavingAccount.h"
#include "../exceptions/ATMException.h"

OneTimeTransfer TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, const CASH_AMOUNT_T & amount) {
    if (const auto* t = dynamic_cast<const CheckingAccount*>(&from)){
        return OneTimeTransfer(date, to, from, amount);
    } else  if (const auto* t = dynamic_cast<const SavingAccount*>(&from)){
        if(t->getMoney() >= t->getLimit() + amount)
            return OneTimeTransfer(date, to, from, amount);
         else
            throw TransactionException("You can't take this amount of money because of card limit");
    } else throw TransactionException("Wrong account type");

}

RegularTransfer TransactionManager::createTransaction(const QDateTime & date, const Account & to, const Account & from, const CASH_AMOUNT_T & amount, const int& reg) {
    if (const auto* t = dynamic_cast<const CheckingAccount*>(&from)){
        return RegularTransfer(date, to, from, amount, reg);
    } else  if (const auto* t = dynamic_cast<const SavingAccount*>(&from)){
        if(t->getMoney() >= t->getLimit() + amount)
            return RegularTransfer(date, to, from, amount, reg);
        else
            throw TransactionException("You can't take this amount of money because of card limit");
    } else throw TransactionException("Wrong account type");
}

CashTransaction TransactionManager::createTransaction(const QDateTime & date, const Account & from, const ACCOUNT_BALANCE_AMOUNT_T & amount, const bool& isWithdrawal) {
    if (const auto* t = dynamic_cast<const CheckingAccount*>(&from)){
        return CashTransaction(date, from, amount, isWithdrawal);
    } else  if (const auto* t = dynamic_cast<const SavingAccount*>(&from)){
        if (((isWithdrawal)&&(t->getMoney() >= t->getLimit() + amount))||(!isWithdrawal))
            return CashTransaction(date, from, amount, isWithdrawal);
        else
            throw TransactionException("You can`t take this amount of money because of card limit");
    } else throw TransactionException("Wrong account type");

    }

AccountManaging TransactionManager::createTransaction(const QDateTime & date,const Account & from, const CARD_NUMBER_T & card_n, const AccountManaging::ValueChanged& valueType, const VAL& oldValue, const VAL& newValue) {
    return AccountManaging(date, from, card_n, valueType, oldValue, newValue);
}
