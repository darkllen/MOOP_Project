#ifndef MOOP_ATM_PROJECT_CARDPINCHECK_H
#define MOOP_ATM_PROJECT_CARDPINCHECK_H

#include "../constants/ATM_Types.h"

class DebitCard;

class CardPinCheck {
private:
    size_t enteringTriesPINNum_ = 0;
    size_t limit_ = 3;
public :
    CardPinCheck();
    ~CardPinCheck();
    bool checkPin(const CARD_NUMBER_T , const PIN_T);
    void blockCard(const CARD_NUMBER_T);

    size_t getEnteringTriesPINNum(){return enteringTriesPINNum_;}
};

#endif //MOOP_ATM_PROJECT_CARDPINCHECK_H