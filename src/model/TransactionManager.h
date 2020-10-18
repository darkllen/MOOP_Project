//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
#define MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
class Account;
class AccountManaging;
class Transaction;
class TransactionManager{
private:

public:
    TransactionManager();
    ~TransactionManager();

    const Transaction& createTransaction(const Date&, const Account&, const Accoun&, int);
    const Transaction& createTransaction(const Date&, const Account&, const Accoun&, int, const Date&);
    const Transaction& createTransaction(const Date&, int, bool);
    const Transaction& createTransaction(const Date&, AccountManaging::ValueChanged, int, int);



};

#endif //MOOP_ATM_PROJECT_TRANSACTIONMANAGER_H
