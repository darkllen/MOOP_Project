#ifndef MOOP_ATM_PROJECT_ATMINFO_H
#define MOOP_ATM_PROJECT_ATMINFO_H

#include <string>

class ATMInfo {
private:
    unsigned int serialNumber_;
    std::string location_;
    std::string managedBy_;
    unsigned int availableCashAmount_;
public:
    ATMInfo(unsigned int, std::string, std::string, unsigned int);
};

#endif //MOOP_ATM_PROJECT_ATMINFO_H