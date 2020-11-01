//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_HARDWARE_H
#define MOOP_ATM_PROJECT_HARDWARE_H

#include "../../constants/ATMTypes.h"
#include "../../mediators/ATMIO.h"
#include "../../models/ATM.h"

class ATM::Hardware {
protected:
    ATM &parent_;
    bool isOperational_;
public:
    explicit Hardware(ATM &parent) : parent_(parent), isOperational_(true) {}
    virtual ~Hardware() = default;

    bool getState() const { return isOperational_; }
    void setState(bool isOp) { isOperational_ = isOp; }
};


#endif //MOOP_ATM_PROJECT_HARDWARE_H
