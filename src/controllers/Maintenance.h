//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_MAINTENANCE_H
#define MOOP_ATM_PROJECT_MAINTENANCE_H

#include "../constants/ATMTypes.h"
#include "../models/ATM.h"


class Maintenance {
public:
    Maintenance() = default;
    ~Maintenance() = default;

    static void putCash(Dispenser &, const CASH_AMOUNT_T &);
    static void takeCash(Dispenser &, const CASH_AMOUNT_T &);
    static bool checkStatus(const ATM::Hardware &);
    static void changeStatus(ATM::Hardware &, const bool &);
};

#endif //MOOP_ATM_PROJECT_MAINTENANCE_H
