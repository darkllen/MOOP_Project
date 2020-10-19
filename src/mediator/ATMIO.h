//
// Created by kuchm on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMIO_H
#define MOOP_ATM_PROJECT_ATMIO_H

#include <string>

//TODO: decitded ATMEvent structure and events
enum DialPadBtn {
    D000, D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, DDot
};

enum DisplaySideBtn {
    L0, L1, L2, L3, R0, R1, R2, R3
};

enum ControlBtn {
    Cancel, Clear, Enter, Empty
};

enum DisplayPowerState {
    ON, OFF
};

enum DisplayState {

};

struct ATMEvent {

};


class ATMBaseComponent;
class ATMMediator {
public:
    virtual void Notify(ATMBaseComponent &sender, const ATMEvent &event) const = 0;
};

class ATMBaseComponent {
protected:
    ATMMediator *mediator_;

public:
    explicit ATMBaseComponent(ATMMediator *mediator = nullptr) : mediator_(mediator) {}
    void setMediator(ATMMediator *mediator) {
        this->mediator_ = mediator;
    }
};

class ATM;
class ATMController;
class ATMIO : public ATMMediator {
private:
    ATM *atm_;
    ATMController *controller_;

public:
    explicit ATMIO(ATM &atm, ATMController &controller);
    void Notify(ATMBaseComponent &sender, const ATMEvent &event) const override;
};


#endif //MOOP_ATM_PROJECT_ATMIO_H
