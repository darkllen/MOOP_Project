//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ACCOUNTMANAGING_H
#define MOOP_ATM_PROJECT_ACCOUNTMANAGING_H

#include <QtCore/qdatetime.h>

#include "Transaction.h"

class AccountManaging : public Transaction {
private:

    //TODO: decide proper type handling
    unsigned __int64 oldValue_;
    unsigned __int64 newValue_;

public:
    enum ValueChanged {
        PIN,
    };

    AccountManaging(const QDateTime &dateTime, ValueChanged, unsigned __int64, unsigned __int64) :
            Transaction(dateTime), oldValue_(0), newValue_(0) {}

    ~AccountManaging() = default;
};

#endif //MOOP_ATM_PROJECT_ACCOUNTMANAGING_H
