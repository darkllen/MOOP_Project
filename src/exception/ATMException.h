//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMEXCEPTION_H
#define MOOP_ATM_PROJECT_ATMEXCEPTION_H

#include <string>

class ATMException{
private:
    std::string message_;
public:
    ATMException(std::string);
    ~ATMException();

    void printException();
};

#endif //MOOP_ATM_PROJECT_ATMEXCEPTION_H
