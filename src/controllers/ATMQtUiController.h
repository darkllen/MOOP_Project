//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
#define MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H

#include <QtCore/QObject>

#include "ATMController.h"

class ATMForm;
class QMainWindow;

class ATMQtUiController : public QObject, public ATMController {
Q_OBJECT
private:
    QMainWindow& mw_;
    ATMForm * atmForm_;

public:
    explicit ATMQtUiController(QMainWindow& mw);
    ~ATMQtUiController() override = default;

    void dialPadInput(DialPadBtn btn) override;
    void dialPadControlInput(ControlBtn btn) override;
    void sideDisplayBtnInput(DisplaySideBtn btn) override;
    void dispenserInput() override;
    void cardReaderInput() override;

private slots:
    void printReceiptOutput();
    void dispenserOutput();
    void cardReaderOutput();
    void displayOutput(DisplayState);
    void displayPower(DisplayPowerState powerState);

signals:
    //TODO: decide the proper logic for communication with JS
    void some_signal_to_emit();
};


#endif //MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
