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

void ATMIO::Notify(const ATMEvent &event) const {
    if (event.target == ATMEvent::Target::ATM) {
        handleNotifyTargetATM(event);
    } else if (event.target == ATMEvent::Target::ATMIO) {
        handleNotifyTargetATMIO(event);
    }
}

void ATMIO::handleNotifyTargetATM(const ATMEvent &event) const {
    switch (event.type) {
        case ATMEvent::ATMPowerStateEvent: {
            auto e = dynamic_cast<const ATMPowerStateEvent &>(event);
            atm_->powerStateChange(e.value);
        }
            break;
        case ATMEvent::CardReaderInputEvent: {
            auto e = dynamic_cast<const CardReaderInputEventToATM &>(event);
            atm_->getCardReader().setInsertedCardN(e.value);
        }
            break;
        default:
            throw ATMException("Invalid event target!");
    }
}

void ATMIO::handleNotifyTargetATMIO(const ATMEvent &event) const {
    switch (event.type) {
        case ATMEvent::EventType::ATMPowerStateEvent:
            controller_->ATMPowerChange(dynamic_cast<const ATMPowerStateEvent &>(event).value);
            break;
        case ATMEvent::EventType::CardEvent:
            controller_->cardAnswerFromATM(dynamic_cast<const CardEventToATMIO &>(event).value);
            break;
        default:
            throw ATMException("Invalid event target!");
    }
}
