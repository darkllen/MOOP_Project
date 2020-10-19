//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTION_H
#define MOOP_ATM_PROJECT_TRANSACTION_H

#include <QtCore/qdatetime.h>

class Transaction{
private:
    QDateTime _time;
public:
    Transaction(const QDateTime&);
    ~Transaction();

};
#endif //MOOP_ATM_PROJECT_TRANSACTION_H
