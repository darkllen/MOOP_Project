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

void ATMQtUiController::dialPadInput(const UIButtonsInput::DialPad e) {
    if (display_->getCurrentScreen() == PINEnteringScreen) {
        //TODO: Requires implementation
    }
}

void ATMQtUiController::dialPadControlInput(const UIButtonsInput::ControlPad e) {
    if (display_->getCurrentScreen() == PINEnteringScreen) {
        //TODO: Requires implementation
    }
}

void ATMQtUiController::sideDisplayBtnInput(const UIButtonsInput::DisplaySideButton e) {
    if (display_->getCurrentScreen() == MainMenuScreen) {
        //TODO: Requires implementation
    }
}

void ATMQtUiController::ATMPowerChangeFromUI(ATMPowerState powerState) {
    mediator_->Notify(*this, EventToATM::ATMPowerStateEvent(powerState));
}

void ATMQtUiController::dispenserInput() {
//    if (display_->getCurrentScreen() == PINEnteringScreen) {
    //TODO: Requires implementation
//    }
}

void ATMQtUiController::cardReaderInput(const CARD_NUMBER_T n) {
    if (display_->getCurrentScreen() == WelcomeScreen) {
        mediator_->Notify(*this, EventToATM::CardInsertedEvent(n));
    }
}

void ATMQtUiController::printReceiptOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::dispenserOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::navigateToNewView(Views view) {
    display_->navigateTo(view);
}

void ATMQtUiController::showCardEvalResult(EventToATMController::CardEvalResultEvent::Result result) {
    switch (result) {
        case EventToATMController::CardEvalResultEvent::CardIsAccepted: {
            display_->navigateTo(Views::MainMenuScreen);
            break;
        }
        case EventToATMController::CardEvalResultEvent::CardIsInvalid: {
            display_->navigateTo(Views::CardIsInvalidScreen);
            break;
        }
        case EventToATMController::CardEvalResultEvent::CardIsBlocked: {
            display_->navigateTo(Views::CardIsBlockedScreen);
            break;
        }
    }
}

void ATMQtUiController::ATMPowerChangeFromATM(ATMPowerState state) {
    switch (state) {
        case On:
            display_->turnOn();
            break;
        case Off:
            display_->turnOff();
            break;
    }
}
