//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATM_H
#define MOOP_ATM_PROJECT_ATM_H

#include "../constants/ATMTypes.h"
#include "../mediators/ATMIO.h"

class ATMInfo;
class Dispenser;
class CardReader;
class TransactionManager;
class SessionManager;

class ATM: public ATMBaseComponent {
private:

    bool isPoweredOn_;

    const ATMInfo *atmInfo_;

    Dispenser *dispenser_;
    CardReader *cardReader_;

    TransactionManager *tsManager_;
    SessionManager *sessionManager_;

public:
    class Hardware;

    explicit ATM(const ATMInfo &atmInfo, unsigned __int32 initialCash);
    ~ATM();

    void powerStateChange(ATMPowerState state);
    const ATMInfo& getATMInfo() const;

    CardReader& getCardReader();
    Dispenser& getDispenser();
};


#endif //MOOP_ATM_PROJECT_ATM_H
