//
// Created by Lemonderon on 25.10.2020.
//

#include <QtWebEngineWidgets/QWebEngineView>
#include <QTimer>
#include <QtCore/qeventloop.h>
#include "ATMDisplay.h"

ATMDisplay::ATMDisplay(QWebEngineView &webEngineView) :
        webEngineView_(&webEngineView), currentScreen_(WelcomeScreen), isOn_(false), receipt_("") {}

void ATMDisplay::turnOn() {
    isOn_ = true;
    navigateTo(Views::WelcomeScreen);
}

void ATMDisplay::turnOff() {
    navigateTo(Views::PoweredOffScreen);
    isOn_ = false;
}

ATMDisplay::~ATMDisplay() {
    delete webEngineView_;
    webEngineView_ = nullptr;
};

void ATMDisplay::navigateTo(Views view) {
    if (!isOn_) {
        switch (view) {
            case PutCashMScreen:
                webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/putCashM.html"));
                break;
            case TakeCashMScreen:
                webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/takeCashM.html"));
                break;
            case ChangeStatusScreen:
                webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/changeStatus.html"));
                break;
            case InfoScreen:
                webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/info.html"));
                break;
            case PoweredOffScreen:
                webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/index.html"));
                break;
            default:
                throw std::exception("Attempt to use the screen in OFF state");
        }
    } else
        switch (view) {
            case WelcomeScreen:
                webEngineView_->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
                break;
            case PINEnteringScreen:
                webEngineView_->load(QUrl("qrc:/views/CardEventScreen/CardPINChecking/index.html"));
                break;
            case MainMenuScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/index.html"));
                break;
            case FinishAccountScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/finishAccount.html"));
                break;
            case CardBalanceScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/cardBalance.html"));
                break;
            case TransactionHistoryScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/transactionHistory.html"));
                break;
            case ChangePinScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/changePin.html"));
                break;
            case DoTransactionScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/doTransaction.html"));
                break;
            case PutCashScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/putCash.html"));
                break;
            case ShowAccountsScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/showAccounts.html"));
                break;
            case TakeCashScreen:
                webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/takeCash.html"));
                break;
            case PoweredOffScreen:
                webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/index.html"));
                break;
            case CardIsBlockedScreen:
                webEngineView_->load(QUrl("qrc:/views/CardEventScreen/CardBlocked/index.html"));
                break;
            case CardIsInvalidScreen:
                webEngineView_->load(QUrl("qrc:/views/CardEventScreen/InvalidCardInserted/index.html"));
                break;
            case ReadCardScreen:
                webEngineView_->load(QUrl("qrc:/views/TransactionReader/ReadCard.html"));
                break;
            case ReadAmountScreen:
                webEngineView_->load(QUrl("qrc:/views/TransactionReader/ReadAmount.html"));
                break;
            case ReadRegScreen:
                webEngineView_->load(QUrl("qrc:/views/TransactionReader/ReadReg.html"));
                break;
            case ProcessScreen:
                webEngineView_->load(QUrl("qrc:/views/TransactionReader/Process.html"));
                break;
            case ReceiptScreen:
                webEngineView_->load(QUrl("qrc:/views/receipt_.html"));
                break;
            case ConnectionErrorScreen:
                webEngineView_->load(QUrl("qrc:/views/ConnectionErrorScreen/index.html"));
                break;
            default:
                throw std::exception("Attempt to use the screen in ON state");
        }
    ATMDisplay::waitForLoad(*webEngineView_);
    currentScreen_ = view;
}

void ATMDisplay::runJs(const QString &js) {
    webEngineView_->page()->runJavaScript(js);
};

Views ATMDisplay::getCurrentScreen() const {
    return currentScreen_;
}


bool ATMDisplay::waitForLoad(QWebEngineView &view) {
    QEventLoop loopLoad;
    QTimer timer;
    QObject::connect(&view, SIGNAL(loadFinished(bool)), &loopLoad, SLOT(quit()));
    QObject::connect(&view, SIGNAL(loadFinished(bool)), &timer, SLOT(stop()));
    QObject::connect(&timer, SIGNAL(timeout()), &loopLoad, SLOT(quit()));
    timer.start(2000);
    loopLoad.exec();
    if (timer.isActive()) {
        timer.stop();
        view.stop();
        return false;
    }
    return true;
}