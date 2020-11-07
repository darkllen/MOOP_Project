//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_INPUTVALIDATION_H
#define MOOP_ATM_PROJECT_INPUTVALIDATION_H

#include <QtCore/qdatetime.h>
#include "../constants/ATMTypes.h"

namespace InputValidation {
    bool validatePin(PIN_T);
    bool validateTimePeriod(const QDateTime &begin, const QDateTime &end);
    bool validateCashSum(CASH_AMOUNT_T, CARD_NUMBER_T);
    bool validatePersonName(QString &s);
    bool validateCardNumber(CARD_NUMBER_T);
};

#endif //MOOP_ATM_PROJECT_INPUTVALIDATION_H
