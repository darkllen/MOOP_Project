#ifndef MOOP_ATM_PROJECT_DEBITCARD_H
#define MOOP_ATM_PROJECT_DEBITCARD_H

#include <ctime>
#include <QtCore/qdatetime.h>

class DebitCard {
private:
    unsigned int cardNum_;
    QDateTime expireDate_;
    unsigned short cvCode_;
    unsigned __int64 PIN_;

public:
    DebitCard(const unsigned int &, const QDateTime &, const unsigned short &, const unsigned __int64 &);
    ~DebitCard();
};

#endif //MOOP_ATM_PROJECT_DEBITCARD_H
