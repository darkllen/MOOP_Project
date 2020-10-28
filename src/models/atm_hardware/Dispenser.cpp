//
// Created by Lemonderon on 20.10.2020.
//

#include "Dispenser.h"

#include "../../constants/ATMLimits.h"

Dispenser::Dispenser(CASH_AMOUNT_T amount): Hardware(), availableCash_(amount) {
    if (amount >= ATMLimits::MAX_CASH_AMOUNT_IN_DISPENSER) {
        //TODO: Requires implementation
    }
}

void Dispenser::cashIn(CASH_AMOUNT_T amount) {
    if (availableCash_ + amount >= ATMLimits::MAX_CASH_AMOUNT_IN_DISPENSER) {
        //TODO: Requires implementation
    }
    availableCash_ += amount;
}

void Dispenser::cashOut(CASH_AMOUNT_T amount) {
    if (availableCash_ - amount < 0){
        //TODO: Requires implementation
    }
    availableCash_ -= amount;
}

