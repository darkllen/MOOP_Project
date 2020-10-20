//
// Created by anna2 on 20.10.2020.
//
#include "CardReader.h"
#include "../constants/ATM_Types.h"
#include "..controllers/CardPinCheck.h"


void CardReader::readPIN(PIN_T pin) {
    pin_ = pin;
    bool correct = cardPinCheck_ -> checkPin(card_n_, pin_);
    if(correct)
        acceptCard();
    else
    {
        //card is blocked or person needs to type pin again
    }

}

void CardReader::insertCard(CARD_NUMBER_T num){
    card_n_ = num;
}

void CardReader::acceptCard(){
    //todo accept card
}

void CardReader::returnCard(){
    //todo return card
}

