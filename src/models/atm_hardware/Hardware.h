//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_HARDWARE_H
#define MOOP_ATM_PROJECT_HARDWARE_H

#include "../../constants/ATMTypes.h"

class Hardware {
protected:
    bool isOperational;
public:
    Hardware() : isOperational(true) {}
    virtual ~Hardware() = default;

    bool getState() const { return isOperational; }
    bool setState(bool isOp) { return isOperational = isOp; }
};


#endif //MOOP_ATM_PROJECT_HARDWARE_H
