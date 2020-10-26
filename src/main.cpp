//
// Created by Lemonderon on 02.10.2020.
//

#include <QApplication>
#include <QStyleFactory>
#include <QMainWindow>

#include "controllers/ui/ATMQtUiController.h"
#include "models/ATM.h"
#include "ui/ATMForm.h"

#include <iostream>

#include <mysqlx/xdevapi.h>
//#include "controllers/PinVerificationService.h"
//#include "models/Bank.h"
#include "models/accounts/Account.h"
//#include "models/DebitCard.h"
//#include "controllers/AccountActions.h"


int main(int argc, char *argv[]) {
    //PinVerificationService::verify(123123, 123);
    //DebitCard card = Bank::getCard(123123);
    //Account* account = Bank::getAccount("XXYY321321");
    //AccountActions::viewHistory(Account("asd", "XXYY123123", 1));


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

    try {
        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
        mysqlx::Session mySession(url);
    } catch (const std::exception& e) {
        std::cout << e.what()<<std::endl;
    }

    return resultCode;
}