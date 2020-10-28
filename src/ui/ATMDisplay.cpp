//
// Created by Lemonderon on 25.10.2020.
//

#include "ATMDisplay.h"
#include <QtWebEngineWidgets/QWebEngineView>

ATMDisplay::ATMDisplay(QWebEngineView &webEngineView) : webEngineView_(&webEngineView), currentScreen_(WelcomeScreen), isOn_(false) {}

void ATMDisplay::turnOn() {
    isOn_ = true;
    navigateTo(NewDisplayStateEventToATMIO(Views::WelcomeScreen));
}

void ATMDisplay::turnOff() {
    navigateTo(NewDisplayStateEventToATMIO(Views::PoweredOffScreen));
    isOn_ = false;
}

void ATMDisplay::navigateTo(const NewDisplayStateEventToATMIO &e) {
    if (!isOn_){
        throw "Attempt to use the screen in OFF state";
        //TODO: requires implementation
    }
    switch (e.value) {
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
    }
    currentScreen_ = e.value;
}

Views ATMDisplay::getCurrentScreen() {
    return currentScreen_;
}
