//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_MAINTENANCE_H
#define MOOP_ATM_PROJECT_MAINTENANCE_H

#include "../constants/ATMTypes.h"

class Hardware;
class Dispenser;

class Maintenance {
public:
    Maintenance() = default;
    ~Maintenance() = default;

    static void putCash(Dispenser &, CASH_AMOUNT_T);
    static void takeCash(Dispenser &, CASH_AMOUNT_T);
    static bool checkStatus(const Hardware &);
    static void changeStatus(Hardware &, bool);
};

#endif //MOOP_ATM_PROJECT_MAINTENANCE_H
