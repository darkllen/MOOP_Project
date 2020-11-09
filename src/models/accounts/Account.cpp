//
// Created by Lemonderon on 20.10.2020.
//

#include "Account.h"

Account::Account(int ownerId, std::string IBAN, const BANK_NUMBER_T& bankNumberT, const ACCOUNT_BALANCE_AMOUNT_T& money): ownerId_(ownerId), IBAN_(std::move(IBAN)), bank_(bankNumberT), money_(money) {}


BANK_NUMBER_T Account::getBank() const {
    return bank_;
}

std::string Account::getIBAN_() const {
    return IBAN_;
}

CASH_AMOUNT_T Account::getMoney() const {
    return money_;
}

void Account::setMoney(const CASH_AMOUNT_T& cash) {
    money_ = cash;
}

