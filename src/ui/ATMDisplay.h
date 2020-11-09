//
// Created by Lemonderon on 25.10.2020.
//

#ifndef ATM_ATMDISPLAY_H
#define ATM_ATMDISPLAY_H

#include "../constants/Views.h"


class QWebEngineView;

class ATMDisplay {
private:
    QWebEngineView *webEngineView_;
    Views currentScreen_;
    bool isOn_;

    QString receipt = "";

public:
    explicit ATMDisplay(QWebEngineView &webEngineView);
    ~ATMDisplay() {
        delete webEngineView_;
        webEngineView_ = nullptr;
    };

    void turnOn();
    void turnOff();

    void navigateTo(Views view);
    void runJs(const QString &js);

    Views getCurrentScreen() const;

    bool getIsOn() const { return isOn_; }
    QString getReceipt() { return receipt; }
    void setReceipt(const QString &s) { receipt = s; }

    static bool waitForLoad(QWebEngineView &view);
};


#endif //ATM_ATMDISPLAY_H
