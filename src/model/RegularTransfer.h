//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_REGULARTRANSFER_H
#define MOOP_ATM_PROJECT_REGULARTRANSFER_H
class OneTimeTransfer;
class Account;
class RegularTransfer: public OneTimeTransfer{
private:
    Date& regularity_;

public:
    RegularTransfer(const Date&, const Account&, const Account&, int, const Date&);
    ~RegularTransfer();
};

#endif //MOOP_ATM_PROJECT_REGULARTRANSFER_H
