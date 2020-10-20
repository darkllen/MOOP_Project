#ifndef MOOP_ATM_PROJECT_CUSTOMER_H
#define MOOP_ATM_PROJECT_CUSTOMER_H

#include <string>

class Account;
class Customer {
private:

    std::string name_;
    std::string address_;
    Account *accounts_;

public:
    Customer(std::string name, std::string address, Account *accounts) :
            name_(std::move(name)), address_(std::move(address)), accounts_(accounts) {}
    ~Customer() = default;
};

#endif //MOOP_ATM_PROJECT_CUSTOMER_H
