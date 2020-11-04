//
// Created by Lemonderon on 25.10.2020.
//

#ifndef ATM_ATMDISPLAY_H
#define ATM_ATMDISPLAY_H

#include "../constants/Views.h"


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
    void reset();

    void navigateTo(Views view);
    void runJs(const QString& js);

    Views getCurrentScreen() const;
};


#endif //ATM_ATMDISPLAY_H
