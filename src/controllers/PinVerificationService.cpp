//
// Created by anna2 on 20.10.2020.
//

#include "PinVerificationService.h"
#include "../models/Bank.h"
#include "../models/DebitCard.h"
#include "../constants/ATMTypes.h"

bool PinVerificationService::verify(const CARD_NUMBER_T cardNum, const PIN_T pin) {
    return pin == Bank::getCard(cardNum).getPIN();
}

