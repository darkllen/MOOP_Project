//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMEXCEPTION_H
#define MOOP_ATM_PROJECT_ATMEXCEPTION_H

#include <string>
#include <stdexcept>

class ATMException : public std::exception {
private:
    std::runtime_error m;

public:
    explicit ATMException(const char *msg) : m(msg) {}

    const char *what() const noexcept override {
        return m.what();
    }
};

#endif //MOOP_ATM_PROJECT_ATMEXCEPTION_H
