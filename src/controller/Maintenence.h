//
// Created by anna2 on 18.10.2020.
//

#ifndef MOOP_ATM_PROJECT_MAINTENENCE_H
#define MOOP_ATM_PROJECT_MAINTENENCE_H
class Hardware;
class Maintenence{
private:

public:
    Maintenence();
    ~Maintenence();

    static void addMoney(int);
    static void getMoney(int);
    static bool checkStatus(const Hardware&);
    static void changeStatus(Hardware&, bool);

};
#endif //MOOP_ATM_PROJECT_MAINTENENCE_H
