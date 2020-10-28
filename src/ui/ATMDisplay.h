//
// Created by Lemonderon on 25.10.2020.
//

#ifndef ATM_ATMDISPLAY_H
#define ATM_ATMDISPLAY_H

#include "../events/ATMEvent.h"

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
    Views getCurrentScreen();
};


#endif //ATM_ATMDISPLAY_H
