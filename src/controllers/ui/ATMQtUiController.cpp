//
// Created by Lemonderon on 20.10.2020.
//

#include "ATMQtUiController.h"
#include "../../ui/ATMForm.h"
#include "../../ui/ATMDisplay.h"


ATMQtUiController::ATMQtUiController(QMainWindow &mw) :
        ATMController(), atmForm_(new ATMForm(mw, *this)), display_(new ATMDisplay(atmForm_->getWebView())), entered_NUM(0) {}

ATMQtUiController::~ATMQtUiController() {
    delete atmForm_;
    atmForm_ = nullptr;
}

#include <iostream>
void ATMQtUiController::dialPadInput(const UIButtonsInput::DialPad e) {
    if (display_->getCurrentScreen() == PINEnteringScreen) {
        if (e != UIButtonsInput::D000 && e!= UIButtonsInput::DDot){
            entered_NUM =entered_NUM*10 + e - 1;
            navigateToNewView(Views::PINEnteringScreen1);
        }
    } else if (display_->getCurrentScreen() == PINEnteringScreen1){
        if (e != UIButtonsInput::D000 && e!= UIButtonsInput::DDot){
            entered_NUM =entered_NUM*10 + e - 1;
            navigateToNewView(Views::PINEnteringScreen2);
        } else if (e == UIButtonsInput::D000){
            entered_NUM = 0;
            navigateToNewView(Views::PINEnteringScreen);
        }
    } else if (display_->getCurrentScreen() == PINEnteringScreen2){
        if (e != UIButtonsInput::D000 && e!= UIButtonsInput::DDot){
            entered_NUM =entered_NUM*10 + e - 1;
            navigateToNewView(Views::PINEnteringScreen3);
        } else if (e == UIButtonsInput::D000){
            entered_NUM = 0;
            navigateToNewView(Views::PINEnteringScreen);
        }
    } else if (display_->getCurrentScreen() == PINEnteringScreen3){
        if (e != UIButtonsInput::D000 && e!= UIButtonsInput::DDot){
            entered_NUM =entered_NUM*10 + e - 1;
            navigateToNewView(Views::PINEnteringScreen4);
        } else if (e == UIButtonsInput::D000){
            entered_NUM = 0;
            navigateToNewView(Views::PINEnteringScreen);
        }
    } else if (display_->getCurrentScreen() == PINEnteringScreen4){
         if (e == UIButtonsInput::D000){
            entered_NUM = 0;
            navigateToNewView(Views::PINEnteringScreen);
        }
    }
}

void ATMQtUiController::dialPadControlInput(const UIButtonsInput::ControlPad e) {
    //TODO Realize Cancel Button and Clear button
    if (display_->getCurrentScreen() == PINEnteringScreen4) {
        if (e == UIButtonsInput::Enter){
            mediator_->Notify(*this, EventToATM::PINSubmittedEvent(entered_NUM));
            entered_NUM = 0;
        }
    }
}

void ATMQtUiController::sideDisplayBtnInput(const UIButtonsInput::DisplaySideButton e) {
    if (display_->getCurrentScreen() == MainMenuScreen) {
        if (e == UIButtonsInput::L3) {
            navigateToNewView(Views::PutCashScreen);
        } else if (e == UIButtonsInput::L2) {
            navigateToNewView(Views::TakeCashScreen);
        }  else if (e == UIButtonsInput::L1) {
            navigateToNewView(Views::ShowAccountsScreen);
        } else if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::FinishAccountScreen);
        }else if (e == UIButtonsInput::R3) {
            navigateToNewView(Views::ChangePinScreen);
        } else if (e == UIButtonsInput::R2) {
            navigateToNewView(Views::ChangeLimitScreen);
        } else if (e == UIButtonsInput::R1) {
            navigateToNewView(Views::DoTransactionScreen);
        } else if (e == UIButtonsInput::R0) {
            navigateToNewView(Views::CardBalanceScreen);
        }
    } else if (display_->getCurrentScreen() == PutCashScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == TakeCashScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == FinishAccountScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == ShowAccountsScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == ChangePinScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == ChangeLimitScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == DoTransactionScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == CardBalanceScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
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
        case EventToATMController::CardEvalResultEvent::CardPINChecking: {
            display_->navigateTo(Views::PINEnteringScreen);
            break;
        }
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
