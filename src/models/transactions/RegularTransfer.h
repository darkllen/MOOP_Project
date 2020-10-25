//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_REGULARTRANSFER_H
#define MOOP_ATM_PROJECT_REGULARTRANSFER_H


#include "OneTimeTransfer.h"

class RegularTransfer : public OneTimeTransfer {
private:

    QDateTime regularity_;

public:
    RegularTransfer(const QDateTime &dateTime, const Account &to, const Account &from, CASH_AMOUNT_T amount, QDateTime regularity) :
            OneTimeTransfer(dateTime, to, from, amount), regularity_(std::move(regularity)) {}
    ~RegularTransfer() = default;
};

#endif //MOOP_ATM_PROJECT_REGULARTRANSFER_H
