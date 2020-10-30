//
// Created by kuchm on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMCONTROLLER_H
#define MOOP_ATM_PROJECT_ATMCONTROLLER_H

#include "../mediators/ATMIO.h"
#include "../events/UIInput.h"
#include "../events/ATMEvent.h"
#include "../constants/ATMTypes.h"

class ATMController: public ATMBaseComponent {
public:
    explicit ATMController(): ATMBaseComponent() {}
    virtual ~ATMController() {};

    virtual void dialPadInput(UIButtonsInput::DialPad) = 0;
    virtual void dialPadControlInput(UIButtonsInput::ControlPad) = 0;
    virtual void sideDisplayBtnInput(UIButtonsInput::DisplaySideButton) = 0;
    virtual void dispenserInput() = 0;
    virtual void cardReaderInput(CARD_NUMBER_T) = 0;
    virtual void ATMPowerChangeFromUI(ATMPowerState) = 0;

    virtual void printReceiptOutput() = 0;
    virtual void dispenserOutput() = 0;
    virtual void navigateToNewView(Views) = 0;
    virtual void showCardEvalResult(EventToATMController::CardEvalResultEvent::Result) = 0;
    virtual void ATMPowerChangeFromATM(ATMPowerState) = 0;
};

#endif //MOOP_ATM_PROJECT_ATMCONTROLLER_H
