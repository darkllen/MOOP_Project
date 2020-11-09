//
// Created by Lemonderon on 20.10.2020.
//

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>
#include "ATMQtUiController.h"
#include "../../ui/ATMForm.h"
#include "../../models/Bank.h"
#include "../../models/ATMInfo.h"
#include "../../models/accounts/Account.h"
#include "../../models/atm_hardware/CardReader.h"
#include "../../models/atm_hardware/Dispenser.h"
#include "../../helpers/InputValidation.h"
#include "../../constants/ATMLimits.h"
#include "../../models/Customer.h"
#include "../../models/accounts/SavingAccount.h"
#include "../AccountActions.h"
#include "../../models/transactions/Transaction.h"


ATMQtUiController::ATMQtUiController(QMainWindow &mw) :
        ATMController(), atmForm_(new ATMForm(mw, *this)), display_(new ATMDisplay(atmForm_->getWebView())), entered_NUM("") {}

ATMQtUiController::~ATMQtUiController() {
    delete atmForm_;
    atmForm_ = nullptr;
}

void ATMQtUiController::changePINTries(int n) {
    if (display_->getCurrentScreen() == PINEnteringScreen) {
        QString jsQ = "document.getElementById(\"tries\").innerHTML = 'Tries left: " + QString::number(ATMLimits::MAX_FAILED_PIN_EVALS - n) + "';";
        entered_NUM = "";
        display_->runJs("document.getElementById(\"text\").innerHTML =' ';");
        display_->runJs(jsQ);
    }
}

void ATMQtUiController::changeWarning(const QString &s) {
    QString jsQ = "document.getElementById(\"warning\").innerHTML = '" + s + "';";
    display_->runJs(jsQ);
}


void ATMQtUiController::dialPadInput(const UIButtonsInput::DialPad e) {
    if ((display_->getCurrentScreen() == PINEnteringScreen || display_->getCurrentScreen() == ChangePinScreen) &&
        (entered_NUM.length() < ATMLimits::NUMBERS_IN_PIN)) {
        if (e != UIButtonsInput::D000 && e != UIButtonsInput::DDot) {
            entered_NUM = entered_NUM + QString::number(e - 1);
            QString jsQ = "document.getElementById(\"text\").innerHTML += '*';";
            display_->runJs(jsQ);

        }
    } else if (display_->getCurrentScreen() == ReadCardScreen || display_->getCurrentScreen() == ReadAmountScreen
               || display_->getCurrentScreen() == ReadRegScreen) {
        if (e != UIButtonsInput::D000 && e != UIButtonsInput::DDot) {
            entered_NUM = entered_NUM + QString::number(e - 1);
            QString jsQ = "document.getElementById(\"text\").innerHTML = '" + entered_NUM + "';";
            display_->runJs(jsQ);
        }
    }

}

void ATMQtUiController::dialPadControlInput(const UIButtonsInput::ControlPad e) {
    if ((display_->getCurrentScreen() == PINEnteringScreen || display_->getCurrentScreen() == ChangePinScreen
         || display_->getCurrentScreen() == ReadCardScreen || display_->getCurrentScreen() == ReadAmountScreen
         || display_->getCurrentScreen() == ReadRegScreen)
        && (e != UIButtonsInput::Enter)) {
        if (e == UIButtonsInput::Cancel) {
            entered_NUM = entered_NUM.mid(0, entered_NUM.length() - 1);
            display_->runJs("var s = document.getElementById(\"text\").innerHTML;");
            display_->runJs("document.getElementById(\"text\").innerHTML = s.substring(0, s.length-1);");

        } else if (e == UIButtonsInput::Clear) {
            entered_NUM = "";
            display_->runJs("document.getElementById(\"text\").innerHTML = ''");
        }
    } else if (display_->getCurrentScreen() == PINEnteringScreen) {
        if (e == UIButtonsInput::Enter) {
            if (InputValidation::validatePin(entered_NUM)) {
                changeWarning("");
                mediator_->Notify(*this, EventToATM::PINSubmittedEvent(entered_NUM.toInt()));
                entered_NUM = "";
            } else changeWarning("Not enough digits in pin");
        }
    } else if (display_->getCurrentScreen() == ChangePinScreen) {
        if (e == UIButtonsInput::Enter) {
            if (InputValidation::validatePin(entered_NUM)) {
                changeWarning("");
                mediator_->Notify(*this, EventToATM::PINChangedEvent(entered_NUM.toInt()));
                entered_NUM = "";
                navigateToNewView(Views::MainMenuScreen);
            } else changeWarning("Not enough digits in pin");
        }
    } else if (display_->getCurrentScreen() == ReadCardScreen) {
        if (e == UIButtonsInput::Enter) {
            if (InputValidation::validateCardNumber(entered_NUM.toLongLong())) {
                entered_card = entered_NUM;
                navigateToNewView(Views::ReadAmountScreen);
                entered_NUM = "";
            } else {
                changeWarning("Card number is invalid!");
            }
        }
    } else if (display_->getCurrentScreen() == ReadAmountScreen) {
        if (e == UIButtonsInput::Enter) {
            CARD_NUMBER_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum();
            if (InputValidation::validateCashSum(entered_NUM.toLongLong(), n)) {
                entered_amount = entered_NUM;
                if (isOneTime) {
                    navigateToNewView(Views::ProcessScreen);
                    downloadProcessScreen();
                } else
                    navigateToNewView(Views::ReadRegScreen);
                entered_NUM = "";
            } else {
                changeWarning("Cash amount is invalid!");
            }
        }
    } else if (display_->getCurrentScreen() == ReadRegScreen) {
        if (e == UIButtonsInput::Enter) {
            if (entered_NUM.toLongLong() > 0) {
                entered_reg = entered_NUM;
                navigateToNewView(Views::ProcessScreen);
                downloadProcessScreen();

                entered_NUM = "";
            } else {
                changeWarning("Regularity is invalid!");
            }
        }
    }
}

