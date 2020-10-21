//
// Created by anna2 on 20.10.2020.
//

#include "Maintenance.h"
#include "../models/ATM.h"
#include "../exceptions/ATMException.h"

void Maintenance::putCash(Dispenser &dispenser, CASH_AMOUNT_T amount) {
    try {
        dispenser.cashIn(amount);
    } catch (const HardwareException &e) {
        //TODO: Requires implementation
    }
}

void Maintenance::takeMoney(Dispenser &dispenser, CASH_AMOUNT_T amount) {
    try {
        dispenser.cashOut(amount);
    } catch (const HardwareException &e) {
        //TODO: Requires implementation
    }
}

bool Maintenance::checkStatus(const Hardware &h) {
    return h.getState();
}

void Maintenance::changeStatus(Hardware &h, bool isOperational) {
    h.setState(isOperational);
}