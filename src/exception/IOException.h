//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_IOEXCEPTION_H
#define MOOP_ATM_PROJECT_IOEXCEPTION_H
#include <string>
class ATMException;
class IOException: public ATMException{
public:
    IOException(std::string);
    ~IOException();
};

#endif //MOOP_ATM_PROJECT_IOEXCEPTION_H
