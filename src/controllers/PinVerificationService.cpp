//
// Created by anna2 on 20.10.2020.
//

#include "PinVerificationService.h"
#include "../models/Bank.h"
#include "../models/DebitCard.h"
#include "../constants/ATMTypes.h"
#include "../exceptions/ATMException.h"

bool PinVerificationService::verify(const CARD_NUMBER_T cardNum, const PIN_T pin) {
    try{
        return pin == Bank::getCard(cardNum).getPIN();
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}

