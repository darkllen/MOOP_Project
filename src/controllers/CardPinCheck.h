#ifndef MOOP_ATM_PROJECT_CARDPINCHECK_H
#define MOOP_ATM_PROJECT_CARDPINCHECK_H

#include "../constants/ATM_Types.h"

class DebitCard;

class CardPinCheck {
private:
    size_t enteringTriesPINNum_;
public :
    CardPinCheck();
    ~CardPinCheck();
    bool checkPin(const CARD_NUMBER_T , const PIN_T);
};

#endif //MOOP_ATM_PROJECT_CARDPINCHECK_H