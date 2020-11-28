#ifndef MOOP_ATM_PROJECT_PINVERIFICATIONSERVICE_H
#define MOOP_ATM_PROJECT_PINVERIFICATIONSERVICE_H

#include "../constants/ATMTypes.h"
#include "../models/ATM.h"

class PinVerificationService {
public :
    PinVerificationService() = default;
    ~PinVerificationService() = default;

    static bool verify(const CARD_NUMBER_T &, const PIN_T &);
};

#endif //MOOP_ATM_PROJECT_PINVERIFICATIONSERVICE_H