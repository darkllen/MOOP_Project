//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMEVENT_H
#define MOOP_ATM_PROJECT_ATMEVENT_H

#include "../constants/Views.h"
#include "../constants/ATMTypes.h"
#include "UIInput.h"

struct ATMEvent {
    enum EventType {
        ATMPowerStateEvent,
        CardEvalResultEvent,
        CardInsertedEvent,
        CardTakenEvent,
        NewViewEvent,
        PINSubmittedEvent,
        PutCashEvent,
        TakeCashEvent,
        PINChangedEvent,
        PINIsWrong,

        PutCashMEvent,
        TakeCashMEvent,

    };
    EventType type;
    explicit ATMEvent(EventType eventType) : type(eventType) {}
    virtual ~ATMEvent() = default;
};

namespace EventToATM {
    struct ATMPowerStateEvent: public ATMEvent {
        ATMPowerState value;
        explicit ATMPowerStateEvent(ATMPowerState e) : ATMEvent(EventType::ATMPowerStateEvent), value(e) {}
    };

    struct PINSubmittedEvent : public ATMEvent {
        PIN_T value;
        explicit PINSubmittedEvent(PIN_T n) : ATMEvent(EventType::PINSubmittedEvent), value(n) {}
    };

    struct CardInsertedEvent : public ATMEvent {
        CARD_NUMBER_T value;
        explicit CardInsertedEvent(CARD_NUMBER_T n) : ATMEvent(EventType::CardInsertedEvent), value(n) {}
    };

    struct CardTakenEvent : public ATMEvent {
        explicit CardTakenEvent() : ATMEvent(EventType::CardTakenEvent) {}
    };

    struct PutCashEvent : public ATMEvent {
        CASH_AMOUNT_T value;
        explicit PutCashEvent(CASH_AMOUNT_T n) : ATMEvent(EventType::PutCashEvent), value(n) {}
    };
    struct TakeCashEvent : public ATMEvent {
        CASH_AMOUNT_T value;
        explicit TakeCashEvent(CASH_AMOUNT_T n) : ATMEvent(EventType::TakeCashEvent), value(n) {}
    };
    struct PINChangedEvent : public ATMEvent {
        PIN_T value;
        explicit PINChangedEvent(PIN_T n) : ATMEvent(EventType::PINChangedEvent), value(n) {}
    };
    struct PINIsWrong : public ATMEvent {
        int value;
        explicit PINIsWrong(int n) : ATMEvent(EventType::PINIsWrong), value(n) {}
    };

    struct PutCashMEvent : public ATMEvent {
        CASH_AMOUNT_T value;
        explicit PutCashMEvent(CASH_AMOUNT_T n) : ATMEvent(EventType::PutCashMEvent), value(n) {}
    };
    struct TakeCashMEvent : public ATMEvent {
        CASH_AMOUNT_T value;
        explicit TakeCashMEvent(CASH_AMOUNT_T n) : ATMEvent(EventType::TakeCashMEvent), value(n) {}
    };
};

namespace EventToATMController {
    struct ATMPowerStateEvent: public ATMEvent {
        ATMPowerState value;
        explicit ATMPowerStateEvent(ATMPowerState e) : ATMEvent(EventType::ATMPowerStateEvent), value(e) {}
    };

    struct CardEvalResultEvent : public ATMEvent {
        enum Result {
            CardIsAccepted,
            CardIsInvalid,
            CardIsBlocked,
            CardPINChecking
        };
        Result value;
        explicit CardEvalResultEvent(Result eventType) :
                ATMEvent(EventType::CardEvalResultEvent),
                value(eventType) {}
    };


    struct NewViewEvent : public ATMEvent {
        Views value;
        explicit NewViewEvent(Views s) : ATMEvent(EventType::NewViewEvent), value(s) {}
    };
}

#endif //MOOP_ATM_PROJECT_ATMEVENT_H
