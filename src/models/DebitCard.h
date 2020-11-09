#ifndef MOOP_ATM_PROJECT_DEBITCARD_H
#define MOOP_ATM_PROJECT_DEBITCARD_H

#include <ctime>
#include <utility>
#include <QtCore/qdatetime.h>

#include "../constants/ATMTypes.h"

class DebitCard {
private:
    CARD_NUMBER_T cardNum_;
    QDateTime expireDate_;
    CVV_T cvvCode_;
    PIN_T pin_;
    bool isBlocked_;

public:
    DebitCard(CARD_NUMBER_T cardNum, QDateTime expireDate, CVV_T cvvCode, PIN_T pin, bool isBlocked = true) :
            cardNum_(cardNum), expireDate_(std::move(expireDate)), cvvCode_(cvvCode), pin_(pin),
            isBlocked_(isBlocked) {}
    ~DebitCard() = default;

    //TODO make it private and friend of PINVerification
    PIN_T getPIN() { return pin_; }

    void setIsBlocked(bool value);
    bool getIsBlocked() { return isBlocked_; }
};

#endif //MOOP_ATM_PROJECT_DEBITCARD_H
