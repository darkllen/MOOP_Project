//
// Created by Lemonderon on 19.10.2020.
//

#include <QDebug>

#include "ATMIO.h"
#include "../models/ATM.h"
#include "../controllers/ATMController.h"
#include "../exceptions/ATMException.h"


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
        default:
            throw ATMException("Invalid event target!");
    }
}
