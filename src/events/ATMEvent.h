//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMEVENT_H
#define MOOP_ATM_PROJECT_ATMEVENT_H

struct ATMEvent {
    enum EventType {
        ATMPowerStateEvent, NewDisplayStateEvent
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

struct NewDisplayStateEvent : public ATMEvent {
    enum NewScreen {
        Welcome, PINEntering, CardEaten, MainMenu
    };
    NewScreen value;
    NewDisplayStateEvent(NewScreen s) : ATMEvent(EventType::NewDisplayStateEvent, Target::ATMIO), value(s) {}
};


#endif //MOOP_ATM_PROJECT_ATMEVENT_H
