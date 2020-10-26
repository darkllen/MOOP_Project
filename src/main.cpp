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
//#include "controllers/PinVerificationService.h"

#include "models/Bank.h"
#include "models/accounts/Account.h"

//#include "models/DebitCard.h"
#include "controllers/AccountActions.h"
#include "models/transactions/Transaction.h"
#include "models/transactions/OneTimeTransfer.h"



int main(int argc, char *argv[]) {
//    PinVerificationService::verify(123123, 123);
//    DebitCard card = Bank::getCard(123123);
//    Account* account = Bank::getAccount("XXYY321321");
//    Account* account2 = Bank::getAccount("XXYY123123");
//    Transaction* transaction = new OneTimeTransfer(QDateTime::currentDateTime(), *account2, *account, 23);
//    AccountActions::makeTransaction(*account, *transaction);
//
//

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

    return resultCode;
}