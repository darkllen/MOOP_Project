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

    QString entered_NUM_;
    QString entered_card_;
    QString entered_amount_;
    QString entered_reg_;

    bool isOneTime_;

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

    void changePINTries(int n) override;
    void changeWarning(const QString &);
    bool getIsOn() { return display_->getIsOn(); }

    bool getIsOneTime() const { return isOneTime_; }
    void setIsOneTime(const bool &b) { isOneTime_ = b; }

    void enableDispencer(const bool &);

    // ATM calls:
    void printReceiptOutput() override;
    void dispenserOutput(CASH_AMOUNT_T) override;
    void navigateToNewView(Views) override;
    void showCardEvalResult(EventToATMController::CardEvalResultEvent::Result) override;
    void ATMPowerChangeFromATM(ATMPowerState) override;
    void DBConnectionFailed() override;

    void downloadProcessScreen();
    void updateEnNum();
};

#endif //MOOP_ATM_PROJECT_ATMQTUICONTROLLER_H
