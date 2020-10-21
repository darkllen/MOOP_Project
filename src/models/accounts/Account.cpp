//
// Created by Lemonderon on 20.10.2020.
//

#include "Account.h"

Account::Account(std::string ownerName, std::string IBAN): ownerName_(std::move(ownerName)), IBAN_(std::move(IBAN)) {}

PIN_T Account::getCardPIN(const CARD_NUMBER_T) const {
    //TODO: Requires implementation
    return 0;
}

BANK_NUMBER_T Account::getBank() const {
    //TODO: Requires implementation
    return 0;
}

