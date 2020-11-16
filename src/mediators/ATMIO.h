//
// Created by kuchm on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMIO_H
#define MOOP_ATM_PROJECT_ATMIO_H

#include "../events/ATMEvent.h"

class ATMBaseComponent;
class ATMMediator {
public:
    virtual void Notify(const ATMBaseComponent &sender, const ATMEvent &event) const = 0;
};

class ATMBaseComponent {
private:
    ATMMediator *mediator_;

public:
    explicit ATMBaseComponent(ATMMediator *mediator = nullptr) : mediator_(mediator) {}
    void setMediator(ATMMediator *mediator) {
        this->mediator_ = mediator;
    }

    ATMMediator *getMediator() {
        return this->mediator_;
    }
};

class ATM;
class ATMController;
class ATMIO : public ATMMediator {
private:
    ATM *atm_;
    ATMController *controller_;

    void handleNotifyTargetATM(const ATMEvent &event) const;
    void handleNotifyTargetATMController(const ATMEvent &event) const;

public:
    ATMIO(ATM &atm, ATMController &controller);
    void Notify(const ATMBaseComponent &sender, const ATMEvent &event) const override;
    ATM &getATM() { return *atm_; }
};


#endif //MOOP_ATM_PROJECT_ATMIO_H
