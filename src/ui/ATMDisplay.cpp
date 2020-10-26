//
// Created by Lemonderon on 25.10.2020.
//

#include "ATMDisplay.h"
#include <QtWebEngineWidgets/QWebEngineView>

ATMDisplay::ATMDisplay(QWebEngineView &webEngineView): webEngineView_(&webEngineView) {}

void ATMDisplay::turnOn() {
    //TODO: Requires implementation
    webEngineView_->setHtml("<h1>IS POWERED ON</h1>");
}

void ATMDisplay::turnOff() {
    //TODO: Requires implementation
    webEngineView_->setHtml("<h1>IS POWERED OFF</h1>");
}
