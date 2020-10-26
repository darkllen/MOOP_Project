//
// Created by Lemonderon on 20.10.2020.
//

#include "Account.h"

Account::Account(std::string ownerName, std::string IBAN, BANK_NUMBER_T bankNumberT): ownerName_(std::move(ownerName)), IBAN_(std::move(IBAN)), bank_(bankNumberT) {}


BANK_NUMBER_T Account::getBank() const {
    return bank_;
}

std::string Account::getIBAN_() const {
    return IBAN_;
}

