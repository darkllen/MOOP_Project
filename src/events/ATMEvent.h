//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMEVENT_H
#define MOOP_ATM_PROJECT_ATMEVENT_H

#include "../constants/Views.h"
#include "../constants/ATMTypes.h"

struct ATMEvent {
    enum EventType {
        ATMPowerStateEvent, NewDisplayStateEvent, CardReaderInputEvent
    };
    enum Target {
        ATM, ATMIO
    };
    EventType type;
    Target target;
    explicit ATMEvent(EventType eventType, Target eventTarget) : type(eventType), target(eventTarget) {}
    virtual ~ATMEvent() = default;
};


struct ATMPowerStateEvent : public ATMEvent {
    enum PowerState {
        On, Off
    };
    PowerState value;
    explicit ATMPowerStateEvent(PowerState e, Target t) : ATMEvent(EventType::ATMPowerStateEvent, t), value(e) {}
};


struct CardReaderInputEvent : public ATMEvent {
    CARD_NUMBER_T value;
    CardReaderInputEvent(CARD_NUMBER_T n) : ATMEvent(EventType::CardReaderInputEvent, Target::ATM), value(n) {}
};


struct NewDisplayStateEvent : public ATMEvent {
    Views value;
    NewDisplayStateEvent(Views s) : ATMEvent(EventType::NewDisplayStateEvent, Target::ATMIO), value(s) {}
};


#endif //MOOP_ATM_PROJECT_ATMEVENT_H
