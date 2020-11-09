//
// Created by Lemonderon on 02.10.2020.
//
#include "tests/Tester.h"
#include <QApplication>
#include <QStyleFactory>
#include <QMainWindow>
#include "controllers/ui/ATMQtUiController.h"
#include "ui/ATMForm.h"
#include "models/DebitCard.h"
#include "models/ATMInfo.h"

int main(int argc, char *argv[]) {
    qputenv("QT_DEVICE_PIXEL_RATIO",QByteArray("1"));
#ifdef _DEBUG
    {
        ATM atmTest(ATM::getATM(9999));
        Tester tester(atmTest);
        tester.testEval();
        tester.testOutput();
        tester.testDispenser();
        tester.testCardReader();
        tester.testTransactions();
  };
#endif

    QApplication qtApp(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QMainWindow mw;

    ATMController *controller = new ATMQtUiController(mw);
    ATM atm(ATM::getATM(1111));
    auto *io = new ATMIO(atm, *controller);
    atm.powerStateChange(ATMPowerState::On);

    mw.show();
    const int resultCode = QApplication::exec();

    delete controller;
    delete io;

    return resultCode;
}