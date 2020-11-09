//
// Created by Lemonderon on 25.10.2020.
//

#ifndef ATM_ATMDISPLAY_H
#define ATM_ATMDISPLAY_H

#include "views/Views.h"
#include <any>



class QWebEngineView;

class ATMDisplay {
private:
    QWebEngineView *webEngineView_;

    ScreenEnum currentScreen_;

    bool isPoweredOn_;
    bool isLocked_;
    QString receipt = "";

public:
    explicit ATMDisplay(QWebEngineView &webEngineView);
    ~ATMDisplay() = default;

    void turnOn();
    void turnOff();

    void navigateTo(ScreenEnum sc);

    ScreenEnum getCurrentScreen() { return currentScreen_; }

    bool getIsLocked() const { return isLocked_; }
    bool getIsPoweredOn() const { return isPoweredOn_; }

    QString getReceipt() { return receipt; }
    void setReceipt(QString s) { receipt = std::move(s); }

    static bool waitForLoad(QWebEngineView &view);
};


#endif //ATM_ATMDISPLAY_H
