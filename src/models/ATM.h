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

    explicit ATM(const ATMInfo &atmInfo, const CASH_AMOUNT_T & initialCash, const bool& cardReaderState, const bool& dispenserState);
    //TODO realize
    ATM(const  ATM& atm) = default;
    ~ATM();

    void powerStateChange(ATMPowerState state);
    const ATMInfo& getATMInfo() const;

    CardReader& getCardReader();
    Dispenser& getDispenser();

    static ATM getATM(const ATM_SERIAL_NUMBER_T& num);

    bool getCardReaderStatus();
    void setCardReaderStatus(const bool&);
    bool getDispenserStatus();
    void setDispenserStatus(const bool&);

    void resetCardReader();

};


#endif //MOOP_ATM_PROJECT_ATM_H
