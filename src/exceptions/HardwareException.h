//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_HARDWAREEXCEPTION_H
#define MOOP_ATM_PROJECT_HARDWAREEXCEPTION_H

#include <string>

#include "ATMException.h"

class HardwareException : public ATMException {
public:
    HardwareException(std::string): ATMException();
    ~HardwareException();
};

#endif //MOOP_ATM_PROJECT_HARDWAREEXCEPTION_H