void ATMQtUiController::sideDisplayBtnInput(const UIButtonsInput::DisplaySideButton e) {
    if (display_->getCurrentScreen() == CardIsInvalidScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::WelcomeScreen);
            atmForm_->changeCardReader(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus());
            entered_NUM = "";
            dynamic_cast<ATMIO *>(mediator_)->getATM().resetCardReader();
        }
    } else if (display_->getCurrentScreen() == CardIsBlockedScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::WelcomeScreen);
            atmForm_->changeCardReader(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus());
            entered_NUM = "";
            dynamic_cast<ATMIO *>(mediator_)->getATM().resetCardReader();
        }
    } else if (display_->getCurrentScreen() == PINEnteringScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::WelcomeScreen);
            atmForm_->changeCardReader(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus());
            entered_NUM = "";
            dynamic_cast<ATMIO *>(mediator_)->getATM().resetCardReader();
        }
    } else if (display_->getCurrentScreen() == MainMenuScreen) {
        if (e == UIButtonsInput::L3) {
            navigateToNewView(Views::PutCashScreen);
            enableDispencer(false);

        } else if (e == UIButtonsInput::L2) {
            navigateToNewView(Views::TakeCashScreen);
            enableDispencer(true);

        } else if (e == UIButtonsInput::L1) {
            navigateToNewView(Views::ShowAccountsScreen);
            CARD_NUMBER_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum();

            display_->runJs("document.getElementById(\"name\").innerHTML ='" + QString::fromStdString(Bank::getCustomer(n)->getName()) + "';");
            display_->runJs("document.getElementById(\"address\").innerHTML ='" + QString::fromStdString(Bank::getCustomer(n)->getAddress()) + "';");

        } else if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::FinishAccountScreen);
        } else if (e == UIButtonsInput::R3) {
            navigateToNewView(Views::ChangePinScreen);
        } else if (e == UIButtonsInput::R2) {
            navigateToNewView(Views::TransactionHistoryScreen);
            CARD_NUMBER_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum();
            Account *account = Bank::getAccount(n);
            QList<Transaction *> transactions = AccountActions::viewHistory(*account);
            std::reverse(transactions.begin(), transactions.end());
            QString res;
            for (auto &transaction : transactions) {
                res += transaction->print() + "\n\n";
            }
            res.replace(QString("\n"), QString("<br>"));
            res.replace(QString("\t"), QString("&nbsp;&nbsp;&nbsp;&nbsp;"));
            display_->runJs(R"(document.getElementById("text").innerHTML = ")" + res + R"(";)");
        } else if (e == UIButtonsInput::R1) {
            navigateToNewView(Views::DoTransactionScreen);
        } else if (e == UIButtonsInput::R0) {
            navigateToNewView(Views::CardBalanceScreen);

            CARD_NUMBER_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum();
            Account *account = Bank::getAccount(n);
            ACCOUNT_BALANCE_AMOUNT_T balance = account->getMoney();

            QString jsQ = "document.getElementById(\"bal_num\").innerHTML = " + QString::number(balance) + ";";
            display_->runJs(jsQ);

            if (const auto *t = dynamic_cast<const SavingAccount *>(account)) {
                QString jsQ = "document.getElementById(\"bal_lim\").innerHTML = " + QString::number(t->getLimit()) + ";";
                display_->runJs(jsQ);
            }

        }
    } else if (display_->getCurrentScreen() == PutCashScreen) {
        if (e == UIButtonsInput::L0) {
            atmForm_->changeDispenser(false);
            navigateToNewView(Views::MainMenuScreen);
            display_->setReceipt("");
            atmForm_->changeReceipt(false);
        }

    } else if (display_->getCurrentScreen() == TakeCashScreen) {
        if (e == UIButtonsInput::L0) {
            atmForm_->changeDispenser(false);
            navigateToNewView(Views::MainMenuScreen);
            display_->setReceipt("");
            atmForm_->changeReceipt(false);
        }
    } else if (display_->getCurrentScreen() == FinishAccountScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        } else if (e == UIButtonsInput::R0) {
            navigateToNewView(Views::WelcomeScreen);
            dynamic_cast<ATMIO *>(mediator_)->getATM().resetCardReader();
            atmForm_->changeDispenser(false);
            atmForm_->changeReceipt(false);

            if (!dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) {
                atmForm_->changeCardReader(false);
                display_->runJs("document.getElementById(\"warning\").innerHTML ='Sorry, the cardreader is temporarily down';");
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
    } else if (display_->getCurrentScreen() == TransactionHistoryScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    } else if (display_->getCurrentScreen() == DoTransactionScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        } else if (e == UIButtonsInput::L3) {
            //onetimetr
            navigateToNewView(Views::ReadCardScreen);
            setIsOneTime(true);
        } else if (e == UIButtonsInput::L2) {
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

            QString dis;
            if (dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenserStatus()) dis = "Working";
            else dis = "Not working";
            QString cR;
            if (dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) cR = "Working";
            else cR = "Not working";

            display_->runJs("document.getElementById(\"dispenser_status\").innerHTML ='" + dis + "' ;");
            display_->runJs("document.getElementById(\"cardreader_status\").innerHTML ='" + cR + "' ;");

        } else if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::InfoScreen);
            ATMInfo atmInfo = dynamic_cast<ATMIO *>(mediator_)->getATM().getATMInfo();
            CASH_AMOUNT_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenser().getAvailableCashAmount();
            display_->runJs("document.getElementById(\"cash\").innerHTML ='" + QString::number(n) + "' ;");
            display_->runJs("document.getElementById(\"s_num\").innerHTML ='" + QString::number(atmInfo.getSerialNumber()) + "' ;");
            display_->runJs("document.getElementById(\"location\").innerHTML ='" + QString::fromStdString(atmInfo.getLocation()) + "' ;");


        }

    } else if (display_->getCurrentScreen() == TakeCashMScreen) {
        if (e == UIButtonsInput::L0) {
            atmForm_->changeDispenser(false);
            navigateToNewView(Views::PoweredOffScreen);
        }
    } else if (display_->getCurrentScreen() == PutCashMScreen) {
        if (e == UIButtonsInput::L0) {
            atmForm_->changeDispenser(false);
            navigateToNewView(Views::PoweredOffScreen);
        }
    } else if (display_->getCurrentScreen() == ChangeStatusScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::PoweredOffScreen);
        } else if (e == UIButtonsInput::L3) {
            QString cR;
            if (dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) {
                cR = "Not working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setCardReaderStatus(false);
            } else {
                cR = "Working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setCardReaderStatus(true);
            }
            display_->runJs("document.getElementById(\"cardreader_status\").innerHTML ='" + cR + "' ;");

        } else if (e == UIButtonsInput::L2) {
            QString dis;
            if (dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenserStatus()) {
                dis = "Not working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setDispenserStatus(false);

            } else {
                dis = "Working";
                dynamic_cast<ATMIO *>(mediator_)->getATM().setDispenserStatus(true);

            }

            display_->runJs("document.getElementById(\"dispenser_status\").innerHTML ='" + dis + "' ;");

        }
    } else if (display_->getCurrentScreen() == InfoScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::PoweredOffScreen);
        }
    } else if (display_->getCurrentScreen() == ReadCardScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::DoTransactionScreen);
            entered_NUM = "";
        }
    } else if (display_->getCurrentScreen() == ReadAmountScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::ReadCardScreen);
            entered_NUM = entered_card;
            updateEnNum();
        }
    } else if (display_->getCurrentScreen() == ReadRegScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::ReadAmountScreen);
            entered_NUM = entered_amount;
            updateEnNum();
        }
    } else if (display_->getCurrentScreen() == ProcessScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::DoTransactionScreen);
            display_->setReceipt("");
            atmForm_->changeReceipt(false);
        } else if (e == UIButtonsInput::R0) {
            navigateToNewView(Views::MainMenuScreen);

            CARD_NUMBER_T n = dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum();

            if (isOneTime) {
                mediator_->Notify(*this, EventToATM::OneTimeTransaction(entered_card.toLongLong(), entered_amount.toLongLong()));
                display_->setReceipt(entered_amount + "$ was transfered from card " + QString::number(n) + " to card " + entered_card);
            } else {
                mediator_->Notify(*this,
                                  EventToATM::RegularTransaction(entered_card.toLongLong(), entered_amount.toLongLong(), entered_reg.toLong()));
                display_->setReceipt(
                        entered_amount + "$ will be transfered from card " + QString::number(n) + " to card " + entered_card + " every " +
                        entered_reg + " days");

            }

            atmForm_->changeReceipt(true);
            entered_card = "";
            entered_amount = "";
            entered_reg = "";

        }
    } else if (display_->getCurrentScreen() == ReceiptScreen) {
        if (e == UIButtonsInput::L0) {
            navigateToNewView(Views::MainMenuScreen);
        }
    }
}

