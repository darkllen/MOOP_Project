//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
#define MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H

#include <QtCore/QObject>

#include "../ATMController.h"
#include "../../ui/ATMDisplay.h"

class ATMForm;
class QMainWindow;
class ATMDisplay;

class ATMQtUiController : public QObject, public ATMController {
Q_OBJECT
private:
    ATMForm *atmForm_;
    ATMDisplay *display_;
    QString entered_NUM;

    QString entered_card;
    QString entered_amount;
    QString entered_reg=0;

    bool isOneTime;


public:
    explicit ATMQtUiController(QMainWindow &mw);
    ~ATMQtUiController() override;

    // UI calls:
    void dialPadInput(UIButtonsInput::DialPad) override;
    void dialPadControlInput(UIButtonsInput::ControlPad) override;
    void sideDisplayBtnInput(UIButtonsInput::DisplaySideButton) override;
    void dispenserInput(CASH_AMOUNT_T) override;
    void cardReaderInput(CARD_NUMBER_T) override;
    void ATMPowerChangeFromUI(ATMPowerState) override;

    void changePINTries(int n);
    void changeWarning(QString);
    bool getIsOn(){return display_->getIsOn();}

    bool getIsOneTime(){return isOneTime;}
    void setIsOneTime(bool b){isOneTime = b;}

    void enableDispencer(bool);

    // ATM calls:
    void printReceiptOutput() override;
    void dispenserOutput(CASH_AMOUNT_T) override;
    void navigateToNewView(Views) override;
    void showCardEvalResult(EventToATMController::CardEvalResultEvent::Result) override;
    void ATMPowerChangeFromATM(ATMPowerState) override;

    void downloadProcessScreen();

    void updateEnNum();
};

#endif //MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
