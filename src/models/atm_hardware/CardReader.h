//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_CARDREADER_H
#define MOOP_ATM_PROJECT_CARDREADER_H

#include "../../constants/ATMTypes.h"
#include "Hardware.h"

class PinVerificationService;

class CardReader : public ATM::Hardware {
private:
    bool cardIsInserted_;
    CARD_NUMBER_T inserted_card_n_;
    unsigned char evalTries;

    ATM *atm_;
    PinVerificationService *verificationService_;

    void onVerificationSuccess() const;
    void onVerificationFail();
    void blockCard();
    void acceptCard();


public:
    explicit CardReader(ATM &atm, bool isOp);
    ~CardReader() override;

    void evalPIN(PIN_T);
    void setInsertedCardN(CARD_NUMBER_T);
    void returnCard();

    CARD_NUMBER_T getCardNum(){return inserted_card_n_;}
    void setState(bool isOp) override;

    inline void reset() {
        cardIsInserted_ = false;
        inserted_card_n_ = 0;
        evalTries = 0;
    }
};

#endif //MOOP_ATM_PROJECT_CARDREADER_H
