//
// Created by Lemonderon on 20.10.2020.
//

#include <QtWidgets/QMessageBox>
#include "ATMQtUiController.h"
#include "../../ui/ATMForm.h"
#include "../../ui/ATMDisplay.h"
#include "../../models/Bank.h"
#include "../../models/accounts/Account.h"
#include "../../models/atm_hardware/CardReader.h"
#include "../../helpers/InputValidation.h"
#include "../../constants/ATMLimits.h"



ATMQtUiController::ATMQtUiController(QMainWindow &mw) :
        ATMController(), atmForm_(new ATMForm(mw, *this)), display_(new ATMDisplay(atmForm_->getWebView())), entered_NUM(0) {}

ATMQtUiController::~ATMQtUiController() {
    delete atmForm_;
    atmForm_ = nullptr;
}

void ATMQtUiController::changePINTries(int n){
    if (display_->getCurrentScreen() == PINEnteringScreen) {
            QString jsQ = "document.getElementById(\"tries\").innerHTML = 'Tries left: "+ QString::number(ATMLimits::MAX_FAILED_PIN_EVALS - n) +"';";
            //todo wait while load
            entered_NUM = 0;
        display_->runJs("document.getElementById(\"stars\").innerHTML =' ';");
        display_->runJs(jsQ);
        }
}


void ATMQtUiController::dialPadInput(const UIButtonsInput::DialPad e) {
    if (display_->getCurrentScreen() == PINEnteringScreen || display_->getCurrentScreen() == ChangePinScreen) {
        if (e != UIButtonsInput::D000 && e!= UIButtonsInput::DDot){
            entered_NUM =entered_NUM*10 + e - 1;
            QString jsQ = "document.getElementById(\"stars\").innerHTML += '*';";
            //todo wait while load
            display_->runJs(jsQ);

        }
    }

}

void ATMQtUiController::dialPadControlInput(const UIButtonsInput::ControlPad e) {
    //TODO Realize Cancel Button and Clear button
    if ((display_->getCurrentScreen() == PINEnteringScreen || display_->getCurrentScreen() == ChangePinScreen)
         &&(e != UIButtonsInput::Enter)){
        if (e == UIButtonsInput::Cancel){
            entered_NUM/=10;
            //todo wait while load
            display_->runJs("var s = document.getElementById(\"stars\").innerHTML;");
            display_->runJs("document.getElementById(\"stars\").innerHTML = s.substring(0, s.length-1);");

        } else if (e == UIButtonsInput::Clear){
            entered_NUM = 0;
            //todo wait while load
            display_->runJs("document.getElementById(\"stars\").innerHTML = ''");
        }
    } else if (display_->getCurrentScreen() == PINEnteringScreen) {
        if (e == UIButtonsInput::Enter) {
            if(InputValidation::validatePin(entered_NUM)){
                mediator_->Notify(*this, EventToATM::PINSubmittedEvent(entered_NUM));
                entered_NUM = 0;
            }
        }
    }
    else if (display_->getCurrentScreen() == ChangePinScreen) {
        if (e == UIButtonsInput::Enter) {
            if(InputValidation::validatePin(entered_NUM)){
                mediator_->Notify(*this, EventToATM::PINChangedEvent(entered_NUM));
                entered_NUM = 0;
                navigateToNewView(Views::MainMenuScreen);
            }
        }
    }
}

void ATMQtUiController::sideDisplayBtnInput(const UIButtonsInput::DisplaySideButton e) {
    if (display_->getCurrentScreen() == MainMenuScreen) {
        if (e == UIButtonsInput::L3) {
            atmForm_->changeDispenser(true);
            atmForm_->setIsWithdrawal(false);
            navigateToNewView(Views::PutCashScreen);
        } else if (e == UIButtonsInput::L2) {
            atmForm_->changeDispenser(true);
            atmForm_->setIsWithdrawal(true);
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

            CARD_NUMBER_T n = dynamic_cast<ATMIO*>(mediator_)->getATM().getCardReader().getCardNum();
            ACCOUNT_BALANCE_AMOUNT_T balance = Bank::getAccount(n)->getMoney();
            QString jsQ = "document.getElementById(\"bal_num\").innerHTML = "+QString::number(balance)+";";
            //todo wait while load and remove message
                   QMessageBox::warning(nullptr, "Invalid input", jsQ, QMessageBox::Ok);
            display_->runJs(jsQ);
        }
    } else if (display_->getCurrentScreen() == PutCashScreen) {
        if (e == UIButtonsInput::L0) {
            atmForm_->changeDispenser(false);
            navigateToNewView(Views::MainMenuScreen);
        }

    } else if (display_->getCurrentScreen() == TakeCashScreen) {
        if (e == UIButtonsInput::L0) {
            atmForm_->changeDispenser(false);
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == FinishAccountScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        } else if (e == UIButtonsInput::R0) {
            navigateToNewView(Views::WelcomeScreen);
            atmForm_->changeCardReader(true);
            //todo erase all info?
        }
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

void ATMQtUiController::dispenserInput(const CASH_AMOUNT_T n) {
//    if (display_->getCurrentScreen() == PINEnteringScreen) {
    //TODO: Requires implementation
//    }
     if (display_->getCurrentScreen() == PutCashScreen) {
         mediator_->Notify(*this, EventToATM::PutCashEvent(n));
    } else if (display_->getCurrentScreen() == TakeCashScreen) {
         mediator_->Notify(*this, EventToATM::TakeCashEvent(n));
     }
}

void ATMQtUiController::cardReaderInput(const CARD_NUMBER_T n) {
    if (display_->getCurrentScreen() == WelcomeScreen) {
        mediator_->Notify(*this, EventToATM::CardInsertedEvent(n));
    }
}

void ATMQtUiController::printReceiptOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::dispenserOutput(CASH_AMOUNT_T n) {
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
            atmForm_->changeCardReader(true);
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

