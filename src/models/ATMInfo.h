#ifndef MOOP_ATM_PROJECT_ATMINFO_H
#define MOOP_ATM_PROJECT_ATMINFO_H

#include <string>

class ATMInfo {
private:
    ATM_SERIAL_N_T serialNumber_;
    std::string location_;
    std::string managedBy_;
    int availableCashAmount_;

public:
    ATMInfo(ATM_SERIAL_N_T sn, std::string loc, std::string managedBy) :
            serialNumber_(sn), location_(std::move(loc)), managedBy_(std::move(managedBy)) {}

    void setAvailableCashAmount(int amount){availableCashAmount_ = amount;};
    int getAvailableCashAmount(){return availableCashAmount_};
};

#endif //MOOP_ATM_PROJECT_ATMINFO_H