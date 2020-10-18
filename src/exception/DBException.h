//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_DBEXCEPTION_H
#define MOOP_ATM_PROJECT_DBEXCEPTION_H
#include <string>
class ATMException;
class DBException: public ATMException{
public:
    DBException(std::string);
    ~DBException();
};

#endif //MOOP_ATM_PROJECT_DBEXCEPTION_H
