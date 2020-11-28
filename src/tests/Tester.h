//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TESTER_H
#define MOOP_ATM_PROJECT_TESTER_H

#include "../models/ATM.h"
#include "../controllers/ATMController.h"

class Tester {
private:
    ATM *_atm;
public:
    explicit Tester(ATM &atm);
    void testEval();
    void testOutput();
    void testDispenser();
    void testCardReader();
    void testTransactions();
};


#endif //MOOP_ATM_PROJECT_TESTER_H
