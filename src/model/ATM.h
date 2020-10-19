//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATM_H
#define MOOP_ATM_PROJECT_ATM_H

#include "../controller/ATMQtUiController.h"
#include "../mediator/ATMIO.h"

class ATM : public ATMBaseComponent {
private:
    bool _isPoweredOn;
public:
    explicit ATM();
    ~ATM() {};

    void powerOn();
    void powerOff();
};


#endif //MOOP_ATM_PROJECT_ATM_H
