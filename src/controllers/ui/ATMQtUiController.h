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
    unsigned int entered_NUM;

public:
    explicit ATMQtUiController(QMainWindow &mw);
    ~ATMQtUiController() override;

    // UI calls:
    void dialPadInput(UIButtonsInput::DialPad) override;
    void dialPadControlInput(UIButtonsInput::ControlPad) override;
    void sideDisplayBtnInput(UIButtonsInput::DisplaySideButton) override;
    void dispenserInput() override;
    void cardReaderInput(CARD_NUMBER_T) override;
    void ATMPowerChangeFromUI(ATMPowerState) override;

    // ATM calls:
    void printReceiptOutput() override;
    void dispenserOutput() override;
    void navigateToNewView(Views) override;
    void showCardEvalResult(EventToATMController::CardEvalResultEvent::Result) override;
    void ATMPowerChangeFromATM(ATMPowerState) override;
};

#endif //MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
