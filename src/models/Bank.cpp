//
// Created by Lemonderon on 20.10.2020.
//

#include "Bank.h"

#include "accounts/Account.h"

Bank::Bank(BANK_NUMBER_T id, std::string address, std::string name) :
        id_(id), address_(std::move(address)),
        name_(std::move(name)) {}

Account Bank::getCardAccount(const DebitCard &) {
    //TODO: Requires implementation
    return Account("", "");
}
