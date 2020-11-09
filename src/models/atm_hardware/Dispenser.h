//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_DISPENSER_H
#define MOOP_ATM_PROJECT_DISPENSER_H

#include "Hardware.h"

class Dispenser : public ATM::Hardware {
private:
    CASH_AMOUNT_T availableCash_;

public:
    explicit Dispenser(ATM &, CASH_AMOUNT_T = 0, bool isOp = true);
    ~Dispenser() override = default;

    CASH_AMOUNT_T getAvailableCashAmount() const { return availableCash_; }

    void cashIn(CASH_AMOUNT_T);
    void cashOut(CASH_AMOUNT_T);
    void setState(bool isOp) override;
};


#endif //MOOP_ATM_PROJECT_DISPENSER_H
