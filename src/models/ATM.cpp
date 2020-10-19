//
// Created by kuchm on 04.10.2020.
//

#include "ATM.h"

ATM::ATM() : _isPoweredOn(false) {}

void ATM::powerOn() {
    if (!_isPoweredOn) {
//  TODO: implement properly
//  this->mediator_->Notify(this, );
        _isPoweredOn = true;
    }
}

void ATM::powerOff() {
    if (_isPoweredOn) {
//  TODO: implement properly
//  this->mediator_->Notify(this, );
        _isPoweredOn = false;
    }
}

