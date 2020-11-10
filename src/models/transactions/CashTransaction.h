//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_CASHTRANSACTION_H
#define MOOP_ATM_PROJECT_CASHTRANSACTION_H

#include <QtCore/qdatetime.h>
#include <QtCore/qlocale.h>
#include "Transaction.h"
#include "../../constants/ATMTypes.h"
#include "../models/accounts/Account.h"

class CashTransaction : public Transaction {
private:

    ACCOUNT_BALANCE_AMOUNT_T amount_;
    bool isWithdrawal_;

public:

    CashTransaction(const QDateTime &dateTime, const Account &from, const ACCOUNT_BALANCE_AMOUNT_T &amount, const bool &isWithdrawal) :
            Transaction(dateTime, from), amount_(amount), isWithdrawal_(isWithdrawal) {}
    ~CashTransaction() = default;

    ACCOUNT_BALANCE_AMOUNT_T getAmount() const { return amount_; }
    bool getIsWithdrawal() const { return isWithdrawal_; }

    QString print() const override {
        QLocale ukr(QLocale::Ukrainian, QLocale::Ukraine);
        QString res = "Time and date: " + ukr.toString(getTime(),"HH:mm dd.MM.yyyy") + "\n";
        res += getFrom().print() + "\n";
        if (isWithdrawal_) {
            res += "Cash withdrawal of -" + QString::number(amount_) + "$";
        } else {
            res += "Amount of cash put is " + QString::number(amount_) + "$";
        }
        return res;
    }
};

#endif //MOOP_ATM_PROJECT_CASHTRANSACTION_H
