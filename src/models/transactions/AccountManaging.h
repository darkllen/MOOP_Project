//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ACCOUNTMANAGING_H
#define MOOP_ATM_PROJECT_ACCOUNTMANAGING_H

#include <QtCore/qdatetime.h>
#include "Transaction.h"
#include "../../constants/ATMTypes.h"

class AccountManaging : public Transaction {


public:
    enum ValueChanged {
        PIN,
    };

    ValueChanged getValueType() const { return v_; }
    CARD_NUMBER_T getCardNum() const { return card_n_; }
    CARD_NUMBER_T getOldValue() const { return oldValue_; }
    CARD_NUMBER_T getNewValue() const { return newValue_; }

    AccountManaging(
            const QDateTime &dateTime, const Account &from, const CARD_NUMBER_T &card_n,
            ValueChanged v, unsigned __int64 &oldV, unsigned __int64 &newV
    ) : Transaction(dateTime, from), card_n_(card_n), v_(v), oldValue_(oldV), newValue_(newV) {}

    ~AccountManaging() = default;
private:

    //TODO: decide proper type handling
    unsigned __int64 oldValue_;
    unsigned __int64 newValue_;
    ValueChanged v_;
    CARD_NUMBER_T card_n_;
};

#endif //MOOP_ATM_PROJECT_ACCOUNTMANAGING_H
