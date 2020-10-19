//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTIONEXCEPTION_H
#define MOOP_ATM_PROJECT_TRANSACTIONEXCEPTION_H

#include <string>

#include "ATMException.h"


class TransactionException : public ATMException {
public:
    TransactionException(std::string);
    ~TransactionException();
};

#endif //MOOP_ATM_PROJECT_TRANSACTIONEXCEPTION_H
