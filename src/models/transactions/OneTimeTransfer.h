//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ONETIMETRANSFER_H
#define MOOP_ATM_PROJECT_ONETIMETRANSFER_H

#include <QtCore/qdatetime.h>
#include <QtCore/qlocale.h>

#include "Transaction.h"
#include "../../constants/ATMTypes.h"

class Account;
class OneTimeTransfer : public Transaction {
private:
    const Account &to_;
    CASH_AMOUNT_T amount_;

public:
    OneTimeTransfer(const QDateTime &dateTime, const Account &to, const Account &from, const CASH_AMOUNT_T &amount) :
            Transaction(dateTime, from), to_(to), amount_(amount) {}
    ~OneTimeTransfer() = default;
    CASH_AMOUNT_T getAmount() const { return amount_; };
    const Account &getTo() const { return to_; };

    QString print() const override {
        QLocale ukr(QLocale::Ukrainian, QLocale::Ukraine);
        QString res = "Time and date: " + ukr.toString(getTime(), "HH:mm dd.MM.yyyy") + "\n";
        res += "From " + getFrom().print() + "\n";
        res += "To " + to_.print() + "\n";
        res += "Transferred " + QString::number(amount_) + "$";
        return res;
    }
};


#endif //MOOP_ATM_PROJECT_ONETIMETRANSFER_H
