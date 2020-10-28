//
// Created by Lemonderon on 20.10.2020.
//

#include "ATMQtUiController.h"
#include "../../ui/ATMForm.h"
#include "../../ui/ATMDisplay.h"

ATMQtUiController::ATMQtUiController(QMainWindow &mw) :
        ATMController(), atmForm_(new ATMForm(mw, *this)), display_(new ATMDisplay(atmForm_->getWebView())) {}

ATMQtUiController::~ATMQtUiController() {
    delete atmForm_;
    atmForm_ = nullptr;
}

void ATMQtUiController::dialPadInput(const UIInput::DialPadBtnInput e) {
    if (display_->getCurrentScreen() == PINEnteringScreen) {
        //TODO: Requires implementation
    }
}

void ATMQtUiController::dialPadControlInput(const UIInput::ControlBtnInput e) {
    if (display_->getCurrentScreen() == PINEnteringScreen) {
        //TODO: Requires implementation
    }
}

void ATMQtUiController::sideDisplayBtnInput(const UIInput::DisplaySideBtnInput e) {
    if (display_->getCurrentScreen() == MainMenuScreen) {
        //TODO: Requires implementation
    }
}

void ATMQtUiController::ATMPowerChange(UIInput::ATMPowerState powerState) {
    switch (powerState) {
        case (UIInput::ATMPowerState::On):
            mediator_->Notify(ATMPowerStateEvent(ATMPowerStateEvent::PowerState::On, ATMEvent::Target::ATM));
            break;
        case (UIInput::ATMPowerState::Off):
            mediator_->Notify(ATMPowerStateEvent(ATMPowerStateEvent::PowerState::Off, ATMEvent::Target::ATM));
            break;
    }
}

void ATMQtUiController::dispenserInput() {
//    if (display_->getCurrentScreen() == PINEnteringScreen) {
    //TODO: Requires implementation
//    }
}

void ATMQtUiController::cardReaderInput(const CARD_NUMBER_T n) {
    if (display_->getCurrentScreen() == WelcomeScreen) {
        mediator_->Notify(CardReaderInputEventToATM(n));
//    TODO: Requires implementation
    }
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

void ATMQtUiController::displayOutput(Views view) {
    //TODO: Requires implementation
}

void ATMQtUiController::ATMPowerChange(ATMPowerStateEvent::PowerState state) {
    switch (state) {
        case (ATMPowerStateEvent::PowerState::On):
            display_->turnOn();
            break;
        case (ATMPowerStateEvent::PowerState::Off):
            display_->turnOff();
            break;
    }
}

void ATMQtUiController::cardAnswerFromATM(CardEventToATMIO::Type eventType) {
    switch (eventType) {
        case CardEventToATMIO::Type::CardAccepted:
            //TODO: requires implementation
            break;
        case CardEventToATMIO::Type::CardReturnEvent:
            //TODO: requires implementation
            break;
        case CardEventToATMIO::Type::CardBlockedEvent:
            //TODO: requires implementation
            break;
        case CardEventToATMIO::Type::InvalidCardInsertedEvent:
            //TODO: requires implementation
            break;
    }
}