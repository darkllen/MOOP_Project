//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_CASH_H
#define MOOP_ATM_PROJECT_CASH_H
class Transaction;
class Cash: public Transaction{
private:
    int amount_;
    bool isWithdrawal_;
public:
    Cash(const Date&, int, bool);
    ~Cash();
};

#endif //MOOP_ATM_PROJECT_CASH_H
