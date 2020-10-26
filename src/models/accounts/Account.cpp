//
// Created by Lemonderon on 20.10.2020.
//

#include "Account.h"

Account::Account(std::string ownerName, std::string IBAN, const BANK_NUMBER_T& bankNumberT, const CASH_AMOUNT_T& money): ownerName_(std::move(ownerName)), IBAN_(std::move(IBAN)), bank_(bankNumberT), money_(money) {}


BANK_NUMBER_T Account::getBank() const {
    return bank_;
}

std::string Account::getIBAN_() const {
    return IBAN_;
}

CASH_AMOUNT_T Account::getMoney() const {
    return money_;
}

