//
// Created by Lemonderon on 20.10.2020.
//

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>
#include "ATMQtUiController.h"
#include "../../ui/ATMForm.h"
#include "../../ui/ATMDisplay.h"
#include "../../models/Bank.h"
#include "../../models/accounts/Account.h"
#include "../../models/atm_hardware/CardReader.h"
#include "../../models/atm_hardware/Dispenser.h"
#include "../../helpers/InputValidation.h"
#include "../../constants/ATMLimits.h"
#include "../../models/Customer.h"



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
        display_->runJs("document.getElementById(\"text\").innerHTML =' ';");
        display_->runJs(jsQ);
        }
}


void ATMQtUiController::dialPadInput(const UIButtonsInput::DialPad e) {
    if (display_->getCurrentScreen() == PINEnteringScreen || display_->getCurrentScreen() == ChangePinScreen) {
        if (e != UIButtonsInput::D000 && e!= UIButtonsInput::DDot){
            entered_NUM =entered_NUM*10 + e - 1;
            QString jsQ = "document.getElementById(\"text\").innerHTML += '*';";
            display_->runJs(jsQ);

        }
    } else if(display_->getCurrentScreen() == ReadCardScreen || display_->getCurrentScreen() == ReadAmountScreen
               || display_->getCurrentScreen() == ReadRegScreen){
        entered_NUM =entered_NUM*10 + e - 1;
        QString jsQ = "document.getElementById(\"text\").innerHTML = '"+QString::number(entered_NUM)+"';";
        display_->runJs(jsQ);
    }

}

