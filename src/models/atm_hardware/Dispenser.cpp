//
// Created by Lemonderon on 20.10.2020.
//

#include "Dispenser.h"

#include "../../constants/ATMLimits.h"
#include "../../exceptions/ATMException.h"

Dispenser::Dispenser(ATM& atm,CASH_AMOUNT_T amount): Hardware(atm), availableCash_(amount) {
    if (amount >= ATMLimits::MAX_CASH_AMOUNT_IN_DISPENSER) {
        throw HardwareException("More cash then dispenser can handle");
    }
}

void Dispenser::cashIn(CASH_AMOUNT_T amount) {
    if (availableCash_ + amount >= ATMLimits::MAX_CASH_AMOUNT_IN_DISPENSER) {
        throw HardwareException("More cash then dispenser can handle");
    }
    availableCash_ += amount;
}

void Dispenser::cashOut(CASH_AMOUNT_T amount) {
    if (availableCash_ - amount < 0){
        throw HardwareException("Not enough cash left in dispenser");
    }
    availableCash_ -= amount;
}

