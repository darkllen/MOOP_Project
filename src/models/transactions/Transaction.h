//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTION_H
#define MOOP_ATM_PROJECT_TRANSACTION_H

#include <QtCore/qdatetime.h>

class Transaction {
private:

    QDateTime time_;

public:
    explicit Transaction(QDateTime time) : time_(std::move(time)) {}
    ~Transaction() = default;
};
#endif //MOOP_ATM_PROJECT_TRANSACTION_H
