//
// Created by kuchm on 04.10.2020.
//

#include "ATMQtUiController.h"
#include "../ui/ATMForm.h"

ATMQtUiController::ATMQtUiController(QMainWindow &mw): QObject(nullptr), ATMController(), mw_(mw), atmForm_(new ATMForm(mw, *this)) {

}
