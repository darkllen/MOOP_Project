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
        cardReader_(new CardReader),
        tsManager_(new TransactionManager),
        sessionManager_(new SessionManager) {
}

ATM::~ATM() {
    delete dispenser_;
    delete cardReader_;
    delete tsManager_;
    delete sessionManager_;
}

void ATM::powerOn() {
    if (!isPoweredOn_) {
        this->mediator_->
                Notify(ATMPowerStateEvent(ATMPowerStateEvent::PowerState::On, ATMEvent::Target::ATMIO));
        isPoweredOn_ = true;
    }
}

void ATM::powerOff() {
    if (isPoweredOn_) {
        this->mediator_->
                Notify(ATMPowerStateEvent(ATMPowerStateEvent::PowerState::Off, ATMEvent::Target::ATMIO));
        isPoweredOn_ = false;
    }
}

const ATMInfo &ATM::getATMInfo() const {
    return *atmInfo_;
}

CardReader& ATM::getCardReader() {
    return *cardReader_;
}

Dispenser& ATM::getDispenser() {
    return *dispenser_;
}
void ATM::setMediator(ATMMediator *mediator) {
    this->mediator_ = mediator;
    this->dispenser_->setMediator(mediator);
    this->cardReader_->setMediator(mediator);
}
