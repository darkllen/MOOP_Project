//
// Created by kuchm on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMIO_H
#define MOOP_ATM_PROJECT_ATMIO_H

#include "../events/ATMEvent.h"

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

    void handleNotifyTargetATM(const ATMEvent &event) const;
    void handleNotifyTargetATMIO(const ATMEvent &event) const;

public:
    ATMIO(ATM &atm, ATMController &controller);
    void Notify(ATMBaseComponent &sender, const ATMEvent &event) const override;
};


#endif //MOOP_ATM_PROJECT_ATMIO_H
