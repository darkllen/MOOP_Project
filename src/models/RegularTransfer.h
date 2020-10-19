//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_REGULARTRANSFER_H
#define MOOP_ATM_PROJECT_REGULARTRANSFER_H


#include "OneTimeTransfer.h"

class Account;
class RegularTransfer: public OneTimeTransfer{
private:
    QDateTime& regularity_;

public:
    RegularTransfer(const QDateTime&, const Account&, const Account&, CASH_AMOUNT_T, const QDateTime&);
    ~RegularTransfer();
};

#endif //MOOP_ATM_PROJECT_REGULARTRANSFER_H
