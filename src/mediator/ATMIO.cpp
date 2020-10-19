//
// Created by Lemonderon on 19.10.2020.
//

#include "ATMIO.h"
#include "../model/ATM.h"


ATMIO::ATMIO(ATM &atm, ATMController &controller): atm_(&atm), controller_(&controller)  {
    this->atm_->setMediator(this);
    this->controller_->setMediator(this);
}

void ATMIO::Notify(ATMBaseComponent &sender, const ATMEvent &event) const {
    //TODO: implement communications by events
//    if (event == "A") {
//        std::cout << "Mediator reacts on A and triggers following operations:\n";
//        this->component2_->DoC();
//    }
//    if (event == "D") {
//        std::cout << "Mediator reacts on D and triggers following operations:\n";
//        this->component1_->DoB();
//        this->component2_->DoC();
//    }
}
