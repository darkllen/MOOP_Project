//
// Created by kuchm on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMCONTROLLER_H
#define MOOP_ATM_PROJECT_ATMCONTROLLER_H

#include "../mediator/ATMIO.h"

class ATMController: public ATMBaseComponent {
public:

    explicit ATMController() : ATMBaseComponent() {}
    virtual ~ATMController() {};

    virtual void dialPadInput(DialPadBtn btn) = 0;
    virtual void dialPadControlInput(ControlBtn btn) = 0;
    virtual void sideDisplayBtnInput(DisplaySideBtn btn) = 0;
    virtual void dispenserInput() = 0;
    virtual void cardReaderInput() = 0;
};


#endif //MOOP_ATM_PROJECT_ATMCONTROLLER_H