void ATMQtUiController::dialPadControlInput(const UIButtonsInput::ControlPad e) {
    if ((display_->getCurrentScreen() == PINEnteringScreen || display_->getCurrentScreen() == ChangePinScreen
           || display_->getCurrentScreen() == ReadCardScreen || display_->getCurrentScreen() == ReadAmountScreen
           || display_->getCurrentScreen() == ReadRegScreen)
         &&(e != UIButtonsInput::Enter)){
        if (e == UIButtonsInput::Cancel){
            entered_NUM/=10;
            //todo wait while load
            display_->runJs("var s = document.getElementById(\"text\").innerHTML;");
            display_->runJs("document.getElementById(\"text\").innerHTML = s.substring(0, s.length-1);");

        } else if (e == UIButtonsInput::Clear){
            entered_NUM = 0;
            //todo wait while load
            display_->runJs("document.getElementById(\"text\").innerHTML = ''");
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
    } else if (display_->getCurrentScreen() == ReadCardScreen) {
        if (e == UIButtonsInput::Enter) {
            if(InputValidation::validateCardNumber(entered_NUM)){
                entered_card = entered_NUM;
                navigateToNewView(Views::ReadAmountScreen);
                entered_NUM = 0;
            } else{
                QMessageBox::warning(nullptr, "Invalid input", "Card number is invalid!", QMessageBox::Ok);
            }
        }
    }
    else if (display_->getCurrentScreen() == ReadAmountScreen) {
        if (e == UIButtonsInput::Enter) {
            CARD_NUMBER_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum();
            if(InputValidation::validateCashSum(entered_NUM, n)){
                entered_amount = entered_NUM;
                if(isOneTime){
                    navigateToNewView(Views::ProcessScreen);
                    downloadProcessScreen();
                }

                else
                    navigateToNewView(Views::ReadRegScreen);
                entered_NUM = 0;
            } else{
                QMessageBox::warning(nullptr, "Invalid input", "Cash amount is invalid!", QMessageBox::Ok);

            }
        }
    } else if (display_->getCurrentScreen() == ReadRegScreen) {
        if (e == UIButtonsInput::Enter) {
            if(entered_NUM>0){
                entered_reg = entered_NUM;
                navigateToNewView(Views::ProcessScreen);
                downloadProcessScreen();

                entered_NUM = 0;
            } else{
                QMessageBox::warning(nullptr, "Invalid input", "Regularity is invalid!", QMessageBox::Ok);
            }
        }
    }
}

void ATMQtUiController::sideDisplayBtnInput(const UIButtonsInput::DisplaySideButton e) {
    if (display_->getCurrentScreen() == MainMenuScreen) {
        if (e == UIButtonsInput::L3) {
            navigateToNewView(Views::PutCashScreen);
            enableDispencer(false);

        } else if (e == UIButtonsInput::L2) {
            navigateToNewView(Views::TakeCashScreen);
            enableDispencer(true);

        } else if (e == UIButtonsInput::L1) {
            navigateToNewView(Views::ShowAccountsScreen);
        } else if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::FinishAccountScreen);
        } else if (e == UIButtonsInput::R3) {
            navigateToNewView(Views::ChangePinScreen);
        } else if (e == UIButtonsInput::R2) {
            navigateToNewView(Views::ChangeLimitScreen);
        } else if (e == UIButtonsInput::R1) {
            navigateToNewView(Views::DoTransactionScreen);
        } else if (e == UIButtonsInput::R0) {
            navigateToNewView(Views::CardBalanceScreen);

            CARD_NUMBER_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum();
            ACCOUNT_BALANCE_AMOUNT_T balance = Bank::getAccount(n)->getMoney();
            QString jsQ = "document.getElementById(\"bal_num\").innerHTML = " + QString::number(balance) + ";";
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

            if(!dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) {
                atmForm_->changeCardReader(false);
                //todo wait while load and remove message
                QMessageBox::warning(nullptr, "Wait", "Wait", QMessageBox::Ok);
                display_->runJs("document.getElementById(\"warning\").innerHTML ='Перепрошуємо, cardReader тимчасово не працює';");
            } else
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
        } else  if (e == UIButtonsInput::L3) {
            //onetimetr
            navigateToNewView(Views::ReadCardScreen);
            setIsOneTime(true);
        } else  if (e == UIButtonsInput::L2) {
            //regtr
            navigateToNewView(Views::ReadCardScreen);
            setIsOneTime(false);
        }
    } else if (display_->getCurrentScreen() == CardBalanceScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == PoweredOffScreen) {
        atmForm_->changeCardReader(false);

        if (e == UIButtonsInput::L3) {
            navigateToNewView(Views::PutCashMScreen);
            enableDispencer(false);

        } else if (e == UIButtonsInput::L2) {
            navigateToNewView(Views::TakeCashMScreen);
            enableDispencer(true);

        } else if (e == UIButtonsInput::L1) {
            navigateToNewView(Views::ChangeStatusScreen);
            //todo wait while load and remove message
            QMessageBox::warning(nullptr, "Wait", "Wait", QMessageBox::Ok);

            QString dis;
            if(dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenserStatus()) dis = "Working";
            else dis = "Not working";
            QString cR;
            if(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) cR = "Working";
            else cR = "Not working";

            display_->runJs("document.getElementById(\"dispenser_status\").innerHTML ='"+dis+"' ;");
            display_->runJs("document.getElementById(\"cardreader_status\").innerHTML ='"+cR+"' ;");

        } else if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::InfoScreen);
            CASH_AMOUNT_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenser().getAvailableCashAmount();
            //todo wait while load and remove message
            QMessageBox::warning(nullptr, "Wait", QString::number(n), QMessageBox::Ok);
            display_->runJs("document.getElementById(\"cash\").innerHTML ='"+QString::number(n)+"' ;");

        }

    } else if (display_->getCurrentScreen() == TakeCashMScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::PoweredOffScreen);
        }
    } else if (display_->getCurrentScreen() == PutCashMScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::PoweredOffScreen);
        }
    } else if (display_->getCurrentScreen() == ChangeStatusScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::PoweredOffScreen);
        } else if (e == UIButtonsInput::L3) {
            QString cR;
            if(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) {
                cR = "Not working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setCardReaderStatus(false);
            }
            else {
                cR = "Working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setCardReaderStatus(true);
            }
            display_->runJs("document.getElementById(\"cardreader_status\").innerHTML ='"+cR+"' ;");

        } else if (e == UIButtonsInput::L2) {
            QString dis;
            if(dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenserStatus()) {
                dis = "Not working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setDispenserStatus(false);

            }
            else {
                dis = "Working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setDispenserStatus(true);

            }

            display_->runJs("document.getElementById(\"dispenser_status\").innerHTML ='"+dis+"' ;");

        }
    } else if (display_->getCurrentScreen() == InfoScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::PoweredOffScreen);
        }
    } else if (display_->getCurrentScreen() == ProcessScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::DoTransactionScreen);
        } else if (e == UIButtonsInput::R0) {
            navigateToNewView(Views::MainMenuScreen);
            if(isOneTime)
                mediator_->Notify(*this, EventToATM::OneTimeTransaction(entered_card,entered_amount));
            else
                mediator_->Notify(*this, EventToATM::RegularTransaction(entered_card,entered_amount, entered_reg));

            entered_card=0;
            entered_amount=0;
            entered_reg=0;

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
    } else if (display_->getCurrentScreen() == PutCashMScreen) {
         mediator_->Notify(*this, EventToATM::PutCashMEvent(n));
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
    if (display_->getCurrentScreen() == TakeCashScreen) {
        mediator_->Notify(*this, EventToATM::TakeCashEvent(n));
    } else if (display_->getCurrentScreen() == TakeCashMScreen) {
        mediator_->Notify(*this, EventToATM::TakeCashMEvent(n));
    }
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
            atmForm_->changeCardReader(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus());
            if(!dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) {
                //todo wait while load and remove message
                QMessageBox::warning(nullptr, "Wait", "Wait", QMessageBox::Ok);
                display_->runJs("document.getElementById(\"warning\").innerHTML ='Перепрошуємо, cardReader тимчасово не працює';");
            }
            break;
        case Off:
            display_->turnOff();
            atmForm_->changeCardReader(false);
            break;
    }
}

void ATMQtUiController::enableDispencer(bool isWithdrawal){
    if (dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenserStatus()) {
        atmForm_->changeDispenser(true);
        atmForm_->setIsWithdrawal(isWithdrawal);
    } else{
        atmForm_->changeDispenser(false);
        //todo wait while load and remove message
        QMessageBox::warning(nullptr, "Wait", "Wait", QMessageBox::Ok);
        display_->runJs("document.getElementById(\"warning\").innerHTML ='Перепрошуємо, діспенсер тимчасово не працює' ;");
    }
}

void ATMQtUiController::downloadProcessScreen() {
    QMessageBox::warning(nullptr, "Wait", "Wait", QMessageBox::Ok);
    display_->runJs("document.getElementById(\"amount\").innerHTML ='"+QString::number(entered_amount)+"' ;");
    display_->runJs("document.getElementById(\"card\").innerHTML ='to "+QString::fromStdString(Bank::getCustomer(entered_card)->getName())+"' ;");
    if(entered_reg!=0)
        display_->runJs("document.getElementById(\"days\").innerHTML ='every "+QString::number(entered_reg)+" days' ;");


}



