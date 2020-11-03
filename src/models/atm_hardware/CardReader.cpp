//
// Created by anna2 on 20.10.2020.
//
#include "CardReader.h"
#include "../../models/Bank.h"
#include "../../controllers/PinVerificationService.h"
#include "../../constants/ATMLimits.h"
#include "../DebitCard.h"
#include "../../exceptions/ATMException.h"

CardReader::CardReader(ATM &atm)
        : Hardware(atm), cardIsInserted_(false), inserted_card_n_(0), evalTries(0), atm_(&atm),
          verificationService_(new PinVerificationService) {}

CardReader::~CardReader() {
    delete verificationService_;
    verificationService_ = nullptr;
}

void CardReader::evalPIN(const PIN_T pin) {
    try {
        bool verificationResult = verificationService_->verify(inserted_card_n_, pin);
        verificationResult ? onVerificationSuccess() : onVerificationFail();
    }
    catch (const DBException& e) {
        //Todo: wrong card
    }
}

void CardReader::setInsertedCardN(const CARD_NUMBER_T n) {
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
        );        //TODO: requires proper implementation
    }
}

void CardReader::onVerificationSuccess() const {
    parent_.getMediator()->Notify(*atm_, EventToATMController::CardEvalResultEvent
            (EventToATMController::CardEvalResultEvent::Result::CardIsAccepted)
    );
}

//TODO show how many tries left on screen (yes, new views...)
void CardReader::onVerificationFail() {
    ++evalTries;
    if (evalTries == ATMLimits::MAX_FAILED_PIN_EVALS) {
        blockCard();
    }
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
        //TODO: requires proper implementation
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
