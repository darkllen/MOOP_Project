//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
#define MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H

#include <QtCore/QObject>

#include "../ATMController.h"

class ATMQtDisplayController;
class ATMForm;
class QMainWindow;

class ATMQtUiController : public QObject, public ATMController {
Q_OBJECT
private:
    ATMForm *atmForm_;

    ATMQtDisplayController *displayController_;

public:
    explicit ATMQtUiController(QMainWindow &mw);
    ~ATMQtUiController() override;

    void dialPadInput(DialPadBtn btn) override;
    void dialPadControlInput(ControlBtn btn) override;
    void sideDisplayBtnInput(DisplaySideBtn btn) override;
    void dispenserInput() override;
    void cardReaderInput() override;

    void printReceiptOutput();
    void dispenserOutput();
    void cardReaderOutput();
    void displayOutput(DisplayState);
    void displayPower(DisplayPowerState powerState);
};

#endif //MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
