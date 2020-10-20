//
// Created by Lemonderon on 20.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMLIMITS_H
#define MOOP_ATM_PROJECT_ATMLIMITS_H

#include "ATMTypes.h"

namespace ATMLimits {
    const unsigned char MAX_FAILED_PIN_EVALS = 3;
    const CASH_AMOUNT_T MAX_CASH_AMOUNT_IN_DISPENSER = 100000;
    const unsigned int MAX_SESSION_IDLE_TIME_SEC = 30;
};


#endif //MOOP_ATM_PROJECT_ATMLIMITS_H
