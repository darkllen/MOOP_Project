//
// Created by kuchm on 04.10.2020.
//

#include "ATM.h"

ATM::ATM(const ATMInfo &atmInfo, unsigned __int32 initialCash) :
        isPoweredOn_(false),
        atmInfo_(&atmInfo),
        dispenser_(new Dispenser(initialCash)),
        cardReader_(new CardReader),
        tsManager_(new TransactionManager),
        sessionManager_(new SessionManager) {}

void ATM::powerOn() {
    if (!isPoweredOn_) {
//  TODO: implement properly
//  this->mediator_->Notify(this, );
        isPoweredOn_ = true;
    }
}

void ATM::powerOff() {
    if (isPoweredOn_) {
//  TODO: implement properly
//  this->mediator_->Notify(this, );
        isPoweredOn_ = false;
    }
}
ATM::~ATM() {
    delete dispenser_;
    delete cardReader_;
    delete tsManager_;
    delete sessionManager_;
}

const ATMInfo& ATM::getATMInfo(){
    return atmInfo_;
}


