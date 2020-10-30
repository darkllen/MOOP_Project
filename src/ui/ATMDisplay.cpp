//
// Created by Lemonderon on 25.10.2020.
//

#include <QtWebEngineWidgets/QWebEngineView>

#include "ATMDisplay.h"

ATMDisplay::ATMDisplay(QWebEngineView &webEngineView) :
        webEngineView_(&webEngineView), currentScreen_(WelcomeScreen), isOn_(false) {}

void ATMDisplay::turnOn() {
    isOn_ = true;
    navigateTo(Views::WelcomeScreen);
}

void ATMDisplay::turnOff() {
    navigateTo(Views::PoweredOffScreen);
    isOn_ = false;
}

void ATMDisplay::navigateTo(Views view) {
    if (!isOn_) {
        throw "Attempt to use the screen in OFF state";
        //TODO: requires implementation
    }
    switch (view) {
        case WelcomeScreen:
            webEngineView_->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
            break;
        case PINEnteringScreen:
            break;
        case CardBlockedScreen:
            break;
        case MainMenuScreen:
            webEngineView_->load(QUrl("qrc:/views/MainMenuScreen/index.html"));
            break;
        case PoweredOffScreen:
            webEngineView_->load(QUrl("qrc:/views/PoweredOffScreen/index.html"));
            break;
        case CardIsBlockedScreen:
            webEngineView_->load(QUrl("qrc:/views/CardEventScreen/InvalidCardInsertedEvent/index.html"));
            break;
        case CardIsInvalidScreen:
            webEngineView_->load(QUrl("qrc:/views/CardEventScreen/CardBlockedEvent/index.html"));
            break;
    }
    currentScreen_ = view;
}

Views ATMDisplay::getCurrentScreen() const {
    return currentScreen_;
}

void ATMDisplay::reset() {
    webEngineView_->load(QUrl("qrc:/views/WelcomeScreen/index.html"));
}
