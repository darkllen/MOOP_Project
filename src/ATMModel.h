//
// Created by Lemonderon on 01.10.2020.
//

#ifndef MOOP_ATM_PROJECT_ATMMODEL_H
#define MOOP_ATM_PROJECT_ATMMODEL_H

#include <QMainWindow>
#include <QAbstractItemModel>

class ATMModel : QAbstractItemModel{
private:
    QMainWindow * m;

public:
    ATMModel(QMainWindow * m);
    ~ATMModel();
};


#endif //MOOP_ATM_PROJECT_ATMMODEL_H
