#ifndef MOOP_ATM_PROJECT_DEBITCARD_H
#define MOOP_ATM_PROJECT_DEBITCARD_H

#include <ctime>
#include <QtCore/qdatetime.h>

#include "../constants/ATM_Types.h"

class DebitCard {
private:
    CARD_NUMBER_T cardNum_;
    QDateTime expireDate_;
    CVV_T cvCode_;
    PIN_T PIN_;

public:
    DebitCard(CARD_NUMBER_T, const QDateTime &, CVV_T, PIN_T);
    ~DebitCard();
};

#endif //MOOP_ATM_PROJECT_DEBITCARD_H
