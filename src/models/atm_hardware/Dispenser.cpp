//
// Created by Lemonderon on 20.10.2020.
//
#include "Dispenser.h"

#include "../../constants/ATMLimits.h"
#include "../../exceptions/ATMException.h"
#include "../../models/ATMInfo.h"
#include "../../controllers/DBConnection.h"

Dispenser::Dispenser(ATM& atm, const CASH_AMOUNT_T& amount, const bool& isOp): Hardware(atm, isOp), availableCash_(amount) {
    if (amount >= ATMLimits::MAX_CASH_AMOUNT_IN_DISPENSER) {
        throw HardwareException("More cash then dispenser can handle");
    }
}

void Dispenser::cashIn(const CASH_AMOUNT_T& amount) {
    if (availableCash_ + amount >= ATMLimits::MAX_CASH_AMOUNT_IN_DISPENSER) {
        throw HardwareException("More cash then dispenser can handle");
    }

    availableCash_ += amount;
    DBConnection connection;
    mysqlx::Table atmInfo = connection.getTable("ATMInfo");

    atmInfo.update().set("availableCashAmount_", availableCash_).where("serialNumber_ like :serialNumber_").bind("serialNumber_", parent_.getATMInfo().getSerialNumber()).execute();

}

void Dispenser::cashOut(const CASH_AMOUNT_T& amount) {
    if (availableCash_ < amount){
        throw HardwareException("Not enough cash left in dispenser");
    }
    availableCash_ -= amount;
    DBConnection connection;
    mysqlx::Table atmInfo = connection.getTable("ATMInfo");
    atmInfo.update().set("availableCashAmount_", availableCash_).where("serialNumber_ like :serialNumber_").bind("serialNumber_", parent_.getATMInfo().getSerialNumber()).execute();
}

void Dispenser::setState(const bool& isOp) {
    isOperational_ = isOp ;
    DBConnection connection;
    mysqlx::Table atmInfo = connection.getTable("ATMInfo");
    atmInfo.update().set("dispenserState", isOperational_).
            where("serialNumber_ like :serialNumber_").
            bind("serialNumber_", parent_.getATMInfo().getSerialNumber()).execute();
}



