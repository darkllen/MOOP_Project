//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
#define MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H

#include <QtCore/QObject>

#include "../ATMController.h"

class ATMForm;
class QMainWindow;
class ATMDisplay;

class ATMQtUiController : public QObject, public ATMController {
Q_OBJECT
private:
    ATMForm *atmForm_;
    ATMDisplay *display_;

public:
    explicit ATMQtUiController(QMainWindow &mw);
    ~ATMQtUiController() override;

    // UI calls:
    void dialPadInput(UIInput::DialPadBtnInput) override;
    void dialPadControlInput(UIInput::ControlBtnInput) override;
    void sideDisplayBtnInput(UIInput::DisplaySideBtnInput) override;
    void dispenserInput() override;
    void cardReaderInput() override;
    void ATMPowerChange(UIInput::ATMPowerState) override;

    // ATM calls:
    void printReceiptOutput() override;
    void dispenserOutput() override;
    void cardReaderOutput() override;
    void displayOutput(const NewDisplayStateEvent&) override;
    void ATMPowerChange(const ATMPowerStateEvent&) override;
};

#endif //MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
