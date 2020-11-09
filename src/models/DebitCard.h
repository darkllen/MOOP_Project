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
    DebitCard(const CARD_NUMBER_T& cardNum, QDateTime  expireDate, const CVV_T& cvvCode, const PIN_T& pin, const bool& isBlocked=true) :
            cardNum_(cardNum), expireDate_(std::move(expireDate)), cvvCode_(cvvCode), pin_(pin), isBlocked_(isBlocked) {}
    ~DebitCard() = default;

    PIN_T getPIN() const{return pin_;}
    void setIsBlocked(bool value);
    bool getIsBlocked() const{return isBlocked_;}
};

#endif //MOOP_ATM_PROJECT_DEBITCARD_H
