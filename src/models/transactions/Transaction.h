//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTION_H
#define MOOP_ATM_PROJECT_TRANSACTION_H

#include <QtCore/qdatetime.h>

class Account;
class Transaction {
private:
    QDateTime time_;
    const Account &from_;

protected:
    const QDateTime &getTime() const {
        return time_;
    }

    const Account &getFrom() const {
        return from_;
    }

public:
    explicit Transaction(QDateTime time, const Account &from_) : time_(std::move(time)), from_(from_) {}
    virtual ~Transaction() = default;

    virtual QString print() const = 0;
};
#endif //MOOP_ATM_PROJECT_TRANSACTION_H
