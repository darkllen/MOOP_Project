//
// Created by Lemonderon on 09.11.2020.
//

#include <QtWebEngineWidgets/QWebEngineView>
#include "Views.h"

void WelcomeScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
}

void PINEnteringScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/CardEventScreen/CardPINChecking/index.html"));
}

void PINEnteringScreen::triesLeftUpdate(unsigned char triesLeft) {
    QString jsStr = "document.getElementById(\"tries\").innerHTML = 'Tries left: " + QString::number(triesLeft) + "';";
    engineView->page()->runJavaScript(jsStr);
}

void PINEnteringScreen::emptyText() {
    engineView->page()->runJavaScript("document.getElementById(\"text\").innerHTML = '';");
}

void MainMenuScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/index.html"));
}

void FinishAccountScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/finishAccount.html"));
}

void CardBalanceScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/cardBalance.html"));
}

//void ChangeLimitScreen::loadIntoDisplay() {
//
//}

void ChangePinScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/changePin.html"));
}

void DoTransactionScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/doTransaction.html"));
}

void PutCashScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/putCash.html"));
}

void ShowAccountsScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/showAccounts.html"));
}

void TakeCashScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/takeCash.html"));
}

void PoweredOffScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/PoweredOffScreen/index.html"));
}

void PutCashMScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/PoweredOffScreen/putCashM.html"));
}

void TakeCashMScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/PoweredOffScreen/takeCashM.html"));
}

void ChangeStatusScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/PoweredOffScreen/changeStatus.html"));
}

void InfoScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/PoweredOffScreen/info.html"));
}

void CardIsInvalidScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/CardEventScreen/InvalidCardInserted/index.html"));
}

void CardIsBlockedScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/CardEventScreen/CardBlocked/index.html"));
}

void ReadAmountScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/TransactionReader/ReadAmount.html"));
}

void ReadCardScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/TransactionReader/ReadCard.html"));
}

void ReadRegScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/TransactionReader/ReadReg.html"));
}

void ProcessScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/TransactionReader/Process.html"));
}

void ReceiptScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/receipt.html"));
}

void TransactionHistoryScreen::loadIntoDisplay() {
    engineView->load(QUrl("qrc:/views/MainMenuScreen/transactionHistory.html"));
}
