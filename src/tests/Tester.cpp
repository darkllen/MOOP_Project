//
// Created by darklen on 11/9/2020.
//

#include "Tester.h"
#include "../models/ATMInfo.h"
#include "../models/atm_hardware/Dispenser.h"
#include "../models/atm_hardware/CardReader.h"
#include "../controllers/PinVerificationService.h"
#include "../models/TransactionManager.h"
#include "../controllers/AccountActions.h"
#include "../models/Bank.h"
#include "../models/DebitCard.h"
#include <cassert>

Tester::Tester(ATM &atm): _atm(&atm){
    assert(atm.getATMInfo().getSerialNumber() == 9999);
    assert(atm.getATMInfo().getLocation() == "test");
    assert(atm.getCardReaderStatus() == true);
    assert(atm.getDispenserStatus() == true);
    assert(atm.getDispenser().getAvailableCashAmount() == 1000);
}

void Tester::testEval() {
    assert(PinVerificationService::verify(9999, 9999));
}

void Tester::testOutput() {
    CASH_AMOUNT_T curr = _atm->getDispenser().getAvailableCashAmount();
    _atm->getDispenser().cashIn(100);
    assert(ATM::getATM(9999).getDispenser().getAvailableCashAmount()==curr+100);
    _atm->getDispenser().cashOut(100);
    assert(ATM::getATM(9999).getDispenser().getAvailableCashAmount()==curr);
    assert(_atm->getDispenser().getAvailableCashAmount() == curr);
}

void Tester::testDispenser() {
    _atm->setDispenserStatus(false);
    assert(ATM::getATM(9999).getDispenserStatus()== false);
    _atm->setDispenserStatus(true);
    assert(ATM::getATM(9999).getDispenserStatus()== true);
}

void Tester::testCardReader() {
    _atm->setCardReaderStatus(false);
    assert(ATM::getATM(9999).getCardReaderStatus()== false);
    _atm->setCardReaderStatus(true);
    assert(ATM::getATM(9999).getCardReaderStatus()== true);
}

void Tester::testTransactions() {
    Account* accFrom = Bank::getAccount("XXYY999999");
    assert(accFrom->getMoney()==1000);
    Account* accTo = Bank::getAccount("XXYY888888");
    assert(accTo->getMoney()==1000);

    OneTimeTransfer t = TransactionManager::createTransaction(QDateTime(), *accTo, *accFrom, 100);
    AccountActions::makeTransaction(*accFrom, t);

    assert(Bank::getAccount("XXYY999999")->getMoney() == 900);
    assert(Bank::getAccount("XXYY888888")->getMoney() == 1100);

    delete accTo;
    accTo = Bank::getAccount("XXYY888888");
    RegularTransfer t1 = TransactionManager::createTransaction(QDateTime(), *accTo, *accFrom,  100, 2);
    AccountActions::makeTransaction(*accFrom, t1);

    assert(Bank::getAccount("XXYY999999")->getMoney() == 800);
    assert(Bank::getAccount("XXYY888888")->getMoney() == 1200);

    delete accTo;
    accTo = Bank::getAccount("XXYY888888");

    CashTransaction t2 = TransactionManager::createTransaction(QDateTime(), *accTo, 200, true);
    AccountActions::makeTransaction(*accTo, t2);

    assert(Bank::getAccount("XXYY888888")->getMoney() == 1000);

    CashTransaction t3 = TransactionManager::createTransaction(QDateTime(), *accFrom, 200, false);
    AccountActions::makeTransaction(*accFrom, t3);

    assert(Bank::getAccount("XXYY999999")->getMoney() == 1000);

    AccountManaging t4 = TransactionManager::createTransaction(QDateTime(), *accFrom, 9999, AccountManaging::PIN, 9999, 8888);
    AccountActions::makeTransaction(*accFrom, t4);

    assert(Bank::getCard(9999).getPIN() == 8888);

    AccountManaging t5 = TransactionManager::createTransaction(QDateTime(), *accFrom, 9999, AccountManaging::PIN, 8888, 9999);
    AccountActions::makeTransaction(*accFrom, t5);
    assert(Bank::getCard(9999).getPIN() == 9999);

    delete accTo;
    delete accFrom;
}


