//
// Created by anna2 on 20.10.2020.
//

#include "Maintenance.h"
#include "../exceptions/ATMException.h"
#include "../models/atm_hardware/CardReader.h"
#include "../models/atm_hardware/Dispenser.h"

void Maintenance::putCash(Dispenser &dispenser, CASH_AMOUNT_T amount) {
    try {
        dispenser.cashIn(amount);
    } catch (const HardwareException &e) {
        //TODO: Trigger ui
    }
}

void Maintenance::takeCash(Dispenser & dispenser, CASH_AMOUNT_T amount) {
    try {
        dispenser.cashOut(amount);
    } catch (const HardwareException &e) {
        //TODO: Trigger ui
    }
}

bool Maintenance::checkStatus(const ATM::Hardware &h) {
    return h.getState();
}

void Maintenance::changeStatus(ATM::Hardware &h, bool isOperational) {
    h.setState(isOperational);
}