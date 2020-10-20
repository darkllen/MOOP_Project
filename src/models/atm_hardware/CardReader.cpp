//
// Created by anna2 on 20.10.2020.
//
#include "CardReader.h"
#include "../../constants/ATMTypes.h"
#include "../../controllers/PinVerificationService.h"
#include "../../constants/ATMLimits.h"

CardReader::CardReader() : inserted_card_n_(0), evalTries(0), verificationService_(new PinVerificationService) {}

CardReader::~CardReader() {
    delete verificationService_;
    verificationService_ = nullptr;
}

void CardReader::evalPIN(const PIN_T pin) {
    bool verificationResult = verificationService_->verify(inserted_card_n_, pin);
    verificationResult ? onVerificationSuccess() : onVerificationFail();
}

void CardReader::setInsertedCardN(const CARD_NUMBER_T n) {
    inserted_card_n_ = n;
}

void CardReader::onVerificationSuccess() const {
    //TODO: Requires implementation
}

void CardReader::onVerificationFail() {
    ++evalTries;
    if (evalTries == ATMLimits::MAX_FAILED_PIN_EVALS){
        // block the card and don't return it
        //TODO: Requires implementation
        reset();
    }
    //TODO: Requires implementation
}

bool CardReader::returnCard() {
    bool res = inserted_card_n_ != 0;
    if (res) reset();
    return res;
}
