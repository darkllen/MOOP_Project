//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATM_H
#define MOOP_ATM_PROJECT_ATM_H

#include "../mediators/ATMIO.h"
#include "TransactionManager.h"
#include "Dispenser.h"
#include "CardReader.h"
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
};


#endif //MOOP_ATM_PROJECT_ATM_H
