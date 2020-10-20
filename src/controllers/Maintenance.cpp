//
// Created by anna2 on 20.10.2020.
//

#include "Maintenance.h"
#include "../models/ATM.h
#include "../models/Hardware.h

Maintenance::Maintenance(){

};

Maintenance::~Maintenance();

static void Maintenance::addMoney(ATM& atm, int amount){
    int money = atm->getATMInfo->getAvailableCashAmount();
    atm->getATMInfo->setAvailableCashAmount(money + amount);

}

static void Maintenance::getMoney(ATM& atm, int amount){
    int money = atm->getATMInfo->getAvailableCashAmount();
    if(money>=amount)
        atm->getATMInfo->setAvailableCashAmount(money - amount);
    else
        {}//todo throw exception
}

static bool Maintenance::checkStatus(const Hardware & h){
    return h->getOperational;
}

static void changeStatus(Hardware & h, bool isOperational){
    h.setIsOperational(isOperational);
}

