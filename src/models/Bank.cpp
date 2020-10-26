//
// Created by Lemonderon on 20.10.2020.
//

#include "Bank.h"

#include "../exceptions/ATMException.h"
#include <mysqlx/xdevapi.h>
#include <string>
#include "DebitCard.h"

Bank::Bank(BANK_NUMBER_T id, std::string address, std::string name) :
        id_(id), address_(std::move(address)),
        name_(std::move(name)) {}

PIN_T Bank::getCardPIN(const CARD_NUMBER_T & cardNumberT) {
    try {
        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
        mysqlx::Session session(url);
        mysqlx::Schema db = session.getSchema("moop");
        mysqlx::Table myTable = db.getTable("DebitCard");
        mysqlx::RowResult myResult = myTable.select("PIN_")
                .where("cardNum_ like :cardNum_")
                .bind("cardNum_",cardNumberT).execute();
        mysqlx::Row row = myResult.fetchOne();
        return row.get(0).get<int>();
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
}

DebitCard Bank::getCard(const CARD_NUMBER_T& cardNumberT) {
    try {
        const char *url = ("mysqlx://root:qwerty@91.196.194.253:33060");
        mysqlx::Session session(url);
        mysqlx::Schema db = session.getSchema("moop");
        mysqlx::Table myTable = db.getTable("DebitCard");
        mysqlx::RowResult myResult = myTable.select("expireDate_","cvCode_","PIN_",	"isBlocked_")
                .where("cardNum_ like :cardNum_")
                .bind("cardNum_",cardNumberT).execute();
        for(size_t i = 0; i< myResult.count(); ++i){
            mysqlx::Row row = myResult.fetchOne();
            std::stringstream s;
            s << row[0];
            QStringList date(QString(QString::fromStdString(s.str())).split("-"));
            QDate expireDate_(date.at(0).toInt(),date.at(1).toInt(),date.at(2).toInt());
            CVV_T cvCode_(row[1].get<int>());
            CVV_T PIN_(row[2].get<int>());
            bool isBlocked_(row[3].get<bool>());
            return DebitCard(cardNumberT, QDateTime(expireDate_), cvCode_, PIN_, isBlocked_);
        }
    } catch (std::exception& e) {
        throw DBException(e.what());
    }
    throw DBException("no card is found with this card num");
}
