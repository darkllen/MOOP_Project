//
// Created by kuchm on 04.10.2020.
//

#include "ATM.h"
#include "../events/ATMEvent.h"

ATM::ATM(const ATMInfo &atmInfo, unsigned __int32 initialCash) :
        ATMBaseComponent(),
        isPoweredOn_(false),
        atmInfo_(&atmInfo),
        dispenser_(new Dispenser(initialCash)),
        cardReader_(new CardReader(*this)),
        tsManager_(new TransactionManager),
        sessionManager_(new SessionManager) {
}

ATM::~ATM() {
    delete dispenser_;
    delete cardReader_;
    delete tsManager_;
    delete sessionManager_;
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
void ATM::setMediator(ATMMediator *mediator) {
    this->mediator_ = mediator;
    this->dispenser_->setMediator(mediator);
    this->cardReader_->setMediator(mediator);
}

void ATM::powerStateChange(ATMPowerState state) {
    switch (state) {
        case On: {
            isPoweredOn_ = true;
            mediator_->Notify(*this, EventToATMController::ATMPowerStateEvent(ATMPowerState::On));
            break;
        }
        case Off: {
            isPoweredOn_ = false;
            mediator_->Notify(*this, EventToATMController::ATMPowerStateEvent(ATMPowerState::Off));
            break;
        }
    }
}

