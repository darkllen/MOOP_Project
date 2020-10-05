//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATM_H
#define MOOP_ATM_PROJECT_ATM_H

#include "../controller/ATMIO.h"

//TODO: Discuss the probability of making ATM class a singleton

class ATM {
private:
    ATMIO *io_;
public:
    ATM();
    ~ATM();

    ATMIO &getIO();
};


#endif //MOOP_ATM_PROJECT_ATM_H
