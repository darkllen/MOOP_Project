//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TESTER_H
#define MOOP_ATM_PROJECT_TESTER_H

#include "../controllers/ATMController.h"

class Tester {
private:

    ATM *atm;
    ATMController *controller;

public:
    Tester(ATM &, ATMController &);

    void testInput();
    void testOutput();
    void testDispenser();
    void testCardReader();
    void testSecurityCheck();
    void testTransactions();
    void testDBConnection();

};

#endif //MOOP_ATM_PROJECT_TESTER_H
