//
// Created by Lemonderon on 25.10.2020.
//

#ifndef ATM_ATMDISPLAY_H
#define ATM_ATMDISPLAY_H

class QWebEngineView;

class ATMDisplay {
private:
    QWebEngineView* webEngineView_;

public:
    explicit ATMDisplay(QWebEngineView& webEngineView);
    ~ATMDisplay() = default;

    void turnOn();
    void turnOff();
};


#endif //ATM_ATMDISPLAY_H
