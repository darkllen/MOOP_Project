//
// Created by Lemonderon on 02.10.2020.
//

#include <QApplication>
#include <QStyleFactory>
#include <QMainWindow>

#include "controllers/ui/ATMQtUiController.h"
#include "models/ATM.h"
#include "ui/ATMForm.h"

#include <mysqlx/xdevapi.h>

int main(int argc, char *argv[]) {
    QApplication qtApp(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QMainWindow mw;


    ATMController *controller = new ATMQtUiController(mw);
    ATMInfo atmInfo(0, "", "");
    ATM atm(atmInfo, 0);
    ATMIO *io = new ATMIO(atm, *controller);


    mw.show();
    const int resultCode = QApplication::exec();

    delete controller;
    delete io;

    {
        mysqlx::nullvalue;
    }

    return resultCode;
}