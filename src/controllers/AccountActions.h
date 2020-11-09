//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ACCOUNTACTIONS_H
#define MOOP_ATM_PROJECT_ACCOUNTACTIONS_H
#include <QtCore/QList>
class Transaction;
class Account;
class AccountActions {
private:

public:
    AccountActions() = default;
    ~AccountActions() = default;

    template<class T>
    static void makeTransaction(Account &, const T &);
    static QList<Transaction*> viewHistory(const Account &);
};

#endif //MOOP_ATM_PROJECT_ACCOUNTACTIONS_H
