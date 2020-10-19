#ifndef MOOP_ATM_PROJECT_ATMINFO_H
#define MOOP_ATM_PROJECT_ATMINFO_H

#include <string>

class ATMInfo {
private:
    ATM_SERIAL_N_T serialNumber_;
    std::string location_;
    std::string managedBy_;

public:
    ATMInfo(ATM_SERIAL_N_T sn, std::string loc, std::string managedBy) :
            serialNumber_(sn), location_(std::move(loc)), managedBy_(std::move(managedBy)) {}
};

#endif //MOOP_ATM_PROJECT_ATMINFO_H