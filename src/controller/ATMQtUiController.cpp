//
// Created by kuchm on 04.10.2020.
//

#include "ATMQtUiController.h"
#include "../ui/ATMForm.h"

ATMQtUiController::ATMQtUiController(QMainWindow &mw): QObject(nullptr), ATMController(), mw_(mw), atmForm_(new ATMForm(mw, *this)) {

}

void ATMQtUiController::dialPadInput(ATMQtUiController::DialPadBtn btn) {
    //TODO: Needs implementation
}
void ATMQtUiController::dialPadControlInput(ATMQtUiController::ControlBtn btn){
    //TODO: Needs implementation
}
void ATMQtUiController::sideDisplayBtnInput(ATMQtUiController::DisplaySideBtn btn) {
    //TODO: Needs implementation
}
void ATMQtUiController::dispenserInput() {
    //TODO: Needs implementation
}
void ATMQtUiController::cardReaderInput() {
    //TODO: Needs implementation
}
void ATMQtUiController::printReceiptOutput() {
    //TODO: Needs implementation
}
void ATMQtUiController::dispenserOutput() {
    //TODO: Needs implementation
}
void ATMQtUiController::cardReaderOutput() {
    //TODO: Needs implementation
}

void ATMQtUiController::displayOutput(ATMQtUiController::DisplayState) {
    //TODO: Needs implementation
}

void ATMQtUiController::displayPower(ATMQtUiController::DisplayPowerState powerState) {
    //TODO: Needs implementation
}

