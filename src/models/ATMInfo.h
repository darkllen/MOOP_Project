#ifndef MOOP_ATM_PROJECT_ATMINFO_H
#define MOOP_ATM_PROJECT_ATMINFO_H

#include <string>

class ATMInfo {
private:
    ATM_SERIAL_NUMBER_T serialNumber_;
    std::string location_;

public:
    ATMInfo(const ATM_SERIAL_NUMBER_T& sn, std::string loc) :
            serialNumber_(sn), location_(std::move(loc)) {}

    ATM_SERIAL_NUMBER_T getSerialNumber() const {return serialNumber_;}
    std::string getLocation() const {return location_;}
};

#endif //MOOP_ATM_PROJECT_ATMINFO_H