void ATMQtUiController::ATMPowerChangeFromUI(ATMPowerState powerState) {
    mediator_->Notify(*this, EventToATM::ATMPowerStateEvent(powerState));
}

void ATMQtUiController::dispenserInput(const CASH_AMOUNT_T n) {

    if (display_->getCurrentScreen() == PutCashScreen) {
        mediator_->Notify(*this, EventToATM::PutCashEvent(n));
        display_->setReceipt("Put " + QString::number(n) + "$ to card with number " +
                             QString::number(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum()));
//         atmForm_->changeReceipt(true);
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
    if (atmForm_->getIsReceiptEnable()) {
        display_->navigateTo(ReceiptScreen);
        display_->runJs("document.getElementById(\"text\").innerHTML ='" + display_->getReceipt() + "';");

        display_->setReceipt("");
        atmForm_->changeReceipt(false);
    }
}

void ATMQtUiController::dispenserOutput(CASH_AMOUNT_T n) {
    if (display_->getCurrentScreen() == TakeCashScreen) {
        mediator_->Notify(*this, EventToATM::TakeCashEvent(n));
        display_->setReceipt("Take " + QString::number(n) + "$ from card with number " +
                             QString::number(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReader().getCardNum()));
//        atmForm_->changeReceipt(true);
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
            atmForm_->changeCardReader(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus());
            break;
        }

    }
}

