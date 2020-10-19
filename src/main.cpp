//
// Created by Lemonderon on 02.10.2020.
//

#include <QApplication>
#include <QStyleFactory>
#include <QMainWindow>

#include "controllers/ATMQtUiController.h"
#include "models/ATM.h"
#include "ui/ATMForm.h"


int main(int argc, char *argv[]) {
    QApplication qtApp(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QMainWindow mw;


//    TODO: Which version is better?
//    ATMQtUiController qtUiController(mw);
//    ATMController *controller = &qtUiController;
    ATMController *controller = new ATMQtUiController(mw);
    ATMInfo atmInfo(0, "", "");
    ATM atm(atmInfo, 0);
    ATMIO *io = new ATMIO(atm, *controller);


    mw.show();
    const int resultCode = QApplication::exec();

    delete controller;
    delete io;

    return resultCode;
}