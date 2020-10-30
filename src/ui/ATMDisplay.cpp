//
// Created by Lemonderon on 25.10.2020.
//

#include <QtWebEngineWidgets/QWebEngineView>
#include <QtConcurrent/QtConcurrentRun>

#include "ATMDisplay.h"

ATMDisplay::ATMDisplay(QWebEngineView &webEngineView) : webEngineView_(&webEngineView), currentScreen_(WelcomeScreen),
                                                        isOn_(false) {}

void ATMDisplay::turnOn() {
    isOn_ = true;
    navigateTo(NewDisplayStateEventToATMIO(Views::WelcomeScreen));
}

void ATMDisplay::turnOff() {
    navigateTo(NewDisplayStateEventToATMIO(Views::PoweredOffScreen));
    isOn_ = false;
}

void ATMDisplay::navigateTo(const NewDisplayStateEventToATMIO &event) {
    if (!isOn_) {
        throw "Attempt to use the screen in OFF state";
        //TODO: requires implementation
    }
    switch (event.value) {
        case WelcomeScreen:
            webEngineView_->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
            break;
        case PINEnteringScreen:
            break;
        case CardBlockedScreen:
            break;
        case MainMenuScreen:
            break;
        case PoweredOffScreen:
            webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/index.html"));
            break;
        case CardEventScreen:
            auto e = dynamic_cast<const CardEventDisplayState &>(event);
            QtConcurrent::run(showCardEventOnDisplay, *this, e.type);
            break;
    }
    currentScreen_ = event.value;
}

Views ATMDisplay::getCurrentScreen() const{
    return currentScreen_;
}

void ATMDisplay::showCardEventAsync(CardEventToATMIO::Type type) {
    switch (type) {
        case CardEventToATMIO::CardAccepted:
            webEngineView_->load(QUrl("qrc:/views/CardEventScreen/CardAccepted/index.html"));
            QThread::sleep(2);
            webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/index.html"));
            break;
        case CardEventToATMIO::InvalidCardInsertedEvent:
            webEngineView_->load(QUrl("qrc:/views/CardEventScreen/InvalidCardInsertedEvent/index.html"));
            QThread::sleep(2);
            webEngineView_->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
            break;
        case CardEventToATMIO::CardBlockedEvent:
            webEngineView_->load(QUrl("qrc:/views/CardEventScreen/CardBlockedEvent/index.html"));
            QThread::sleep(5);
            webEngineView_->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
            break;
        case CardEventToATMIO::CardReturnEvent:
            webEngineView_->load(QUrl("qrc:/views/CardEventScreen/CardReturnEvent/index.html"));
            QThread::sleep(2);
            webEngineView_->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
            break;
    }
}

void showCardEventOnDisplay(ATMDisplay &d, CardEventToATMIO::Type type) {
    d.showCardEventAsync(type);
}
