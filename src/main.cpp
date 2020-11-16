//
// Created by Lemonderon on 02.10.2020.
//
#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QStyleFactory>
#include <QtWidgets/QVBoxLayout>

#include <mysqlx/devapi/common.h>

#include "controllers/ui/ATMQtUiController.h"
#include "models/DebitCard.h"
#include "models/ATMInfo.h"
#include "tests/Tester.h"
#include "ui/ATMForm.h"


void showErrorScreen(QMainWindow &mw, int &resultCode);
void showATM(QMainWindow &mw, int &resultCode);

int main(int argc, char *argv[]) {
    qputenv("QT_DEVICE_PIXEL_RATIO", QByteArray("1"));
#ifndef NDEBUG
    ATM atmTest(ATM::getATM(9999));
    Tester tester(atmTest);
    tester.testEval();
    tester.testOutput();
    tester.testDispenser();
    tester.testCardReader();
    tester.testTransactions();
#endif

    QApplication qtApp(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QMainWindow mw;
    int resultCode;

    try {
        showATM(mw, resultCode);
    } catch (const mysqlx::Error &err) {
        showErrorScreen(mw, resultCode);
    }

    return resultCode;
}


void showErrorScreen(QMainWindow &mw, int &resultCode) {
    QLabel *lbl;
    lbl = new QLabel(&mw);
    lbl->setText("DB CONNECTION FAILED\n"
                 "PLEASE CHECK THE INTERNET CONNECTION\n"
                 "AND RESTART THE PROGRAM");
    lbl->setAlignment(Qt::AlignCenter);
    mw.setMenuBar(nullptr);
    mw.setCentralWidget(lbl);
    mw.show();
    resultCode = QApplication::exec();
}

void showATM(QMainWindow &mw, int &resultCode) {
    ATM atm(ATM::getATM(1111));

    ATMController *controller = new ATMQtUiController(mw);
    auto *io = new ATMIO(atm, *controller);
    atm.powerStateChange(ATMPowerState::On);

    mw.show();
    resultCode = QApplication::exec();

    delete controller;
    delete io;
}