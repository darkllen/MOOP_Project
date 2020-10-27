//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATM_H
#define MOOP_ATM_PROJECT_ATM_H

#include "../constants/ATMTypes.h"
#include "../mediators/ATMIO.h"
#include "TransactionManager.h"
#include "atm_hardware/Dispenser.h"
#include "atm_hardware/CardReader.h"
#include "ATMInfo.h"
#include "SessionManager.h"

class ATM : public ATMBaseComponent {
private:

    bool isPoweredOn_;

    const ATMInfo *atmInfo_;

    Dispenser *dispenser_;
    CardReader *cardReader_;

    TransactionManager *tsManager_;
    SessionManager *sessionManager_;

public:

    explicit ATM(const ATMInfo &atmInfo, unsigned __int32 initialCash);
    ~ATM();

    void powerOn();
    void powerOff();

    const ATMInfo& getATMInfo() const;

    CardReader& getCardReader();
    Dispenser& getDispenser();
};


#endif //MOOP_ATM_PROJECT_ATM_H
