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

    bool isLocked_;

public:
    explicit ATMDisplay(QWebEngineView& webEngineView);
    ~ATMDisplay() = default;

    void turnOn();
    void turnOff();
    void reset();

    void navigateTo(Views view);
    void runJs(const QString& js);

    Views getCurrentScreen() const;

    bool getIsLocked(){return isLocked_;}
    bool getIsOn(){return isOn_;}
};


#endif //ATM_ATMDISPLAY_H
