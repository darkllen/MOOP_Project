//
// Created by Lemonderon on 20.10.2020.
//
#include <mysqlx/xdevapi.h>
#include "Dispenser.h"

#include "../../constants/ATMLimits.h"
#include "../../exceptions/ATMException.h"
#include "../../models/ATMInfo.h"

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

    const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
    mysqlx::Session session(url);
    mysqlx::Schema db = session.getSchema("moop");
    mysqlx::Table atmInfo = db.getTable("ATMInfo");

    atmInfo.update().set("availableCashAmount_", availableCash_).where("serialNumber_ like :serialNumber_").bind("serialNumber_", parent_.getATMInfo().getSerialNumber()).execute();

}

void Dispenser::cashOut(const CASH_AMOUNT_T& amount) {
    if (availableCash_ < amount){
        throw HardwareException("Not enough cash left in dispenser");
    }
    availableCash_ -= amount;

    const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
    mysqlx::Session session(url);
    mysqlx::Schema db = session.getSchema("moop");
    mysqlx::Table atmInfo = db.getTable("ATMInfo");
    atmInfo.update().set("availableCashAmount_", availableCash_).where("serialNumber_ like :serialNumber_").bind("serialNumber_", parent_.getATMInfo().getSerialNumber()).execute();
}

void Dispenser::setState(const bool& isOp) {
    isOperational_ = isOp ;
    const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
    mysqlx::Session session(url);
    mysqlx::Schema db = session.getSchema("moop");
    mysqlx::Table atmInfo = db.getTable("ATMInfo");


    atmInfo.update().set("dispenserState", isOperational_).
            where("serialNumber_ like :serialNumber_").
            bind("serialNumber_", parent_.getATMInfo().getSerialNumber()).execute();
}



