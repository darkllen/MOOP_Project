#ifndef MOOP_ATM_PROJECT_CUSTOMER_H
#define MOOP_ATM_PROJECT_CUSTOMER_H

#include <string>

class Account;

class Customer {
private:

    std::string name_;
    std::string address_;

public:
    Customer(std::string name, std::string address) :
            name_(std::move(name)), address_(std::move(address)) {}
    ~Customer() = default;

    std::string getName() { return name_; }
    std::string getAddress() { return address_; }
};

#endif //MOOP_ATM_PROJECT_CUSTOMER_H
