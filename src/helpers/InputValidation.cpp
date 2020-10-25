//
// Created by anna2 on 25.10.2020.
//

#include <QtCore/qdatetime.h>
#include "../constants/ATMTypes.h"
#include "InputValidation.h"

bool InputValidation::validatePin(PIN_T);

bool InputValidation::validateTimePeriod(const QDateTime &begin, const QDateTime &end){
    return begin<end;
}

bool InputValidation::validateCashSum(CASH_AMOUNT_T);

bool InputValidation::validatePersonName(QString &s);

bool InputValidation::validateCardNumber(CARD_NUMBER_T);
