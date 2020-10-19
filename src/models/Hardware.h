//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_HARDWARE_H
#define MOOP_ATM_PROJECT_HARDWARE_H

#include "../constants/ATM_Types.h"

class Hardware {
protected:
    bool isOperational;
public:
    Hardware() = default;
    virtual ~Hardware() = default;
};


#endif //MOOP_ATM_PROJECT_HARDWARE_H
