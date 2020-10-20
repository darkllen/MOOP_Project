//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_CARDREADER_H
#define MOOP_ATM_PROJECT_CARDREADER_H

#include "../constants/ATM_Types.h"

class CardPinCheck;


class CardReader {
private:
    PIN_T pin_;
    CARD_NUMBER_T card_n_;

    CardPinCheck & cardPinCheck_;

public:
    CardReader() = default;
    ~CardReader() = default;

    void readPIN(PIN_T);
    void insertCard(CARD_NUMBER_T);
    void acceptCard();
    void returnCard();

    PIN_T getPin(){return pin_;}
    //void setCardN(CARD_NUMBER_T num){card_n_ = num;}

};


#endif //MOOP_ATM_PROJECT_CARDREADER_H
