//
// Created by Lemonderon on 20.10.2020.
//

#include "Bank.h"

#include "accounts/Account.h"
#include <mysqlx/xdevapi.h>

Bank::Bank(BANK_NUMBER_T id, std::string address, std::string name) :
        id_(id), address_(std::move(address)),
        name_(std::move(name)) {}

PIN_T Bank::getCardPIN(const CARD_NUMBER_T & cardNumberT) {
    //TODO: Requires implementation
    mysqlx::Session sess("localhost", 3306, "root", "0987654321i");

    //mysqlx::Schema db= sess.getSchema("moop");

    return 0;
}
