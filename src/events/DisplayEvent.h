//
// Created by Lemonderon on 29.10.2020.
//

#ifndef ATM_DISPLAYEVENT_H
#define ATM_DISPLAYEVENT_H

#include "ATMEvent.h"

struct NewDisplayStateEventToATMIO : public ATMEvent {
    Views value;
    explicit NewDisplayStateEventToATMIO(Views s) : ATMEvent(EventType::CardEvent, Target::ATMIO), value(s) {}
};

struct CardEventDisplayState : public NewDisplayStateEventToATMIO {
    CardEventToATMIO::Type type;
    explicit CardEventDisplayState(CardEventToATMIO::Type t) : NewDisplayStateEventToATMIO(CardEventScreen), type(t) {}
};

#endif //ATM_DISPLAYEVENT_H
