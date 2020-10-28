//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_HARDWARE_H
#define MOOP_ATM_PROJECT_HARDWARE_H

#include "../../constants/ATMTypes.h"
#include "../../mediators/ATMIO.h"

class Hardware: public ATMBaseComponent {
protected:
    bool isOperational;
public:
    Hardware() : ATMBaseComponent(), isOperational(true) {}
    virtual ~Hardware() = default;

    bool getState() const { return isOperational; }
    void setState(bool isOp) { isOperational = isOp; }
};


#endif //MOOP_ATM_PROJECT_HARDWARE_H
