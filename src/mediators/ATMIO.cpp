//
// Created by Lemonderon on 19.10.2020.
//

#include <QDebug>

#include "ATMIO.h"
#include "../models/ATM.h"
#include "../controllers/ATMController.h"
#include "../exceptions/ATMException.h"
#include "../models/atm_hardware/CardReader.h"
#include "../models/atm_hardware/Dispenser.h"
#include "../controllers/PinVerificationService.h"
#include "../controllers/AccountActions.h"
#include "../controllers/Maintenance.h"
#include "../models/TransactionManager.h"
#include "../models/Bank.h"
#include "../models/DebitCard.h"
#include "../models/accounts/Account.h"


ATMIO::ATMIO(ATM &atm, ATMController &controller) : atm_(&atm), controller_(&controller) {
    this->atm_->setMediator(this);
    this->controller_->setMediator(this);
}

void ATMIO::Notify(const ATMBaseComponent &sender, const ATMEvent &event) const {
    if (&sender == atm_) {
        handleNotifyTargetATMController(event);
    } else {
        handleNotifyTargetATM(event);
    }
}

void ATMIO::handleNotifyTargetATM(const ATMEvent &event) const {
    switch (event.type) {
        case ATMEvent::ATMPowerStateEvent: {
            auto e = dynamic_cast<const EventToATM::ATMPowerStateEvent &>(event);
            atm_->powerStateChange(e.value);
            break;
        }
        case ATMEvent::CardInsertedEvent: {
            auto e = dynamic_cast<const EventToATM::CardInsertedEvent &>(event);
            atm_->getCardReader().setInsertedCardN(e.value);
            break;
        }
        case ATMEvent::CardTakenEvent: {
            auto e = dynamic_cast<const EventToATM::CardTakenEvent &>(event);
            atm_->getCardReader().returnCard();
            break;
        }
        case ATMEvent::PINSubmittedEvent: {
            auto e = dynamic_cast<const EventToATM::PINSubmittedEvent &>(event);
            atm_->getCardReader().evalPIN(e.value);
            break;
        }
        case ATMEvent::PutCashEvent: {
            auto e = dynamic_cast<const EventToATM::PutCashEvent &>(event);
            CARD_NUMBER_T n = atm_->getCardReader().getCardNum();
            Account* account = Bank::getAccount(n);
            const CashTransaction tr = TransactionManager::createTransaction(QDateTime::currentDateTime(), *account, e.value, false);
            AccountActions::makeTransaction(*account, tr);
            atm_->getDispenser().cashIn(e.value);
            break;
        }
        case ATMEvent::TakeCashEvent: {
            auto e = dynamic_cast<const EventToATM::TakeCashEvent &>(event);
            CARD_NUMBER_T n = atm_->getCardReader().getCardNum();
            Account* account = Bank::getAccount(n);
            if(e.value>account->getMoney())
                throw HardwareException("You don`t have enough money on your card");
            const CashTransaction tr = TransactionManager::createTransaction(QDateTime::currentDateTime(), *account, e.value, true);
            AccountActions::makeTransaction(*account, tr);
            atm_->getDispenser().cashOut(e.value);
            break;
        }
        case ATMEvent::OneTimeTransactionEvent: {
            auto e = dynamic_cast<const EventToATM::OneTimeTransaction &>(event);
            CARD_NUMBER_T n = atm_->getCardReader().getCardNum();
            Account* from = Bank::getAccount(n);
            const Account* to = Bank::getAccount(e.num);
            const OneTimeTransfer tr = TransactionManager::createTransaction(QDateTime::currentDateTime(), *to, *from, e.value);
            AccountActions::makeTransaction(*from, tr);
            break;
        }
        case ATMEvent::RegularTransactionEvent: {
            auto e = dynamic_cast<const EventToATM::RegularTransaction &>(event);
            CARD_NUMBER_T n = atm_->getCardReader().getCardNum();
            Account* from = Bank::getAccount(n);
            const Account* to = Bank::getAccount(e.num);
            const RegularTransfer tr = TransactionManager::createTransaction(QDateTime::currentDateTime(), *to, *from, e.value, e.reg);
            AccountActions::makeTransaction(*from, tr);
            break;
        }
        case ATMEvent::PutCashMEvent: {
            auto e = dynamic_cast<const EventToATM::PutCashMEvent &>(event);
            Maintenance::putCash(atm_->getDispenser(), e.value);

            break;
        }
        case ATMEvent::TakeCashMEvent: {
            auto e = dynamic_cast<const EventToATM::TakeCashMEvent &>(event);
            Maintenance::takeCash(atm_->getDispenser(), e.value);
            break;
        }
        case ATMEvent::PINChangedEvent: {
            auto e = dynamic_cast<const EventToATM::PINChangedEvent &>(event);
            CARD_NUMBER_T n = atm_->getCardReader().getCardNum();
            PIN_T pin = Bank::getCard(n).getPIN();
            Account account = *(Bank::getAccount(n));
            const AccountManaging tr = TransactionManager::createTransaction(QDateTime::currentDateTime(), account,n,AccountManaging::ValueChanged::PIN,pin,e.value);
            AccountActions::makeTransaction(account, tr);
            break;
        }

        default:
            throw ATMException("Invalid event target!");
    }
}

void ATMIO::handleNotifyTargetATMController(const ATMEvent &event) const {
    switch (event.type) {
        case ATMEvent::ATMPowerStateEvent: {
            controller_->ATMPowerChangeFromATM(
                    dynamic_cast<const EventToATMController::ATMPowerStateEvent &>(event).value
            );
            break;
        }
        case ATMEvent::CardEvalResultEvent: {
            controller_->showCardEvalResult(
                    dynamic_cast<const EventToATMController::CardEvalResultEvent &>(event).value
            );
            break;
        }
        case ATMEvent::NewViewEvent: {
            controller_->navigateToNewView(dynamic_cast<const EventToATMController::NewViewEvent &>(event).value);
            break;
        }
        case ATMEvent::PINIsWrongEvent: {
            auto e = dynamic_cast<const EventToATM::PINIsWrong &>(event);
            controller_->changePINTries(e.value);
            break;
        }
        default:
            throw ATMException("Invalid event target!");
    }
}
