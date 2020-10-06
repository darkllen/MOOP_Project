//
// Created by Lemonderon on 02.10.2020.
//

#include <QApplication>
#include <QStyleFactory>
#include <QMainWindow>

#include "ui/ATMForm.h"

int main(int argc, char *argv[]) {
    QApplication qtApp(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    ATM atm;
    QMainWindow mw;
    ATMForm form(mw, atm.getIO());
    mw.show();

    return QApplication::exec();
}