//
// Created by anna2 on 20.10.2020.
//

#include "CardPinCheck.h"
#include "../constants/ATM_Types.h"

    CardPinCheck::CardPinCheck(){}
    CardPinCheck::~CardPinCheck(){}

    bool CardPinCheck::checkPin(const CARD_NUMBER_T cardNum, const PIN_T pin){
        enteringTriesPINNum_++;
        if(enteringTriesPINNum_ >limit_) {
            blockCard(cardNum);
            return false;
        }
        else {
            //todo check pin from db
            if(pin!=0)
                return true;
            else return false;
        }
    }

    void CardPinCheck::blockCard(const CARD_NUMBER_T) {
        //todo set card blocked
    }
};

#endif //MOOP_ATM_PROJECT_CARDPINCHECK_H

