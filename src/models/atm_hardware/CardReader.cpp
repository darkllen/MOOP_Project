//
// Created by anna2 on 20.10.2020.
//
#include "CardReader.h"
#include "../../models/Bank.h"
#include "../../controllers/PinVerificationService.h"
#include "../../constants/ATMLimits.h"
#include "../DebitCard.h"
#include "../../exceptions/ATMException.h"
#include "../../models/ATMInfo.h"
#include "../../controllers/DBConnection.h"
#include "../../events/ATMEvent.h"

CardReader::CardReader(ATM &atm, const bool& isOp)
        : Hardware(atm, isOp), cardIsInserted_(false), inserted_card_n_(0), evalTries(0), atm_(&atm){}

void CardReader::evalPIN(const PIN_T& pin) {
    try {
        bool verificationResult = PinVerificationService::verify(inserted_card_n_, pin);
        verificationResult ? onVerificationSuccess() : onVerificationFail();
    }
    catch (const DBException& e) {
        atm_->getMediator()->Notify(*atm_, EventToATMController::ATMDBConnectionErrorEvent());
    }
}

void CardReader::setInsertedCardN(const CARD_NUMBER_T& n) {
    inserted_card_n_ = n;
    try {
        DebitCard debitCard = Bank::getCard(inserted_card_n_);
        if (debitCard.getIsBlocked()) {
            blockCard();
        } else {
            acceptCard();
        }
    } catch (const DBException &e) {
        reset();
        parent_.getMediator()->Notify(*atm_, EventToATMController::CardEvalResultEvent
                (EventToATMController::CardEvalResultEvent::Result::CardIsInvalid)
        );
    }
}

void CardReader::onVerificationSuccess() const {
    parent_.getMediator()->Notify(*atm_, EventToATMController::CardEvalResultEvent
            (EventToATMController::CardEvalResultEvent::Result::CardIsAccepted)
    );
}

void CardReader::onVerificationFail() {
    ++evalTries;
    if (evalTries == ATMLimits::MAX_FAILED_PIN_EVALS) {
        blockCard();
    }
    parent_.getMediator()->Notify(*atm_, EventToATM::PINIsWrong (evalTries)
    );
}

void CardReader::returnCard() {
    assert(cardIsInserted_);
    reset();
}

void CardReader::blockCard() {
    try {
        DebitCard debitCard = Bank::getCard(inserted_card_n_);
        debitCard.setIsBlocked(true);
    } catch (const DBException &e) {
        atm_->getMediator()->Notify(*atm_, EventToATMController::ATMDBConnectionErrorEvent());
    }
    parent_.getMediator()->Notify(*atm_, EventToATMController::CardEvalResultEvent
            (EventToATMController::CardEvalResultEvent::Result::CardIsBlocked)
    );
    reset();
}

void CardReader::acceptCard() {
    cardIsInserted_ = true;
    parent_.getMediator()->Notify(*atm_, EventToATMController::CardEvalResultEvent
            (EventToATMController::CardEvalResultEvent::Result::CardPINChecking)
    );
}

void CardReader::setState(const bool& isOp) {
    isOperational_ = isOp ;
    DBConnection connection;
    mysqlx::Table atmInfo = connection.getTable("ATMInfo");

    atmInfo.update().set("cardReaderState", isOperational_).
            where("serialNumber_ like :serialNumber_").
            bind("serialNumber_", parent_.getATMInfo().getSerialNumber()).execute();
}
