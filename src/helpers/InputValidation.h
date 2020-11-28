//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_INPUTVALIDATION_H
#define MOOP_ATM_PROJECT_INPUTVALIDATION_H

#include <QtCore/qdatetime.h>
#include "../constants/ATMTypes.h"

namespace InputValidation {
    bool validatePin(const QString &);
    bool validateCashSum(const CASH_AMOUNT_T &, const CARD_NUMBER_T &);
    bool validateCardNumber(const CARD_NUMBER_T &);
};

#endif //MOOP_ATM_PROJECT_INPUTVALIDATION_H
