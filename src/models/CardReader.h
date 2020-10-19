//
// Created by Lemonderon on 19.10.2020.
//

#ifndef MOOP_ATM_PROJECT_CARDREADER_H
#define MOOP_ATM_PROJECT_CARDREADER_H

class CardReader {
private:
    PIN_T pin_;
    CARD_NUMBER_T card_n_;

public:
    CardReader() = default;
    ~CardReader() = default;

    void readPIN(PIN_T);
    void insertCard(CARD_NUMBER_T);
    void acceptCard();
    void returnCard();
};


#endif //MOOP_ATM_PROJECT_CARDREADER_H
