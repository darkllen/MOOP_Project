//
// Created by kuchm on 04.10.2020.
//
#include "ATM.h"
#include "atm_hardware/CardReader.h"
#include "atm_hardware/Dispenser.h"
#include "TransactionManager.h"
#include "ATMInfo.h"
#include "../controllers/DBConnection.h"

ATM::ATM(const ATMInfo &atmInfo, const CASH_AMOUNT_T &initialCash, const bool &cardReaderState, const bool &dispenserState) :
        ATMBaseComponent(),
        atmInfo_(&atmInfo),
        dispenser_(new Dispenser(*this, initialCash, dispenserState)),
        cardReader_(new CardReader(*this, cardReaderState)),
        tsManager_(new TransactionManager) {
}


ATM::~ATM() {
    delete dispenser_;
    delete cardReader_;
    delete tsManager_;
}

const ATMInfo &ATM::getATMInfo() const {
    return *atmInfo_;
}

CardReader &ATM::getCardReader() {
    return *cardReader_;
}

Dispenser &ATM::getDispenser() {
    return *dispenser_;
}

void ATM::powerStateChange(ATMPowerState state) {
    switch (state) {
        case On: {
            mediator_->Notify(*this, EventToATMController::ATMPowerStateEvent(ATMPowerState::On));
            break;
        }
        case Off: {
            mediator_->Notify(*this, EventToATMController::ATMPowerStateEvent(ATMPowerState::Off));
            break;
        }
    }
}

ATM ATM::getATM(const ATM_SERIAL_NUMBER_T &num) {
    DBConnection connection;
    mysqlx::Table myTable = connection.getTable("ATMInfo");
    mysqlx::RowResult myResult = myTable.select("location_", "availableCashAmount_", "cardReaderState", "dispenserState")
            .where("serialNumber_ like :serialNumber_")
            .bind("serialNumber_", num).execute();

    mysqlx::Row row = myResult.fetchOne();
    std::stringstream s;
    s << row[0];
    CASH_AMOUNT_T cash(row[1].get<int>());
    bool cardReaderState(row[2].get<bool>());
    bool dispenserState(row[3].get<bool>());

    std::string ad(s.str());
    auto *inf = new ATMInfo(num, ad);
    return ATM(*inf, cash, cardReaderState, dispenserState);
}

bool ATM::getCardReaderStatus() {
    return cardReader_->getState();
}

void ATM::setCardReaderStatus(const bool &b) {
    cardReader_->setState(b);
}

bool ATM::getDispenserStatus() {
    return dispenser_->getState();
}

void ATM::setDispenserStatus(const bool &b) {
    dispenser_->setState(b);
}

void ATM::resetCardReader() {
    cardReader_->reset();
}





