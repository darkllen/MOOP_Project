//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMEVENT_H
#define MOOP_ATM_PROJECT_ATMEVENT_H

#include "../constants/Views.h"
#include "../constants/ATMTypes.h"

struct ATMEvent {
    enum EventType {
        ATMPowerStateEvent,
        NewDisplayStateEvent,
        CardReaderInputEvent,
        CardEvent
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


struct CardReaderInputEventToATM : public ATMEvent {
    CARD_NUMBER_T value;
    explicit CardReaderInputEventToATM(CARD_NUMBER_T n) : ATMEvent(EventType::CardReaderInputEvent, Target::ATM), value(n) {}
};


struct NewDisplayStateEventToATMIO : public ATMEvent {
    Views value;
    explicit NewDisplayStateEventToATMIO(Views s) : ATMEvent(EventType::NewDisplayStateEvent, Target::ATMIO), value(s) {}
};


struct CardEventToATMIO: public ATMEvent {
    enum Type {
        CardAccepted,
        InvalidCardInsertedEvent,
        CardBlockedEvent,
        CardReturnEvent
    };
    Type value;
    explicit CardEventToATMIO(Type eventType) : ATMEvent(EventType::CardEvent, Target::ATMIO), value(eventType) {}
};

#endif //MOOP_ATM_PROJECT_ATMEVENT_H
