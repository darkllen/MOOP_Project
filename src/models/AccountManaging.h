//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ACCOUNTMANAGING_H
#define MOOP_ATM_PROJECT_ACCOUNTMANAGING_H

#include <QtCore/qdatetime.h>

#include "transactions/Transaction.h"

class AccountManaging : public Transaction {
private:

    int oldValue_;
    int newValue_;

public:
    enum ValueChanged {
        PIN,
    };

    AccountManaging(const QDateTime &dateTime, ValueChanged, int, int) :
            Transaction(dateTime), oldValue_(0),
            newValue_(0) {}

    ~AccountManaging() = default;
};

#endif //MOOP_ATM_PROJECT_ACCOUNTMANAGING_H
