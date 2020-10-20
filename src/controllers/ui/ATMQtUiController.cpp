//
// Created by Lemonderon on 20.10.2020.
//

#include "ATMQtUiController.h"
#include "ATMQtDisplayController.h"
#include "../../ui/ATMForm.h"

ATMQtUiController::ATMQtUiController(QMainWindow &mw) :
        atmForm_(new ATMForm(mw, *this)), displayController_(new ATMQtDisplayController(*this)) {}

ATMQtUiController::~ATMQtUiController() {
    delete atmForm_;
    delete displayController_;
    atmForm_ = nullptr;
    displayController_ = nullptr;
}

void ATMQtUiController::dialPadInput(DialPadBtn btn) {
    //TODO: Requires implementation
}

void ATMQtUiController::dialPadControlInput(ControlBtn btn) {
    //TODO: Requires implementation
}

void ATMQtUiController::sideDisplayBtnInput(DisplaySideBtn btn) {
    //TODO: Requires implementation
}

void ATMQtUiController::dispenserInput() {
    //TODO: Requires implementation
}

void ATMQtUiController::cardReaderInput() {
    //TODO: Requires implementation
}

void ATMQtUiController::printReceiptOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::dispenserOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::cardReaderOutput() {
    //TODO: Requires implementation
}

void ATMQtUiController::displayOutput(DisplayState) {
    //TODO: Requires implementation
}

void ATMQtUiController::displayPower(DisplayPowerState powerState) {
    //TODO: Requires implementation
}