//
// Created by Lemonderon on 25.10.2020.
//

#ifndef ATM_ATMDISPLAY_H
#define ATM_ATMDISPLAY_H

#include "../events/DisplayEvent.h"

class QWebEngineView;

class ATMDisplay {
private:
    QWebEngineView* webEngineView_;
    Views currentScreen_;
    bool isOn_;

public:
    explicit ATMDisplay(QWebEngineView& webEngineView);
    ~ATMDisplay() = default;

    void turnOn();
    void turnOff();

    void navigateTo(const NewDisplayStateEventToATMIO&);
    void showCardEventAsync(CardEventToATMIO::Type type);

    Views getCurrentScreen() const;
};

extern void showCardEventOnDisplay(ATMDisplay& d, CardEventToATMIO::Type t);

#endif //ATM_ATMDISPLAY_H
