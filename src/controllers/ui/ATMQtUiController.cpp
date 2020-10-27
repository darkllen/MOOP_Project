//
// Created by Lemonderon on 20.10.2020.
//

#include "ATMQtUiController.h"
#include "../../ui/ATMForm.h"
#include "../../ui/ATMDisplay.h"

ATMQtUiController::ATMQtUiController(QMainWindow &mw) :
        ATMController(), atmForm_(new ATMForm(mw, *this)), display_(new ATMDisplay(atmForm_->getWebView())) {
    display_->turnOn();
}

ATMQtUiController::~ATMQtUiController() {
    delete atmForm_;
    atmForm_ = nullptr;
}

void ATMQtUiController::dialPadInput(const UIInput::DialPadBtnInput e) {
    //TODO: Requires implementation
}

void ATMQtUiController::dialPadControlInput(const UIInput::ControlBtnInput e) {
    //TODO: Requires implementation
}

void ATMQtUiController::sideDisplayBtnInput(const UIInput::DisplaySideBtnInput e) {
    //TODO: Requires implementation
}

void ATMQtUiController::ATMPowerChange(UIInput::ATMPowerState powerState) {
    switch (powerState) {
        case (UIInput::ATMPowerState::On):
            mediator_->Notify(*this, ATMPowerStateEvent(ATMPowerStateEvent::PowerState::On, ATMEvent::Target::ATM));
            break;
        case (UIInput::ATMPowerState::Off):
            mediator_->Notify(*this, ATMPowerStateEvent(ATMPowerStateEvent::PowerState::Off, ATMEvent::Target::ATM));
            break;
    }
}

void ATMQtUiController::dispenserInput() {
    //TODO: Requires implementation
}

void ATMQtUiController::cardReaderInput(const CARD_NUMBER_T n) {
    mediator_->Notify(*this, CardReaderInputEvent(n));
}

void ATMQtUiController::printReceiptOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::dispenserOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::cardReaderOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::displayOutput(const NewDisplayStateEvent &) {
    //TODO: Requires implementation
}

void ATMQtUiController::ATMPowerChange(const ATMPowerStateEvent & powerState) {
    switch (powerState.value) {
        case (ATMPowerStateEvent::PowerState::On):
            display_->turnOn();
            break;
        case (ATMPowerStateEvent::PowerState::Off):
            display_->turnOff();
            break;
    }
}