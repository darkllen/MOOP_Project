//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_CARDREADER_H
#define MOOP_ATM_PROJECT_CARDREADER_H

#include "../../constants/ATMTypes.h"

class PinVerificationService;

class CardReader {
private:
    CARD_NUMBER_T inserted_card_n_;
    unsigned char evalTries;

    PinVerificationService * verificationService_;

    void onVerificationSuccess() const;
    void onVerificationFail();
    inline void reset() { inserted_card_n_ = 0; evalTries = 0; }

public:
    CardReader();
    ~CardReader();

    void evalPIN(PIN_T);
    void setInsertedCardN(CARD_NUMBER_T);
    bool returnCard();
};

#endif //MOOP_ATM_PROJECT_CARDREADER_H
