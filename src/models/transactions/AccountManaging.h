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

    //TODO add field with ValueChanged type and field with DebitCard number
    unsigned __int64 oldValue_;
    unsigned __int64 newValue_;

public:
    enum ValueChanged {
        PIN,
    };

    AccountManaging(const QDateTime &dateTime,const Account& from, ValueChanged v, unsigned __int64& oldV, unsigned __int64& newV) :
            Transaction(dateTime,from), oldValue_(oldV), newValue_(newV) {}

    ~AccountManaging() = default;
};

#endif //MOOP_ATM_PROJECT_ACCOUNTMANAGING_H
