//
// Created by anna2 on 20.10.2020.
//
#include "CardReader.h"
#include "../../models/Bank.h"
#include "../../controllers/PinVerificationService.h"
#include "../../constants/ATMLimits.h"
#include "../DebitCard.h"
#include "../../exceptions/ATMException.h"


CardReader::CardReader()
        : Hardware(), cardIsInserted_(false), inserted_card_n_(0), evalTries(0),
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
    catch (const DBException e) {
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
        mediator_->Notify(CardEventToATMIO(CardEventToATMIO::Type::InvalidCardInsertedEvent));
    }
}

void CardReader::onVerificationSuccess() const {
    //TODO: Requires implementation
}

void CardReader::onVerificationFail() {
    ++evalTries;
    if (evalTries == ATMLimits::MAX_FAILED_PIN_EVALS) {
        blockCard();
    }
}

void CardReader::returnCard() {
    if (cardIsInserted_) {
        mediator_->Notify(CardEventToATMIO(CardEventToATMIO::Type::CardReturnEvent));
        reset();
    }
}

void CardReader::blockCard() {
    try {
        DebitCard debitCard = Bank::getCard(inserted_card_n_);
        debitCard.setIsBlocked(true);
    } catch (const DBException &e) {
        throw e;
    }
    mediator_->Notify(CardEventToATMIO(CardEventToATMIO::Type::CardBlockedEvent));
    reset();
}

void CardReader::acceptCard() {
    cardIsInserted_ = true;
    mediator_->Notify(CardEventToATMIO(CardEventToATMIO::Type::CardAccepted));
}
