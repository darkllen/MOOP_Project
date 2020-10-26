//
// Created by Lemonderon on 25.10.2020.
//

#include "ATMDisplay.h"
#include <QtWebEngineWidgets/QWebEngineView>

ATMDisplay::ATMDisplay(QWebEngineView &webEngineView): webEngineView_(&webEngineView) {}

void ATMDisplay::turnOn() {
    //TODO: Requires implementation
    webEngineView_->load(QUrl("https://www.google.com/search?client=firefox-b-d&q=is+powered+on"));
}

void ATMDisplay::turnOff() {
    //TODO: Requires implementation
    webEngineView_->load(QUrl("https://www.google.com/search?client=firefox-b-d&q=is+powered+off"));
}
