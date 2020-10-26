//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_REGULARTRANSFER_H
#define MOOP_ATM_PROJECT_REGULARTRANSFER_H


#include "OneTimeTransfer.h"

class RegularTransfer : public OneTimeTransfer {
private:

    int regularity_;

public:
    RegularTransfer(const QDateTime &dateTime, const Account &to, const Account &from, CASH_AMOUNT_T amount, int regularity) :
            OneTimeTransfer(dateTime, to, from, amount), regularity_(regularity) {}
    ~RegularTransfer() = default;
};

#endif //MOOP_ATM_PROJECT_REGULARTRANSFER_H
