//
// Created by Lemonderon on 25.10.2020.
//

#include <QtWebEngineWidgets/QWebEngineView>
#include <QTimer>
#include <QtCore/qeventloop.h>
#include "ATMDisplay.h"
#include "../models/Bank.h"
#include "../models/accounts/Account.h"


ATMDisplay::ATMDisplay(QWebEngineView &webEngineView) :
        webEngineView_(&webEngineView), currentScreen_(nullptr), isPoweredOn_(false), isLocked_(false) {
    navigateTo(ScreenEnum::WelcomeScreen);
}

void ATMDisplay::turnOn() {
    isPoweredOn_ = true;
    navigateTo(ScreenEnum::WelcomeScreen);
}

void ATMDisplay::turnOff() {
    navigateTo(ScreenEnum::PoweredOffScreen);
    isPoweredOn_ = false;
}

void ATMDisplay::navigateTo(ScreenEnum sc) {
    if (!isPoweredOn_) {
        switch (sc) {
            case PutCashMScreen:
            case TakeCashMScreen:
            case ChangeStatusScreen:
            case InfoScreen:
            case PoweredOffScreen:
                loadIntoDisplay(sc, *webEngineView_);
                break;
            default:
                throw std::exception("Attempt to use invalid screen in OFF state");
        }
    } else {
        switch (sc) {
            case WelcomeScreen:
            case PINEnteringScreen:
            case MainMenuScreen:
            case FinishAccountScreen:
            case CardBalanceScreen:
            case TransactionHistoryScreen:
            case ChangePinScreen:
            case DoTransactionScreen:
            case PutCashScreen:
            case ShowAccountsScreen:
            case TakeCashScreen:
            case CardIsBlockedScreen:
            case CardIsInvalidScreen:
            case ReadCardScreen:
            case ReadAmountScreen:
            case ReadRegScreen:
            case ProcessScreen:
            case ReceiptScreen:
                loadIntoDisplay(sc, *webEngineView_);
                break;
            default:
                throw std::exception("Attempt to use invalid screen in ON state");
        }
    }
    currentScreen_ = sc;
    ATMDisplay::waitForLoad(*webEngineView_);
}

void ATMDisplay::runJs(const QString &js) {
    webEngineView_->page()->runJavaScript(js);
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