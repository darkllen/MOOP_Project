//
// Created by kuchm on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMCONTROLLER_H
#define MOOP_ATM_PROJECT_ATMCONTROLLER_H

#include "../mediators/ATMIO.h"
#include "../events/UIInput.h"
#include "../events/ATMEvent.h"


class ATMController: public ATMBaseComponent {
public:
    explicit ATMController(): ATMBaseComponent() {}
    virtual ~ATMController() {};

    virtual void dialPadInput(UIInput::DialPadBtnInput) = 0;
    virtual void dialPadControlInput(UIInput::ControlBtnInput) = 0;
    virtual void sideDisplayBtnInput(UIInput::DisplaySideBtnInput) = 0;
    virtual void dispenserInput() = 0;
    virtual void cardReaderInput() = 0;
    virtual void ATMPowerChange(UIInput::ATMPowerState) = 0;

    virtual void printReceiptOutput() = 0;
    virtual void dispenserOutput() = 0;
    virtual void cardReaderOutput() = 0;
    virtual void displayOutput(const NewDisplayStateEvent&) = 0;
    virtual void ATMPowerChange(const ATMPowerStateEvent&) = 0;
};

#endif //MOOP_ATM_PROJECT_ATMCONTROLLER_H
