//
// Created by Lemonderon on 20.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMQTDISPLAYCONTROLLER_H
#define MOOP_ATM_PROJECT_ATMQTDISPLAYCONTROLLER_H

#include <QtCore/QObject>

class QWebEngineView;
class ATMQtUiController;

class ATMQtDisplayController : public QObject {
Q_OBJECT
private:
    ATMQtUiController *uiController_;
public:
    explicit ATMQtDisplayController(ATMQtUiController &uiController);
    ~ATMQtDisplayController() override = default;

signals:
    //TODO: decide the proper logic for communication with JS
    void some_signal_to_emit();
};

#endif //MOOP_ATM_PROJECT_ATMQTDISPLAYCONTROLLER_H
