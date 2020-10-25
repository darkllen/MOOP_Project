//
// Created by Lemonderon on 20.10.2020.
//

#include "Bank.h"

#include "accounts/Account.h"
#include <mysqlx/xdevapi.h>
#include <iostream>
#include <string>

using namespace mysqlx;

Bank::Bank(BANK_NUMBER_T id, std::string address, std::string name) :
        id_(id), address_(std::move(address)),
        name_(std::move(name)) {}

PIN_T Bank::getCardPIN(const CARD_NUMBER_T & cardNumberT) {
    //TODO: Requires implementation
    try {
        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
        Session mySession(url);
    } catch (std::exception e) {
        std::cout << e.what()<<std::endl;
    }


    //mysqlx::Schema db= sess.getSchema("moop");

    return 0;
}
