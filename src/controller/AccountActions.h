//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ACCOUNTACTIONS_H
#define MOOP_ATM_PROJECT_ACCOUNTACTIONS_H
class Transaction;
class Account;
class AccountActions{
private:

public:
    AccountActions();
    ~AccountActions();
    static void makeTransaction(const Account&, const Transaction&);
    static void viewHistory(const Account&);

};

#endif //MOOP_ATM_PROJECT_ACCOUNTACTIONS_H
