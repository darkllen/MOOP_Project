//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_MAINTENANCE_H
#define MOOP_ATM_PROJECT_MAINTENANCE_H

class Hardware;

class Maintenance {
private:

public:
    Maintenance();
    ~Maintenance();

    static void addMoney(ATM&, int);
    static void getMoney(ATM&, int);
    static bool checkStatus(const Hardware &);
    static void changeStatus(Hardware &, bool);

};

#endif //MOOP_ATM_PROJECT_MAINTENANCE_H