void ATMQtUiController::ATMPowerChangeFromATM(ATMPowerState state) {
    switch (state) {
        case On:
            if(!display_->getIsOn()) {
                display_->turnOn();
                atmForm_->changeCardReader(dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus());
                atmForm_->changeDispenser(false);
                if (!dynamic_cast<ATMIO *>(mediator_)->getATM().getCardReaderStatus()) {
                    display_->runJs(
                            "document.getElementById(\"warning\").innerHTML ='Sorry, the cardreader is temporarily down';");
                }
            }
            break;
        case Off:
            if(display_->getIsOn()) {
                display_->turnOff();
                atmForm_->changeCardReader(false);
                atmForm_->changeDispenser(false);
                atmForm_->changeReceipt(false);
            }
            break;
    }
}

void ATMQtUiController::enableDispencer(const bool &isWithdrawal) {
    if (dynamic_cast<ATMIO *>(mediator_)->getATM().getDispenserStatus()) {
        atmForm_->changeDispenser(true);
        atmForm_->setIsWithdrawal(isWithdrawal);
    } else {
        atmForm_->changeDispenser(false);
        display_->runJs("document.getElementById(\"warning\").innerHTML ='Sorry, the dispenser is temporarily down' ;");
    }
}

void ATMQtUiController::downloadProcessScreen() {
    display_->runJs("document.getElementById(\"amount\").innerHTML ='" + entered_amount + "' ;");
    display_->runJs(
            "document.getElementById(\"card\").innerHTML ='to " + QString::fromStdString(Bank::getCustomer(entered_card.toLongLong())->getName()) +
            "' ;");
    if (entered_reg.toLong() != 0)
        display_->runJs("document.getElementById(\"days\").innerHTML ='every " + entered_reg + " days' ;");


}

void ATMQtUiController::updateEnNum() {
    display_->runJs("document.getElementById(\"text\").innerHTML = '" + entered_NUM + "';");
}



