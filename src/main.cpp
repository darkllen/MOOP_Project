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

#include "models/DebitCard.h"
#include "controllers/AccountActions.h"
#include "models/transactions/Transaction.h"
#include "models/transactions/AccountManaging.h"
#include "models/ATMInfo.h"


int main(int argc, char *argv[]) {
    qputenv("QT_DEVICE_PIXEL_RATIO",QByteArray("1"));
//    PinVerificationService::verify(123123, 123);
    //DebitCard card = Bank::getCard(123123);
  //  card.setIsBlocked(false);
   // Account* account = Bank::getAccount("XXYY123123");
//    Account* account2 = Bank::getAccount("XXYY123123");
  //    unsigned  __int64 o = 1234;
  //    unsigned  __int64 n = 4321;
  //  Transaction* transaction = new AccountManaging(QDateTime::currentDateTime(), *account, 123123, AccountManaging::PIN, o, n);
  //  AccountActions::makeTransaction(*account, *transaction);

    QApplication qtApp(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QMainWindow mw;


    ATMController *controller = new ATMQtUiController(mw);
    //ATMInfo atmInfo(0, "", "");
    //TODO fix constructor. For now location isn`t copying at all
    ATM atm(ATM::getATM(1111));
    ATMIO *io = new ATMIO(atm, *controller);
    atm.powerStateChange(ATMPowerState::On);


    mw.show();
    const int resultCode = QApplication::exec();

    delete controller;
    delete io;

    return resultCode;
}